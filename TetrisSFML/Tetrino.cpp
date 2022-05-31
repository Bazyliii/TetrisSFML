#include "Tetrino.h"
#include <time.h>
using namespace sf;

Box::Box()
{
	color = Color(213, 0, 249); 		//Rozowa fuksja
	block[0][0] = color;	//1,1,0,0
	block[0][1] = color;	//1,1,0,0
	block[1][0] = color;	//0,0,0,0
	block[1][1] = color;	//0,0,0,0
	length = 2;
}

TShape::TShape()
{
	color = Color(118, 255, 3);		//Limonkowy
	block[0][1] = color;	//0,1,0,0
	block[1][1] = color;	//0,1,1,0
	block[2][1] = color;	//0,1,0,0
	block[1][2] = color;	//0,0,0,0
	length = 3;
}

IShape::IShape()
{
	color = Color(24, 255, 255);		//Turkus
	block[1][0] = color;	//0,0,0,0
	block[1][1] = color;	//1,1,1,1
	block[1][2] = color;	//0,0,0,0
	block[1][3] = color;	//0,0,0,0
	length = 4;
}

LShapeRight::LShapeRight()
{
	color = Color(244, 67, 54);		//Czerwony?
	block[1][0] = color;	//0,1,0,0
	block[1][1] = color;	//0,1,0,0
	block[1][2] = color;	//0,1,1,0
	block[2][2] = color;	//0,0,0,0
	length = 3;
}

LShapeLeft::LShapeLeft()
{
	color = Color(48, 79, 254);		//Niebieski
	block[1][0] = color;	//0,1,0,0
	block[1][1] = color;	//0,1,0,0
	block[0][2] = color;	//1,1,0,0
	block[1][2] = color;	//0,0,0,0
	length = 3;
}

ZShapeRight::ZShapeRight()
{
	color = Color(255, 61, 0);		//Pomaranczowy
	block[0][1] = color;	//0,0,0,0
	block[1][1] = color;	//1,1,0,0
	block[1][2] = color;	//0,1,1,0
	block[2][2] = color;	//0,0,0,0
	length = 3;
}

ZShapeLeft::ZShapeLeft()
{
	color = Color(255, 255, 0);		//zolty
	block[0][1] = color;	//0,1,1,0
	block[0][2] = color;	//1,1,0,0
	block[1][0] = color;	//0,0,0,0
	block[1][1] = color;	//0,0,0,0
	length = 3;
}

iTetrino::iTetrino()
{
	color = usedColors::backgroundColor;
	Off_X = 0;
	Off_Y = 0;
	Off_X_last = 0;
	Off_Y_last = 0;
	length = height;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			block[i][j] = color;
		}
	}
}

void iTetrino::rotateCCW()
{ // rotate by 90deg (ccw)
	if (width != height) throw("NIE");
	for (int i = 0; i < length; i++)
		std::reverse(block[i], block[i] + length);
	for (int i = 0; i < length; i++) {
		for (int j = i; j < length; j++)
			std::swap(block[i][j], block[j][i]);
	}
}

void iTetrino::rotateCW() {
	rotateCCW();
	rotateCCW();
	rotateCCW();
}

void iTetrino::moveLeft()
{
	Off_X_last = Off_X--;
}

void iTetrino::moveRight() {
	Off_X_last = Off_X++;
}

void iTetrino::moveDown() {
	Off_Y_last = Off_Y++;
}

void iTetrino::moveToLastPos() {
	Off_X = Off_X_last;
	Off_Y = Off_Y_last;
}

sf::Color iTetrino::getColor() {
	return color;
}

uint16_t iTetrino::getOff_Y() {
	return Off_Y;
}

int16_t iTetrino::getOff_X() {
	return Off_X;
}

int iTetrino::getLength() {
	return length;
}
