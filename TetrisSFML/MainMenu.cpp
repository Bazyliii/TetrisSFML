#include "GameOver.h"
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include "Window.h"
#include "MainMenu.h"
#include "addons/RichText.hpp"
#include "Colors.h"

sf::Font MainMenu::font;


MainMenu::MainMenu()
{
	font.loadFromFile("fonts\\Gameplay.ttf");
}
sfe::RichText MainMenu::getGameNameAsText()
{
	sfe::RichText text(font);
	text << usedColors::LShapeLeftColor << "T"
		<< usedColors::LShapeRightColor << "E"
		<< usedColors::LShapeRightColor << "T"
		<< usedColors::BoxColor << "R"
		<< usedColors::ZShapeLeftColor << "I"
		<< usedColors::ZShapeRightColor << "S";
	text.setCharacterSize(72);
	text.setPosition(18, 200);
	return text;
}
