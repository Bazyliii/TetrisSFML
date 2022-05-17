#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include "TetrisArena.h"
#include "Tetrino.h"
#include "Colors.h"
#define SIZE 25

using namespace sf;

class AppWindow
{
private:
	Arena arena;
	RenderWindow window;
	iTetrino tetrino;
	void renderArena(RectangleShape* renderList, int& list_length);

	void printArena(RectangleShape* renderList, int& list_length);

	void handleKeyPressed(Event event)
	{
		switch (event.key.code)
		{
		case Keyboard::Key::A:
			tetrino.rotate();
			arena.printBlock(tetrino);
			break;
		case Keyboard::Key::D:
			tetrino.rotate();
			tetrino.rotate();
			tetrino.rotate();
			arena.printBlock(tetrino);
			break;
		case Keyboard::Key::Space:
			arena.printBlock(tetrino);
			break;
		default:
			break;
		}
	}

	void listenEvents();


public:
	AppWindow() :
		window(VideoMode(800, 600), "Tetris", Style::Titlebar | Style::Close)
	{
		arena = Arena();
		tetrino = TShape();
		window.setFramerateLimit(60);
	}
	void appLoop();
};