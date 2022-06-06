#include "GameOver.h"
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include "Window.h"

sf::Font GameOver::font;

GameOver::GameOver()
{
	font.loadFromFile("fonts\\Gameplay.ttf");
}

sf::Text GameOver::getGameOverAsText()
{
	sf::Text text;
	text.setFont(font);
	text.setString("GAME OVER");
	text.setCharacterSize(72);
	text.setPosition(18, 220);
	text.setFillColor(usedColors::TextColor);
	return text;
}
