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
	void printBlock(int id, iTetrino tetrino) 
	{

	}
private:
	int Matrix[arenaHeight + 2][arenaWidth + 2];
};