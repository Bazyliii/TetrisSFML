#include "GameOver.h"
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include "Window.h"
#include "Score.h"

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
	text.setPosition(18, 200);
	text.setFillColor(usedColors::TextColor);
	return text;
}

sf::Text GameOver::getGameOverScoreAsText() {
	sf::Text score;
	score.setFont(font);
	score.setString("Score: " + to_string(Score::getScore()));
	score.setCharacterSize(42);
	score.setPosition(18, 290);
	score.setFillColor(usedColors::TextColor);
	return score;
}

sf::Text GameOver::getUserInputAsText(std::string nickname) {
	sf::Text nick;
	nick.setFont(font);
	nick.setString("Nickname: \n" +nickname);
	nick.setCharacterSize(42);
	nick.setPosition(18, 434);
	nick.setFillColor(usedColors::TextColor);
	return nick;
}