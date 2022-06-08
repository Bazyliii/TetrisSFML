#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include "GameConsts.h"

//Static class... needs to be initialized before use
class MainMenu{
private:
	//Font used for text
	static sf::Font font;
public:
	//Initialize class in place of constructor
	static void init();

	//Get texboxes to render on screen
	static sf::Text MainMenuLogo(std::string content, int x, sf::Color color);
	static sf::Text MainMenuButton(std::string content, int y, sf::Color color);
};