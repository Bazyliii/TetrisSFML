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
	static sf::Text T();
	static sf::Text E();
	static sf::Text TT();
	static sf::Text R();
	static sf::Text I();
	static sf::Text S();
	static sf::Text PlayButton(sf::Color color);
	static sf::Text HighScoreButton(sf::Color color);
	static sf::Text QuitButton(sf::Color color);
};