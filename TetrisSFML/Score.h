#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include "fileIO.h"
#include "GameConsts.h"
#include <fstream>

//Static class... needs to be initialized before use
//Holds score of actual game
class Score
{
private:
	static int points;
	static int counter;
	static int combo;
	static sf::Font font;
	static bool sortbysec(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b);
public:
	static void init();
	static sf::Text getScoreAsText();
	static int getScore();
	static void countercount();
	static void resetcounter();
	static int getCombo();
	static void setScore(int x);
	static void addToScore(int x);
	static void saveScore(std::string name);
	//Returns top 10 scores
	static std::string getTopScore();
};