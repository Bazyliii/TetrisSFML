#include "Tetrino.h"

using namespace sf;

Box::Box()
{
	Color color(213, 0, 249); 		//Ró¿owa fuksja
	block[1][1] = color;	//0,0,0,0
	block[1][2] = color;	//0,1,1,0
	block[2][1] = color;	//0,1,1,0
	block[2][2] = color;	//0,0,0,0
}

TShape::TShape()
{
	Color color(118, 255, 3);		//Limonkowy
	block[1][0] = color;	//0,1,0,0
	block[1][1] = color;	//0,1,1,0
	block[1][2] = color;	//0,1,0,0
	block[2][1] = color;	//0,0,0,0
}

IShape::IShape()
{
	Color color(24, 255, 255);		//Turkus
	block[1][0] = color;	//0,1,0,0
	block[1][1] = color;	//0,1,0,0
	block[1][2] = color;	//0,1,0,0
	block[1][3] = color;	//0,1,0,0
}

LShapeRight::LShapeRight()
{
	Color color(244, 67, 54);		//Czerwony?
	block[1][0] = color;	//0,1,0,0
	block[1][1] = color;	//0,1,0,0
	block[1][2] = color;	//0,1,1,0
	block[2][2] = color;	//0,0,0,0
}

LShapeLeft::LShapeLeft()
{
	Color color(48, 79, 254);		//Niebieski
	block[2][0] = color;	//0,0,1,0
	block[2][1] = color;	//0,0,1,0
	block[1][2] = color;	//0,1,1,0
	block[2][2] = color;	//0,0,0,0
}

ZShapeRight::ZShapeRight()
{
	Color color(255, 61, 0);		//Pomarañczowy
	block[0][1] = color;	//0,0,0,0
	block[1][1] = color;	//1,1,0,0
	block[1][2] = color;	//0,1,1,0
	block[2][2] = color;	//0,0,0,0
}

ZShapeLeft::ZShapeLeft()
{
	Color color(255, 255, 0);		//¯ó³ty
	block[2][1] = color;	//0,0,0,0
	block[3][1] = color;	//0,0,1,1
	block[1][2] = color;	//0,1,1,0
	block[2][2] = color;	//0,0,0,0
}

iTetrino::iTetrino()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			block[i][j] = usedColors::backgroundColor;
		}
	}
}
