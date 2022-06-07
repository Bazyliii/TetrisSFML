#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include "MainMenu.h"
#include "addons/RichText.hpp"

static class MainMenu{
private:
	static sf::Font font;
public:
	MainMenu();
	static sfe::RichText getGameNameAsText();
};