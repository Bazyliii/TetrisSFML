#include "Score.h"
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include "Window.h"

void Score::showScore() {
	if (!font.loadFromFile("Gameplay.ttf")) {
		system("pause");
	}
	text.setFont(font);
	text.setString("Chdsfsdfsdfsdfsdfuj");
}