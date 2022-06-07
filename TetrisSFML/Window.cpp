#include "Window.h"

#define TETRINO_SPEED 620
#define WINDOW_FPS 144

GameState AppWindow::gameState = GameState::MainMenu;

void AppWindow::initBeforeGame()
{
	nickname = "";
	Score::init();
	GameOver::init();
	arena = Arena();
	arena.renderRandomPiece(tetrino);
}

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
	case Keyboard::Key::Backspace:
		if (!arena.getGameState() && nickname.length() > 0) 
		{
			nickname.pop_back();
		}
		break;
	case Keyboard::Key::Enter:
		if (getGameState()==GameState::GameLost)
		{
			Score::saveScore(nickname);
			setGameState(GameState::MainMenu);
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
		case Event::TextEntered:
			if (!arena.getGameState() && event.text.unicode < 126 && event.text.unicode >= 33 && event.text.unicode != 96)
			{
				if (nickname.length() < 8) {
					nickname += static_cast<char>(event.text.unicode);
				}
			}
			break;
		default:
			break;
		}
	}
}

void AppWindow::gameLoop()
{
	RectangleShape* renderList = new RectangleShape[(arenaWidth + 2) * (arenaHeight + 2)];
	sf::Clock clock;
	clock.restart();
	while (window.isOpen())
	{
		int list_length = 0;
		if (clock.getElapsedTime().asMilliseconds() >= TETRINO_SPEED)
		{
			tetrino.moveDown();
			arena.printBlock(tetrino);
			clock.restart();
		}
		renderArena(renderList, list_length);
		listenEvents();
		if (tetrino.IsStatic() && !arena.renderRandomPiece(tetrino)) { break; }
		printArena(renderList, list_length);
	}
	delete[] renderList;
}


AppWindow::AppWindow() :
	window(VideoMode(500, 550), "Tetris", Style::Titlebar | Style::Close)
{
	MainMenu::init();
	initBeforeGame();
	window.setFramerateLimit(WINDOW_FPS);
}

bool AppWindow::appLoop()
{
	switch (gameState)
	{
	case GameState::MainMenu:
		initBeforeGame();
		setGameState(GameState::Game); //Tu main meneu
		break;
	case GameState::Game:
		gameLoop();
		break;
	case GameState::GameLost:
		listenEvents();
		window.clear();
		window.draw(GameOver::getGameOverAsText());
		window.draw(GameOver::getUserInputAsText(nickname));
		window.draw(GameOver::getGameOverScoreAsText());
		window.display();
		break;
	case GameState::ScorePeek:
		break;
	}
	return window.isOpen();
}

GameState AppWindow::getGameState()
{
	return gameState;
}

void AppWindow::setGameState(GameState _gameState)
{
	gameState = _gameState;
}
