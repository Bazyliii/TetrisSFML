#include "Window.h"

void AppWindow::renderArena(RectangleShape* renderList, int& list_length)
{
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
		while (!tetrino.IsStatic())
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
	window.setFramerateLimit(144);
}

void AppWindow::appLoop() {
	RectangleShape* renderList = new RectangleShape[(arenaWidth + 2) * (arenaHeight + 2)];
	while (window.isOpen())
	{
		int list_length = 0;
		p += 1;
		if (p % 70 == 0) {
			tetrino.moveDown();
			arena.printBlock(tetrino);
			p = 0;
		}
		if (tetrino.IsStatic() && !arena.renderRandomPiece(tetrino)) window.close();
		renderArena(renderList, list_length);
		listenEvents();
		printArena(renderList, list_length);
	}
	delete[] renderList;
}