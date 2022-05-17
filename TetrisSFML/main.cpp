#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <chrono>
#include "Game.h"

using namespace sf;
using namespace std;



int main(void) {
	RenderWindow window(VideoMode(800, 900), "Tetris");

	auto tp{ chrono::system_clock::now() };
	static constexpr float FRAME_RATE{ 60.0f };
	static GameState* state = &GameState::menu;

	Game game(state);

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}
		float dt;
		{
			auto new_tp{ chrono::system_clock::now() };
			dt = chrono::duration<float>(new_tp - tp).count();
			tp = new_tp;
		}
		game.handleInput();
		game.update(dt * FRAME_RATE);
		window.clear();
		window.draw(game);
		window.display();
	}
}