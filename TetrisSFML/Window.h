#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include "TetrisArena.h"
#include "Tetrino.h"
#include "Colors.h"
#include <time.h>

#define SIZE 25

using namespace sf;
using namespace std;

class AppWindow
{
private:
	Arena arena;
	RenderWindow window;
	iTetrino tetrino;
	int piece;
	int p;
	void renderArena(RectangleShape* renderList, int& list_length);

	void printArena(RectangleShape* renderList, int& list_length);

	void handleKeyPressed(Event event)
	{
		switch (event.key.code)
		{
			//ROTATION
		case Keyboard::Key::Q:
			tetrino.rotateCCW();
			arena.printBlock(tetrino);
			break;
		case Keyboard::Key::E:
			tetrino.rotateCW();
			arena.printBlock(tetrino);
			break;
		case Keyboard::Key::W:
			tetrino.rotateCW();
			arena.printBlock(tetrino);
			break;

			//MOVEMENT
		case Keyboard::Key::A:
			tetrino.moveLeft();
			arena.printBlock(tetrino);
			break;
		case Keyboard::Key::D:
			tetrino.moveRight();
			arena.printBlock(tetrino);
			break;
		case Keyboard::Key::S:
			tetrino.moveDown();
			arena.printBlock(tetrino);
			break;
			//SOMETHING ELSE
		case Keyboard::Key::Space:
			randomPiece();
			break;
		default:
			break;
		}
	}

	void listenEvents();

	
public:
	void randomPiece() {
		srand(time(NULL));
		piece = rand() % 6;
		switch (piece) {
		case 0:
			tetrino = Box();
			break;
		case 1:
			tetrino = TShape();
			break;
		case 2:
			tetrino = IShape();
			break;
		case 3:
			tetrino = LShapeLeft();
			break;
		case 4:
			tetrino = LShapeRight();
			break;
		case 5:
			tetrino = ZShapeLeft();
			break;
		case 6:
			tetrino = ZShapeRight();
			break;
		}
		arena.printBlock(tetrino);
	};

	AppWindow() :
		window(VideoMode(800, 600), "Tetris", Style::Titlebar | Style::Close)
	{
		arena = Arena();
		randomPiece();
		window.setFramerateLimit(144);
	}
	void appLoop();
};