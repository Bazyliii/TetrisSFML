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

void Arena::printBlock(iTetrino& tetrino)
{
	//PREPARE temp arena
	if (tetrino.IsStatic()) return;
	std::memcpy(tempMatrix, Matrix, sizeof(Matrix));							//Get tempMatrix up to date
	int arenaCenter = ((arenaWidth + 2) / 2) - (tetrino.getLength() / 2);		//Calc arena center for blocks to be placed
	//RENDERING
	try
	{
		for (int i = 1 + tetrino.getOff_Y(), j = 0; j < tetrino.getLength(); i++, j++)
		{
			for (int k = arenaCenter + tetrino.getOff_X(), l = 0; k < arenaCenter + tetrino.getLength() + tetrino.getOff_X(); k++, l++)
			{
				//Collisions
				if (tempMatrix[i][k] != usedColors::backgroundColor && tetrino.block[j][l] == tetrino.color) {
					if (i == arenaHeight + 1) throw 420;	//Colision with bottom of arena
					else if (tempMatrix[i][k] != usedColors::backgroundColor&&tempMatrix[i][k] != usedColors::borderColor)throw 420;
					else throw 69420;
				}
				//Place block
				if (tempMatrix[i][k] == usedColors::backgroundColor) tempMatrix[i][k] = tetrino.block[j][l];
			}
		}
	}
	catch (int x)
	{
		switch (x)
		{
		case 69420:
			tetrino.moveToLastPos();
			printBlock(tetrino);
			return;
		case 420:
			tetrino.moveToLastPos();
			printBlock(tetrino);
			saveMatrix();
			tetrino.setStatic();
			return;
		default:
			throw 69420;
			break;
		}
	}
}

void Arena::saveMatrix()
{
	std::memcpy(Matrix, tempMatrix, sizeof(Matrix));
}

