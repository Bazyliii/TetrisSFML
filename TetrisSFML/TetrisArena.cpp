#include "TetrisArena.h"



Arena::Arena()
{
	for (int i = 0; i < arenaHeight + 2; i++)
	{
		for (int j = 0; j < arenaWidth + 2; j++)
		{
			Matrix[i][j] = usedColors::backgroundColor;

			tempMatrix[i][j] = usedColors::backgroundColor;
		}
	}

	for (int i = 0; i < arenaHeight + 2; i++)
	{
		Matrix[i][0] = usedColors::borderColor;
		Matrix[i][arenaWidth + 1] = usedColors::borderColor;

		tempMatrix[i][0] = usedColors::borderColor;
		tempMatrix[i][arenaWidth + 1] = usedColors::borderColor;
	}

	for (int i = 0; i < arenaWidth + 2; i++)
	{
		Matrix[0][i] = usedColors::borderColor;
		Matrix[arenaHeight + 1][i] = usedColors::borderColor;

		tempMatrix[0][i] = usedColors::borderColor;
		tempMatrix[arenaHeight + 1][i] = usedColors::borderColor;
	}
}

void Arena::printBlock(iTetrino tetrino)
{
	std::memcpy(tempMatrix, Matrix, sizeof(Matrix));						//Get tempMatrix up to date
	int arenaCenter = ((arenaWidth + 2) / 2) - (iTetrino::width / 2);		//Calc arena center for blocks to be placed
	for (int i = 1 + tetrino.Off_Y, j = 0; j < iTetrino::height; i++, j++)
	{
		for (int k = arenaCenter + tetrino.Off_X, l = 0; (k < arenaCenter + iTetrino::width + tetrino.Off_X); k++, l++)
		{
			if (tempMatrix[i][k] == usedColors::backgroundColor) tempMatrix[i][k] = tetrino.block[j][l];
		}
	}

}

void Arena::saveMatrix()
{
	std::memcpy(Matrix, tempMatrix, sizeof(Matrix));
}

