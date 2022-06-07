#include "Score.h"
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include "Window.h"
#include <fstream>

int Score::points = 0;
sf::Font Score::font;

void Score::init()
{
	font.loadFromFile("fonts\\Gameplay.ttf");
}

sf::Text Score::getScoreAsText()
{
	sf::Text text;
	text.setFont(font);
	text.setString("Score: \n" + to_string(points));
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

void Score::saveScore(int points)
{
	fstream file;
	file.open("score.txt", ios::out);
	file << points << endl;
	file.close();

}