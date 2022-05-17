#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>

using namespace sf;
using namespace std;



int main(void) {
    Window window(VideoMode(800, 600), "Tetris");
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