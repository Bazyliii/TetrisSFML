#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include "MainMenu.h"

class MainMenu{
private:
	static sf::Font font;
public:
	static void init();
	static sf::Text T();
	static sf::Text E();
	static sf::Text TT();
	static sf::Text R();
	static sf::Text I();
	static sf::Text S();
	static sf::Text PlayButton();
	static sf::Text HighScoreButton();
	static sf::Text QuitButton();
};