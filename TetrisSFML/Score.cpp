#include "Score.h"
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include "Window.h"

int Score::points = 0;
sf::Font Score::font;

Score::Score()
{
	font.loadFromFile("fonts\\Gameplay.ttf");
}

sf::Text Score::getScoreAsText()
{
	sf::Text text;
	text.setFont(font);
	text.setString(to_string(points));
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
