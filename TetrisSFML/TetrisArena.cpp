#include "TetrisArena.h"

Arena::Arena()
{
	for (int i = 0; i < arenaHeight + 2; i++)
	{
		for (int j = 0; j < arenaWidth + 2; j++)
		{
			Matrix[i][j] = 0;
		}
	}

	for (int i = 0; i < arenaHeight + 2; i++)
	{
		Matrix[i][0] = -1;
		Matrix[i][arenaWidth + 1] = -1;
	}

	for (int i = 0; i < arenaWidth + 2; i++)
	{
		Matrix[0][i] = -1;
		Matrix[arenaHeight + 1][i] = -1;
	}
}

int* Arena::getArena()
{
	return *Matrix;
}

void Arena::printBlock(iTetrino tetrino)
{
	std::memcpy(temmpMatrix, Matrix, sizeof(Matrix));
	int arenaCenter = ((arenaWidth + 2) / 2) - (iTetrino::width / 2);
	for (int i = 1; i < iTetrino::height; i++)
	{
		for (int j = arenaCenter, int k = 0; j < arenaCenter + iTetrino::width; j++, k++)
		{
			temmpMatrix[i][j] = tetrino.block[i - 1][k];
		}
	}

}

void Arena::saveMatrix()
{
	std::memcpy(Matrix, temmpMatrix, sizeof(Matrix));
}

