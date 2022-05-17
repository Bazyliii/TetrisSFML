#pragma once
#include <iostream>
#include <array>
#include <SFML/Graphics.hpp>
#include "Tetrino.h"
#include "Colors.h"
#define arenaWidth 10
#define arenaHeight 20



class Arena
{

	// Arena matrix: 
	// 0 <-- blank space
	// -1 <-- border
	// 1,inf <-- blocks id's

public:
	Arena();
	void printBlock(iTetrino tetrino);
	void saveMatrix();
	sf::Color tempMatrix[arenaHeight + 2][arenaWidth + 2];
private:
	sf::Color Matrix[arenaHeight + 2][arenaWidth + 2];
};