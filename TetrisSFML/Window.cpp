#include "Window.h"

#define TETRINO_SPEED 220
#define WINDOW_FPS 144

void AppWindow::renderArena(RectangleShape* renderList, int& list_length)
{
	if (!arena.getGameState()) return;
	for (int j = 0; j < arenaHeight + 2; j++) {
		for (int i = 0; i < arenaWidth + 2; i++) {
			RectangleShape x(Vector2f(BOX_SIZE, BOX_SIZE));
			x.setFillColor(arena.tempMatrix[j][i]);
			x.setPosition(Vector2f(i * BOX_SIZE, j * BOX_SIZE));
			renderList[list_length++] = x;
		}
	}
}

void AppWindow::printArena(RectangleShape* renderList, int& list_length)
{
	if (!arena.getGameState()) return;
	window.clear();
	//rysowanie
	for (int i = 0; i < list_length; i++) {
		window.draw(renderList[i]);
	}
	window.draw(Score::getScoreAsText());
	window.display();
}

void AppWindow::handleKeyPressed(Event event) {
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
	case Keyboard::Key::Space:
		while (!tetrino.IsStatic() && arena.getGameState())
		{
			tetrino.moveDown();
			arena.printBlock(tetrino);
		}
		break;
	default:
		break;
	}
}

void AppWindow::listenEvents()
{
	Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case Event::Closed:
			window.close();
			break;
		case Event::KeyPressed:
			handleKeyPressed(event);

			if (!arena.getGameState()) {
				if (event.type == Event::TextEntered) {
					if (event.text.unicode < 128) {
						nickname += static_cast<char>(event.text.unicode);				
					}
				}
			}




			break;
		default:
			break;
		}
	}
}

AppWindow::AppWindow() :
	window(VideoMode(500, 550), "Tetris", Style::Titlebar | Style::Close)
{
	p = 0;
	arena = Arena();
	arena.renderRandomPiece(tetrino);
	window.setFramerateLimit(WINDOW_FPS);
}

void AppWindow::appLoop() {
	RectangleShape* renderList = new RectangleShape[(arenaWidth + 2) * (arenaHeight + 2)];

	sf::Clock clock;
	clock.restart();
	while (window.isOpen())
	{
		int list_length = 0;
		if (clock.getElapsedTime().asMilliseconds() >= TETRINO_SPEED) {
			tetrino.moveDown();
			arena.printBlock(tetrino);
			clock.restart();
		}
		if (!arena.getGameState() || tetrino.IsStatic() && !arena.renderRandomPiece(tetrino))
		{
			//When game is lost:
		}
		renderArena(renderList, list_length);
		listenEvents();
		if (!arena.getGameState()) {
			window.clear();
			window.draw(GameOver::getGameOverAsText());
			window.draw(GameOver::getUserInputAsText(nickname));
			window.draw(GameOver::getGameOverScoreAsText());
			window.display();
		}
		else {
			printArena(renderList, list_length);
		}
	}
	delete[] renderList;
}
