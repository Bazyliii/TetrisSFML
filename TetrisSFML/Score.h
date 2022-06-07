#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
class Score 
{
private:
	static int points;
	static sf::Font font;
public:
	static void init();
	static sf::Text getScoreAsText();
	static int getScore();
	static void setScore(int x);
	static void addToScore(int x);
	static void saveScore(int points);
};