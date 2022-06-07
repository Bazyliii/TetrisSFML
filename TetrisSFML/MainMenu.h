#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include "MainMenu.h"
#include "Colors.h"

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
	static sf::Text PlayButton(sf::Color color);
	static sf::Text HighScoreButton(sf::Color color);
	static sf::Text QuitButton(sf::Color color);
};