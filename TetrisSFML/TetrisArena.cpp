#include "TetrisArena.h"
#include "Window.h"

//Ahh win api
#define WIN32_LEAN_AND_MEAN
#include <windows.h>



Arena::Arena() :
	generatorRNG(random_device()()), susage(0, 5)
{
	gameState = true;
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

bool Arena::printBlock(iTetrino& tetrino)
{
	//PREPARE temp arena
	if (tetrino.IsStatic()) return true;
	if (!gameState) return false;
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
				if (tempMatrix[i][k] != usedColors::backgroundColor && tetrino.block[j][l] == tetrino.color)
				{
					iTetrino::Move lastMove = tetrino.lastMove();
					if (i == arenaHeight + 1) throw 1;	//Colision with bottom of arena
					else if (tempMatrix[i][k] != usedColors::borderColor && (lastMove == iTetrino::Move::down || lastMove == iTetrino::Move::none))
						throw 1; //Colision with block in arena
					else throw 0;
				}
				//Place block
				if (tempMatrix[i][k] == usedColors::backgroundColor) tempMatrix[i][k] = tetrino.block[j][l];
			}
		}
	}
	//Catch collisions
	catch (int x)
	{
		switch (x)
		{
		case 0:
			tetrino.moveToLastPos();
			return printBlock(tetrino);
		case 1:
			if (!tetrino.moveToLastPos())
			{
				MessageBoxA(NULL, "You lost", "Game ended!!", MB_ICONEXCLAMATION);
				gameState = false;
				return false;
			}
			if (!printBlock(tetrino)) return false;
			saveMatrix();
			tetrino.setStatic();
			clearLine();
			//Do poprawienia
			{
				switch (susage(generatorRNG)) {
				case 0:
					tetrino = Box();
					break;
				case 1:
					tetrino = TShape();
					break;
				case 2:
					tetrino = IShape();
					break;
				case 3:
					tetrino = LShapeLeft();
					break;
				case 4:
					tetrino = LShapeRight();
					break;
				case 5:
					tetrino = ZShapeLeft();
					break;
				case 6:
					tetrino = ZShapeRight();
					break;
				}
				return printBlock(tetrino);
			}
		default:
			throw 0;
			break;
		}
	}
	return true;
}

void Arena::saveMatrix()
{
	std::memcpy(Matrix, tempMatrix, sizeof(Matrix));
}

void Arena::clearLine() {
	for(int k=20;k>=2;k--){
		if (tempMatrix[k][1] != usedColors::backgroundColor &&
			tempMatrix[k][2] != usedColors::backgroundColor &&
			tempMatrix[k][3] != usedColors::backgroundColor &&
			tempMatrix[k][4] != usedColors::backgroundColor &&
			tempMatrix[k][5] != usedColors::backgroundColor &&
			tempMatrix[k][6] != usedColors::backgroundColor &&
			tempMatrix[k][7] != usedColors::backgroundColor &&
			tempMatrix[k][8] != usedColors::backgroundColor &&
			tempMatrix[k][9] != usedColors::backgroundColor &&
			tempMatrix[k][10] != usedColors::backgroundColor) {
				for (int j = k; j >= 2;j--) {
					for (int i = 1;i <= 10;i++) {
						Matrix[j][i] = Matrix[j - 1][i];
						tempMatrix[j][i] = tempMatrix[j - 1][i];
					}
				}
				k++;
			}
		}
	}