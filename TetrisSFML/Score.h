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
	static bool sortbysec(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b);
public:
	static void init();
	static sf::Text getScoreAsText();
	static int getScore();
	static void setScore(int x);
	static void addToScore(int x);
	static void saveScore(std::string name);
	//Returns top 10 scores
	static std::string getTopScore();
};