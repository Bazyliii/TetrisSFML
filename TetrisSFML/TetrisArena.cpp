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
	//PREPARE temp arena
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
				if (tempMatrix[i][k] != usedColors::backgroundColor && tetrino.block[j][l] == tetrino.color) throw 69420;
				//Place block
				if (tempMatrix[i][k] == usedColors::backgroundColor) tempMatrix[i][k] = tetrino.block[j][l];
			}
		}
	}
	catch (int x) 
	{
		if (x != 69420) throw 2137;
		tetrino.moveToLastPos();
		printBlock(tetrino);
		return;
	}

}

void Arena::saveMatrix()
{
	std::memcpy(Matrix, tempMatrix, sizeof(Matrix));
}

