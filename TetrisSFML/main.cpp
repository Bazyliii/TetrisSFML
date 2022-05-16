#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <iostream>
#include "arena.h"
#include "box.h"

using namespace sf;
using namespace std;



int main(void) {
	RenderWindow window(VideoMode(1920, 1080), "TETRIS", Style::Fullscreen);
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) {
				window.close();
			}
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				cout << "Lewo";
			}
			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				cout << "Prawo";
			}
			if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				cout << "Dol";
			}
		}
		window.clear(Color::Black);
		window.display();
	}
}