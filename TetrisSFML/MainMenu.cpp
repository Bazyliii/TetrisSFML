#include "GameOver.h"
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include "Window.h"
#include "MainMenu.h"
#include "Colors.h"

sf::Font MainMenu::font;


MainMenu::MainMenu()
{
	font.loadFromFile("fonts\\Gameplay.ttf");
}
sf::Text MainMenu::T()
{
	sf::Text T;
	T.setFont(font);
	T.setString("T");
	T.setCharacterSize(72);
	T.setPosition(18, 200);
	T.setFillColor(usedColors::ZShapeLeftColor);
	return T;
}
sf::Text MainMenu::E()
{
	sf::Text E;
	E.setFont(font);
	E.setString("E");
	E.setCharacterSize(72);
	E.setPosition(18, 200);
	E.setFillColor(usedColors::ZShapeRightColor);
	return E;
}
sf::Text MainMenu::TT()
{
	sf::Text TT;
	TT.setFont(font);
	TT.setString("T");
	TT.setCharacterSize(72);
	TT.setPosition(18, 200);
	TT.setFillColor(usedColors::LShapeLeftColor);
	return TT;
}
sf::Text MainMenu::R()
{
	sf::Text R;
	R.setFont(font);
	R.setString("R");
	R.setCharacterSize(72);
	R.setPosition(18, 200);
	R.setFillColor(usedColors::LShapeRightColor);
	return R;
}
sf::Text MainMenu::I()
{
	sf::Text I;
	I.setFont(font);
	I.setString("I");
	I.setCharacterSize(72);
	I.setPosition(18, 200);
	I.setFillColor(usedColors::LShapeRightColor);
	return I;
}
sf::Text MainMenu::S()
{
	sf::Text S;
	S.setFont(font);
	S.setString("S");
	S.setCharacterSize(72);
	S.setPosition(18, 200);
	S.setFillColor(usedColors::LShapeRightColor);
	return S;
}
