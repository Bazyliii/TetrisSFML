#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
class Score {
public:
	int points;
	sf::Text text;
	sf::Font font;
	void showScore();
};