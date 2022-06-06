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
		tetrino.moveDown();
		while (!arena.printBlock(tetrino)){ tetrino.moveDown(); }
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

void AppWindow::appLoop() {
	RectangleShape* renderList = new RectangleShape[(arenaWidth + 2) * (arenaHeight + 2)];
	while (window.isOpen())
	{
		int list_length = 0;
		p += 1;
		if (p % 70 == 0) {
			tetrino.moveDown();
			if (!(arena.printBlock(tetrino))) 
			window.close();
			p = 0;
		}
		renderArena(renderList, list_length);
		listenEvents();
		printArena(renderList, list_length);
	}
	delete[] renderList;
}


void AppWindow::randomPiece() {
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
}
