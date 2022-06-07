
#include "MainMenu.h"

#define PRZESUNIECIE 30

#define FONT_SIZE 90

sf::Font MainMenu::font;


void MainMenu::init()
{
	font.loadFromFile("fonts\\Gameplay.ttf");
}

sf::Text MainMenu::T()
{
	sf::Text T;
	T.setFont(font);
	T.setString("T");
	T.setStyle(sf::Text::Bold);
	T.setCharacterSize(FONT_SIZE);
	T.setPosition(20, 30);
	T.setFillColor(usedColors::ZShapeLeftColor);
	return T;
}
sf::Text MainMenu::E()
{
	sf::Text E;
	E.setFont(font);
	E.setString("E");
	E.setStyle(sf::Text::Bold);
	E.setCharacterSize(FONT_SIZE);
	E.setPosition(20+ 85, 30);
	E.setFillColor(usedColors::ZShapeRightColor);
	return E;
}
sf::Text MainMenu::TT()
{
	sf::Text TT;
	TT.setFont(font);
	TT.setString("T");
	TT.setStyle(sf::Text::Bold);
	TT.setCharacterSize(FONT_SIZE);
	TT.setPosition(20+ 85 *2, 30);
	TT.setFillColor(usedColors::ZShapeLeftColor);
	return TT;
}
sf::Text MainMenu::R()
{
	sf::Text R;
	R.setFont(font);
	R.setString("R");
	R.setStyle(sf::Text::Bold);
	R.setCharacterSize(FONT_SIZE);
	R.setPosition(20+ 85 *3, 30);
	R.setFillColor(usedColors::LShapeLeftColor);
	return R;
}
sf::Text MainMenu::I()
{
	sf::Text I;
	I.setFont(font);
	I.setString("I");
	I.setCharacterSize(FONT_SIZE);
	I.setPosition(20+ 87 *4, 30);
	I.setFillColor(usedColors::IShapeColor);
	return I;
}
sf::Text MainMenu::S()
{
	sf::Text S;
	S.setFont(font);
	S.setString("S");
	S.setCharacterSize(FONT_SIZE);
	S.setPosition( -26 + 88 *5, 30);
	S.setFillColor(usedColors::BoxColor);
	return S;
}

sf::Text MainMenu::PlayButton(sf::Color color) {
	sf::Text playbutton;
	playbutton.setFont(font);
	playbutton.setString("PLAY");
	playbutton.setCharacterSize(66);
	playbutton.setPosition((500 / 2) - (playbutton.getGlobalBounds().width / 2), 180+ PRZESUNIECIE);
	playbutton.setFillColor(color);
	return playbutton;
}

sf::Text MainMenu::HighScoreButton(sf::Color color) {
	sf::Text highscore;
	highscore.setFont(font);
	highscore.setString("HIGHSCORES");
	highscore.setCharacterSize(66);
	highscore.setPosition((500/2) - (highscore.getGlobalBounds().width/2), 275+ PRZESUNIECIE);
	highscore.setFillColor(color);
	return highscore;
}

sf::Text MainMenu::QuitButton(sf::Color color) {
	sf::Text quit;
	quit.setFont(font);
	quit.setString("QUIT");
	quit.setCharacterSize(66);
	quit.setPosition((500 / 2) - (quit.getGlobalBounds().width / 2), 370+PRZESUNIECIE);
	quit.setFillColor(color);
	return quit;
}