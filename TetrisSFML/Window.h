#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include "TetrisArena.h"
#include "Tetrino.h"
#include "Colors.h"
#include "Score.h"
#include <time.h>

#define BOX_SIZE 25

using namespace sf;
using namespace std;

class AppWindow
{
private:
	Arena arena;
	RenderWindow window;
	iTetrino tetrino;
	Score score;
	int p;
	void renderArena(RectangleShape* renderList, int& list_length);
	void printArena(RectangleShape* renderList, int& list_length);
	void handleKeyPressed(Event event);
	void listenEvents();
	
public:
	AppWindow();
	void appLoop();
	void loseScreen();
};