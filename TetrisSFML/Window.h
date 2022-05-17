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

public:
	AppWindow() :
		window(VideoMode(800, 600), "Tetris")
	{
		arena = Arena();
		arena.printBlock(LShapeRight());
		window.setFramerateLimit(60);
		while (window.isOpen())
		{
			RectangleShape renderList[(arenaWidth+2)*(arenaHeight+2)];
			int list_length = 0;
			for (int j = 0; j < arenaHeight + 2;j++) {
				for (int i = 0;i < arenaWidth + 2;i++) {
					if (usedColors::backgroundColor==arena.tempMatrix[j][i]) {
						continue;
					}
					RectangleShape x(Vector2f(SIZE, SIZE));
					x.setFillColor(arena.tempMatrix[j][i]);
					x.setPosition(Vector2f(i * SIZE, j * SIZE));
					renderList[list_length++] = x;
				}
			}

			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
			}
			window.setActive();
			window.clear();
			//rysowanie
			for (int i = 0;i <list_length;i++) {
				window.draw(renderList[i]);
			}

			window.display();
		}
	}
};