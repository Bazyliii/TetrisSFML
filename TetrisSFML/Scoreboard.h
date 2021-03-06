#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include "Score.h"
#include "GameConsts.h"

class Scoreboard
{
private:
	static sf::Font font;
public:
	static void init();
	static sf::Text getScoreboardAsText();
};