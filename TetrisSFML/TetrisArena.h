#pragma once
#include <iostream>
#include <array>
#include <SFML/Graphics.hpp>
#include "Tetrino.h"
#include "Score.h"
#include "Colors.h"
#include <random>
#define arenaWidth 10
#define arenaHeight 20



class Arena
{
public:
	Arena();
	bool printBlock(iTetrino& tetrino) ;
	void saveMatrix();
	void clearLine();
	sf::Color tempMatrix[arenaHeight + 2][arenaWidth + 2];
private:
	std::mt19937 generatorRNG;
	std::uniform_int_distribution<std::mt19937::result_type> susage;
	bool gameState;
	sf::Color Matrix[arenaHeight + 2][arenaWidth + 2];
};