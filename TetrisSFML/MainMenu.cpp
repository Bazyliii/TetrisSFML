#include "MainMenu.h"

sf::Font MainMenu::font;


void MainMenu::init()
{
	font.loadFromFile("fonts\\Gameplay.ttf");
}

sf::Text MainMenu::MainMenuLogo(std::string content, int x, sf::Color color)
{
	sf::Text letter;
	letter.setFont(font);
	letter.setString(content);
	letter.setStyle(sf::Text::Bold);
	letter.setCharacterSize(90);
	letter.setPosition((float)x, 30);
	letter.setFillColor(color);
	return letter;
}

sf::Text MainMenu::MainMenuButton(std::string content, int y, sf::Color color)
{
	sf::Text button;
	button.setFont(font);
	button.setString(content);
	button.setCharacterSize(66);
	button.setPosition((500 / 2) - (button.getGlobalBounds().width / 2),(float)y);
	button.setFillColor(color);
	return button;
}
