#include "Tetrino.h"

using namespace sf;

Box::Box()
{
	sf::Color color(213, 0, 249); 			//Ró¿owa fuksja
	block[1][1] = color;	//0,0,0,0
	block[1][2] = color;	//0,1,1,0
	block[2][1] = color;	//0,1,1,0
	block[2][2] = color;	//0,0,0,0
}

TShape::TShape()
{
	block[1][0] = 1;	//0,1,0,0
	block[1][1] = 1;	//0,1,1,0
	block[1][2] = 1;	//0,1,0,0
	block[2][2] = 1;	//0,0,0,0
	color = Color(118, 255, 3);		//Limonkowy
}

IShape::IShape()
{
	block[1][0] = 1;	//0,1,0,0
	block[1][1] = 1;	//0,1,0,0
	block[1][2] = 1;	//0,1,0,0
	block[1][3] = 1;	//0,1,0,0
	color = Color(24, 255, 255);	//Turkus
}

LShapeRight::LShapeRight()
{
	block[1][0] = 1;	//0,1,0,0
	block[1][1] = 1;	//0,1,0,0
	block[1][2] = 1;	//0,1,1,0
	block[2][2] = 1;	//0,0,0,0
	color = Color(244, 67, 54);		//Czerwony?
}

LShapeLeft::LShapeLeft()
{
	block[2][0] = 1;	//0,0,1,0
	block[2][1] = 1;	//0,0,1,0
	block[1][2] = 1;	//0,1,1,0
	block[2][2] = 1;	//0,0,0,0
	color = Color(48, 79, 254);		//Niebieski
}

ZShapeRight::ZShapeRight()
{
	block[0][1] = 1;	//0,0,0,0
	block[1][1] = 1;	//1,1,0,0
	block[1][2] = 1;	//0,1,1,0
	block[2][2] = 1;	//0,0,0,0
	color = Color(255, 61, 0);		//Pomarañczowy
}

ZShapeLeft::ZShapeLeft()
{
	block[2][1] = 1;	//0,0,0,0
	block[3][1] = 1;	//0,0,1,1
	block[1][2] = 1;	//0,1,1,0
	block[2][2] = 1;	//0,0,0,0
	color = Color(255, 255, 0);		//¯ó³ty
}