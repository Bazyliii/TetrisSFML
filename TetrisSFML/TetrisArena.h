#pragma once
#include <iostream>
#include <array>
#include "Tetrino.h"
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
	int* getArena();
	void printBlock(iTetrino tetrino)
	{
		std::memcpy(temmpMatrix, Matrix, sizeof(Matrix));
		int arenaCenter = ((arenaWidth + 2) / 2) - (iTetrino::width / 2);
		for (int i = arenaCenter; i < arenaCenter + iTetrino::width; i++)
		{

		}

	}
	void saveMatrix();
private:
	int Matrix[arenaHeight + 2][arenaWidth + 2];
	int temmpMatrix[arenaHeight + 2][arenaWidth + 2];
};