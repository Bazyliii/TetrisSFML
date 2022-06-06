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
	text.setString("Chdsfsdfsdfsdfsdfuj");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
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
