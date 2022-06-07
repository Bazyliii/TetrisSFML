#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include "fileIO.h"
#include "Colors.h"
#include <fstream>

class Score
{
private:
	static int points;
	static sf::Font font;
	static bool sortbysec(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b)
	{
		return (b.second < a.second);
	}
public:
	static void init();
	static sf::Text getScoreAsText();
	static int getScore();
	static void setScore(int x);
	static void addToScore(int x);
	static void saveScore(std::string name)
	{
		if (name.length() < 1) return;
		FileIO::appendToFile(name + ":" + std::to_string(getScore()), "score");
	}
	//Returns top 10 scores
	static std::string getTopScore()
	{
		std::string score = FileIO::readFromFile("score");

		//convert given string to vector of pairs of name;score
		std::vector<std::pair<std::string, int>> scorePairs;
		{
			bool isValue = false;
			std::string strPair = "";
			std::string intPair = "";
			std::pair<std::string, int> tempPair = std::pair<std::string, int>();
			for (auto& ch : score)
			{
				switch (ch)
				{
				case '\n':
					tempPair = std::pair<std::string, int>();
					tempPair.first = strPair;
					tempPair.second = stoi(intPair);
					scorePairs.push_back(tempPair);
					strPair = "";
					isValue = false;
					break;
				case ':':
					intPair = "0";
					isValue = true;
					break;
				default:
					switch (isValue)
					{
					case true:
						intPair += ch;
						break;
					case false:
						strPair += ch;
						break;
					}
					break;
				}
			}
		}

		std::sort(scorePairs.begin(), scorePairs.end(), sortbysec);

		std::string str = "";
		for (int i = 0; i < 10 && i < scorePairs.size(); i++)
		{
			str.append(scorePairs[i].first);
			str.append(" : ");
			str.append(std::to_string(scorePairs[i].second));
			str += '\n';
		}

		return str;
	}
};