#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include "Score.h"
#include "GameConsts.h"

//Static class... needs to be initialized before use
class GameOver
{
private:
	//Font used for text
	static sf::Font font;
public:
	//Initialize class in place of constructor
	static void init();
	//Get texboxes to render on screen
	static sf::Text getGameOverAsText();
	static sf::Text getGameOverScoreAsText();
	static sf::Text getUserInputAsText(std::string nickname);
};