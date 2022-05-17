#include "TetrisArena.h"

const sf::Color Arena::backgroundColor(52, 70, 93);
const sf::Color Arena::borderColor(19, 20, 24);

Arena::Arena()
{
	for (int i = 0; i < arenaHeight + 2; i++)
	{
		for (int j = 0; j < arenaWidth + 2; j++)
		{
			Matrix[i][j] = backgroundColor;

			tempMatrix[i][j] = backgroundColor;
		}
	}

	for (int i = 0; i < arenaHeight + 2; i++)
	{
		Matrix[i][0] = borderColor;
		Matrix[i][arenaWidth + 1] = borderColor;

		tempMatrix[i][0] = borderColor;
		tempMatrix[i][arenaWidth + 1] = borderColor;
	}

	for (int i = 0; i < arenaWidth + 2; i++)
	{
		Matrix[0][i] = borderColor;
		Matrix[arenaHeight + 1][i] = borderColor;

		tempMatrix[0][i] = borderColor;
		tempMatrix[arenaHeight + 1][i] = borderColor;
	}
}

void Arena::printBlock(iTetrino tetrino)
{
	std::memcpy(tempMatrix, Matrix, sizeof(Matrix));
	int arenaCenter = ((arenaWidth + 2) / 2) - (iTetrino::width / 2);
	for (int i = 1; i < iTetrino::height; i++)
	{
		for (int j = arenaCenter, k = 0; j < arenaCenter + iTetrino::width; j++, k++)
		{
			tempMatrix[i][j] = tetrino.block[i - 1][k];
		}
	}

}

void Arena::saveMatrix()
{
	std::memcpy(Matrix, tempMatrix, sizeof(Matrix));
}

