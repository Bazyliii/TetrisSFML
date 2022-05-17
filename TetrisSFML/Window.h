#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include "TetrisArena.h"
#include "Tetrino.h"
using namespace sf;

class AppWindow 
{
private:
    Arena arena;
    Window window;
public:
	AppWindow() :
        window(VideoMode(800, 600), "Tetris")
    {
        arena = Arena();
        window.setFramerateLimit(60);
        while (window.isOpen())
        {
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::Closed)
                    window.close();
            }
            window.setActive();
            window.display();
        }
	}
};