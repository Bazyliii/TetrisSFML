#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>

#include "TetrisArena.h"
#include "Tetrino.h"
#include "GameConsts.h"
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
#define NEXT_TETRINO_OFFSET_X 350
#define NEXT_TETRINO_OFFSET_Y 100

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
	iTetrino nextTetrino;
	//Stores player's nickname
	string nickname;
	//Clock data
	sf::Clock clock;


	///Function declarations

	//Perform init of all used comp so that we start a new game
	void initBeforeGame();
	//Add arena tiles to render list
	void renderArena(RectangleShape* renderList, int& list_length);
	//Add next tetrino tiles to render list
	void renderNextTetrino(RectangleShape* renderList, int& list_length);
	//Print (render) given object list on window's screen
	void printArena(RectangleShape* renderList, int& list_length);
	//Self explanatory
	void handleKeyPressed(Event event);
	//Handles all reported events since last command execution
	void listenEvents();
	//Main game loop (when GameState is game)
	void gameLoop();
	//Calculates tetrino speed based on function from geogebra that we've worked on for 15min
	int calcTetrinoSpeed();
	//Actual delay
	int tetrinospeed;

public:
	AppWindow();
	//Main AppWindow loop
	bool appLoop();
	//Returns state of the game of enum type GameState
	static GameState getGameState();
	//Sets state of the game to any of GameState enum type
	static void setGameState(GameState _gameState);
};