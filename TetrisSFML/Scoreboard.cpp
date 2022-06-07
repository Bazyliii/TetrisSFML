#include "Scoreboard.h"

sf::Font Scoreboard::font;


void Scoreboard::init() {
	font.loadFromFile("fonts\\Gameplay.ttf");
}

sf::Text Scoreboard::getScoreboardAsText()
{
	sf::Text scoreboard;
	scoreboard.setFont(font);
	scoreboard.setString("Best scores: \n chuj 20000");
	scoreboard.setCharacterSize(30);
	scoreboard.setPosition((500 / 2) - (scoreboard.getGlobalBounds().width / 2), 20);
	scoreboard.setFillColor(usedColors::TextColor);
	return scoreboard;
}