#include "Window.h"

void AppWindow::renderArena(RectangleShape* renderList, int& list_length)
{
	for (int j = 0; j < arenaHeight + 2; j++) {
		for (int i = 0; i < arenaWidth + 2; i++) {
			RectangleShape x(Vector2f(SIZE, SIZE));
			x.setFillColor(arena.tempMatrix[j][i]);
			x.setPosition(Vector2f(i * SIZE, j * SIZE));
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

	window.display();
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
		renderArena(renderList, list_length);
		listenEvents();
		printArena(renderList, list_length);
	}
	delete[] renderList;
}
