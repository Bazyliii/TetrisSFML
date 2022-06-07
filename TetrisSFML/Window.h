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
#include "Scoreboard.h"
#include "Sounds.h"

#define BOX_SIZE 25
#define WINDOW_FPS 144
#define TETRINO_MAX_SPEED 140

using namespace sf;
using namespace std;

class AppWindow
{
private:
	///Variables declaration

	//Arena instance
	Arena arena;
	//Thats a GameState enum
	static GameState gameState;
	//SFML window declaration
	RenderWindow window;
	//Interface that's gonna have different tetrinos assigned
	iTetrino tetrino;
	//Stores player's nickname
	string nickname;


	///Function declarations

	//Perform init of all used comp so that we start a new game
	void initBeforeGame();
	//Prepare object list to be rendered
	void renderArena(RectangleShape* renderList, int& list_length);
	//Print (render) given object list on window's screen
	void printArena(RectangleShape* renderList, int& list_length);
	//Self explanatory
	void handleKeyPressed(Event event);
	//Handles all reported events since last command execution
	void listenEvents();
	//Main game loop (when GameState is game)
	void gameLoop();
	//Calculates tetrino speed based on function from geogebra that we worked for 15min
	int calcTetrinoSpeed()
	{
		double a = (-1.0 / 2137.0) * (6.0 / 9420.0) * (6.0 / 9420.0) * (double)Score::getScore() * (double)Score::getScore() + 6.0;
		return a > 1 ? (int)(TETRINO_MAX_SPEED * a) : TETRINO_MAX_SPEED;
	}

	int tetrinospeed;
	sf::Color playcolor;
	sf::Color scorecolor;
	sf::Color quitcolor;

public:
	AppWindow();
	//Main AppWindow loop
	bool appLoop();
	//Returns state of the game of enum type GameState
	static GameState getGameState();
	//Sets state of the game to any of GameState enum type
	static void setGameState(GameState _gameState);
};