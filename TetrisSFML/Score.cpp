#include "Score.h"


int Score::points = 0;
int Score::counter = 0;
int Score::combo = 0;
sf::Font Score::font;

bool Score::sortbysec(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b)
{
	return (b.second < a.second);
}

void Score::init()
{
	font.loadFromFile("fonts\\Gameplay.ttf");
	points = 0;
}

sf::Text Score::getScoreAsText()
{
	sf::Text text;
	text.setFont(font);
	text.setString("Score: \n" + std::to_string(points));
	text.setCharacterSize(24);
	text.setPosition(320, 20);
	text.setFillColor(usedColors::TextColor);
	return text;
}

int Score::getScore()
{
	return points;
}

void Score::setScore(int x)
{
	points = x;
}

void Score::addToScore(int x)
{
	points += x;
}

void Score::saveScore(std::string name)
{
	if (name.length() < 1) return;
	FileIO::appendToFile(name + ":" + std::to_string(getScore()), "score");
}

//Returns top 10 scores

std::string Score::getTopScore()
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
void Score::countercount() {
	counter++;
}

int Score::getCombo() {
	switch (counter)
	{
	case 1:
		combo = 1;
		break;
	case 2:
		combo = 3;
		break;
	case 3:
		combo = 5;
		break;
	case 4:
		combo = 8;
		break;
	default:
		combo = 0;
		break;
	}

	return combo;
}

void Score::resetcounter() {
	counter=0;
}