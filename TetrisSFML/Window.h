#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include "TetrisArena.h"
#include "Tetrino.h"
#include "Colors.h"
#include "Score.h"
#include "GameOver.h"
#include <time.h>
#include "MainMenu.h"
#include "GameState.h"

#define BOX_SIZE 25

using namespace sf;
using namespace std;

class AppWindow
{
private:
	Arena arena;
	static GameState gameState;
	RenderWindow window;
	iTetrino tetrino;
	Score score;
	GameOver gameover;
	string nickname;
	void renderArena(RectangleShape* renderList, int& list_length);
	void printArena(RectangleShape* renderList, int& list_length);
	void handleKeyPressed(Event event);
	void listenEvents();
	
public:
	AppWindow();
	void appLoop();
	static GameState getGameState();
	static void setGameState(GameState _gameState);
};