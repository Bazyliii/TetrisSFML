#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
static class GameOver {
private:
	static sf::Font font;
public:
	GameOver();
	static sf::Text getGameOverAsText();
};