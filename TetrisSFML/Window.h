#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include "TetrisArena.h"
#include "Tetrino.h"
#define SIZE 40

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
		arena.printBlock(Box());
		window.setFramerateLimit(60);
		while (window.isOpen())
		{
			RectangleShape chujnia[arenaWidth+2];
			int chujnia_length = 0;
			for (int j = 0; j < arenaHeight + 2;j++) {
				for (int i = 0;i < arenaWidth + 2;i++) {
					if () {
					
					}
					RectangleShape chuj(Vector2f(SIZE, SIZE));

					chuj.setPosition(Vector2f(i * SIZE, j * SIZE));
					chujnia[chujnia_length++] = chuj;
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
			for (int i = 0;i <chujnia_length;i++) {
				window.draw(chujnia[i]);
			}

			window.display();
		}
	}
};