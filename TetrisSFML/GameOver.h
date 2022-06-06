#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include "Score.h"


static class GameOver: public Score{
private:
	static sf::Font font;
public:
	GameOver();
	static sf::Text getGameOverAsText();
	static sf::Text getGameOverScoreAsText();
};