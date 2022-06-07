#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include "Score.h"

class GameOver
{
private:
	static sf::Font font;
public:
	static void init();
	static sf::Text getGameOverAsText();
	static sf::Text getGameOverScoreAsText();
	static sf::Text getUserInputAsText(std::string nickname);
};