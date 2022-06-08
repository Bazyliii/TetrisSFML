#include "Window.h"



GameState AppWindow::gameState = GameState::MainMenu;

void AppWindow::initBeforeGame()
{
	nickname = "";
	tetrinospeed = calcTetrinoSpeed();
	Score::init();
	GameOver::init();
	Scoreboard::init();
	arena = Arena();
	arena.renderRandomPiece(tetrino);
}

void AppWindow::renderArena(RectangleShape* renderList, int& list_length)
{
	if (!arena.getGameState()) return;
	for (int j = 0; j < arenaHeight + 2; j++) {
		for (int i = 0; i < arenaWidth + 2; i++) {
			RectangleShape x(Vector2f((float)BOX_SIZE, (float)BOX_SIZE));
			x.setFillColor(arena.tempMatrix[j][i]);
			x.setPosition(Vector2f((float)(i * BOX_SIZE), (float)(j * BOX_SIZE)));
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
		if (getGameState() == GameState::MainMenu) {
			if (usedColors::quitcolor == usedColors::LShapeLeftColor) {
				usedColors::scorecolor = usedColors::LShapeLeftColor;
				usedColors::quitcolor = usedColors::BoxColor;
			}
			else if (usedColors::scorecolor == usedColors::LShapeLeftColor) {
				usedColors::playcolor = usedColors::LShapeLeftColor;
				usedColors::scorecolor = usedColors::BoxColor;
			}
		}
		else {
			tetrino.rotateCW();
			arena.printBlock(tetrino);
		}
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
		if (getGameState() == GameState::MainMenu) {
			if (usedColors::playcolor == usedColors::LShapeLeftColor) {
				usedColors::scorecolor = usedColors::LShapeLeftColor;
				usedColors::playcolor = usedColors::BoxColor;
			}
			else if (usedColors::scorecolor == usedColors::LShapeLeftColor) {
				usedColors::quitcolor = usedColors::LShapeLeftColor;
				usedColors::scorecolor = usedColors::BoxColor;
			}
		}
		else {
			tetrino.moveDown();
			arena.printBlock(tetrino);
		}
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
		if (getGameState() == GameState::MainMenu) {
			if (usedColors::playcolor == usedColors::LShapeLeftColor) {
				initBeforeGame();
				setGameState(GameState::Game);
			}
			if (usedColors::scorecolor == usedColors::LShapeLeftColor) {
				setGameState(GameState::ScorePeek);
			}
			if (usedColors::quitcolor == usedColors::LShapeLeftColor) {
				exit(2);
			}
		}
		if (getGameState() == GameState::GameLost && nickname.length()>0)
		{
			Score::saveScore(nickname);
			setGameState(GameState::MainMenu);
		}
		break;
	case Keyboard::Key::Escape:
		if (getGameState() == GameState::MainMenu) {
			exit(69);
		}
		if (getGameState() == GameState::ScorePeek){
			setGameState(GameState::MainMenu);
		}
		if (getGameState() == GameState::Game) {
			setGameState(GameState::GameLost);
		}
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
		if (clock.getElapsedTime().asMilliseconds() >= tetrinospeed)
		{
			tetrino.moveDown();
			arena.printBlock(tetrino);
			tetrinospeed = calcTetrinoSpeed();
			clock.restart();
		}
		renderArena(renderList, list_length);
		listenEvents();
		if (getGameState() == GameState::GameLost) { break; }
		if (getGameState() == GameState::MainMenu) { break; }
		if (tetrino.IsStatic() && !arena.renderRandomPiece(tetrino)) { break; }
		printArena(renderList, list_length);
	}
	delete[] renderList;
}

//Calculates tetrino speed based on function from geogebra that we worked for 15min

int AppWindow::calcTetrinoSpeed()
{
	double a = (-1.0 / 2137.0) * (6.0 / 9420.0) * (6.0 / 9420.0) * (double)Score::getScore() * (double)Score::getScore() + 6.0;
	return a > 1 ? (int)(TETRINO_MAX_SPEED * a) : TETRINO_MAX_SPEED;
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
		listenEvents();
		window.clear();
		window.draw(MainMenu::T());
		window.draw(MainMenu::E());
		window.draw(MainMenu::TT());
		window.draw(MainMenu::R());
		window.draw(MainMenu::I());
		window.draw(MainMenu::S());
		window.draw(MainMenu::PlayButton(usedColors::playcolor));
		window.draw(MainMenu::HighScoreButton(usedColors::scorecolor));
		window.draw(MainMenu::QuitButton(usedColors::quitcolor));
		window.display();
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
		listenEvents();
		window.clear();
		window.draw(Scoreboard::getScoreboardAsText());
		window.display();
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
