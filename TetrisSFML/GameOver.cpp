#include "GameOver.h"

sf::Font GameOver::font;


void GameOver::init() {
	font.loadFromFile("fonts\\Gameplay.ttf");
}

sf::Text GameOver::getGameOverAsText()
{
	sf::Text text;
	text.setFont(font);
	text.setString("GAME OVER");
	text.setCharacterSize(72);
	text.setPosition((500 / 2) - text.getGlobalBounds().width / 2, 40);
	text.setFillColor(usedColors::TextColor);
	return text;
}

sf::Text GameOver::getGameOverScoreAsText() {
	sf::Text score;
	score.setFont(font);
	score.setString("Score:\n" + std::to_string(Score::getScore()));
	score.setCharacterSize(42);
	score.setPosition((500 / 2) - score.getGlobalBounds().width / 2, 200);
	score.setFillColor(usedColors::BoxColor);
	return score;
}

sf::Text GameOver::getUserInputAsText(std::string nickname) {
	sf::Text nick;
	nick.setFont(font);
	nick.setString("Nickname: \n" +nickname);
	nick.setCharacterSize(42);
	nick.setPosition((500 / 2) - nick.getGlobalBounds().width / 2, 360);
	nick.setFillColor(usedColors::ZShapeLeftColor);
	return nick;
}