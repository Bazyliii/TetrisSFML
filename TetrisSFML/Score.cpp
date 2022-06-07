#include "Score.h"


int Score::points = 0;
sf::Font Score::font;

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
