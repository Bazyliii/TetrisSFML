#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include "MainMenu.h"

static class MainMenu{
private:
	static sf::Font font;
public:
	MainMenu();
	static sf::Text T();
	static sf::Text E();
	static sf::Text TT();
	static sf::Text R();
	static sf::Text I();
	static sf::Text S();
};