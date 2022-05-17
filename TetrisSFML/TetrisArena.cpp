#include "TetrisArena.h"

int Matrix[arenaHeight][arenaWidth] = {};

Arena::Arena()
{
	for (int i = 0; i < arenaHeight; i++)
	{
		for (int j = 0; j < arenaWidth; j++)
		{
			Matrix[i][j] = 0;
		}
	}
}

