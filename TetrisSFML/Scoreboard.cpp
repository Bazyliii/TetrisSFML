#include "Scoreboard.h"

sf::Font Scoreboard::font;


void Scoreboard::init() {
	font.loadFromFile("fonts\\Gameplay.ttf");
}

sf::Text Scoreboard::getScoreboardAsText()
{
	sf::Text text;
	text.setFont(font);
	text.setString("Gowno");
	text.setCharacterSize(90);
	text.setPosition((500 / 2) - (text.getGlobalBounds().width / 2), 180);
	text.setFillColor(usedColors::TextColor);
	return text;
}