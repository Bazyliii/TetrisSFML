#include "Tetrino.h"
#include <time.h>
#include "Colors.h"
using namespace sf;

Box::Box()
{
	color = usedColors::BoxColor; 		//Rozowa fuksja
	block[0][0] = color;	//1,1,0,0
	block[0][1] = color;	//1,1,0,0
	block[1][0] = color;	//0,0,0,0
	block[1][1] = color;	//0,0,0,0
	length = 2;
}

TShape::TShape()
{
	color = usedColors::TShapeColor;		//Limonkowy
	block[0][1] = color;	//0,1,0,0
	block[1][1] = color;	//0,1,1,0
	block[2][1] = color;	//0,1,0,0
	block[1][2] = color;	//0,0,0,0
	length = 3;
}

IShape::IShape()
{
	color = usedColors::IShapeColor;		//Turkus
	block[1][0] = color;	//0,0,0,0
	block[1][1] = color;	//1,1,1,1
	block[1][2] = color;	//0,0,0,0
	block[1][3] = color;	//0,0,0,0
	length = 4;
}

LShapeRight::LShapeRight()
{
	color = usedColors::LShapeRightColor;		//Czerwony?
	block[1][0] = color;	//0,1,0,0
	block[1][1] = color;	//0,1,0,0
	block[1][2] = color;	//0,1,1,0
	block[2][2] = color;	//0,0,0,0
	length = 3;
}

LShapeLeft::LShapeLeft()
{
	color = usedColors::LShapeLeftColor;		//Niebieski
	block[1][0] = color;	//0,1,0,0
	block[1][1] = color;	//0,1,0,0
	block[0][2] = color;	//1,1,0,0
	block[1][2] = color;	//0,0,0,0
	length = 3;
}

ZShapeRight::ZShapeRight()
{
	color = usedColors::ZShapeRightColor;		//Pomaranczowy
	block[0][1] = color;	//0,0,0,0
	block[1][1] = color;	//1,1,0,0
	block[1][2] = color;	//0,1,1,0
	block[2][2] = color;	//0,0,0,0
	length = 3;
}

ZShapeLeft::ZShapeLeft()
{
	color = usedColors::ZShapeLeftColor;		//zolty
	block[0][1] = color;	//0,1,1,0
	block[0][2] = color;	//1,1,0,0
	block[1][0] = color;	//0,0,0,0
	block[1][1] = color;	//0,0,0,0
	length = 3;
}

void iTetrino::rotate()
{ // rotate by 90deg (ccw)
	if (IsStatic()) return;
	move = Move::rotation;
	wasRotated = true;
	Off_X_last = Off_X;
	Off_Y_last = Off_Y;
	if (width != height) throw("NIE");
	for (int i = 0; i < length; i++)
		std::reverse(block[i], block[i] + length);
	for (int i = 0; i < length; i++) {
		for (int j = i; j < length; j++)
			std::swap(block[i][j], block[j][i]);
	}
}

iTetrino::iTetrino()
{
	move = Move::none;
	color = usedColors::backgroundColor;
	wasRotated = false;
	State = false;
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
	std::memcpy(lastblock, block, sizeof(block));
}

void iTetrino::rotateCCW()
{
	std::memcpy(lastblock, block, sizeof(block));
	rotate();
}

void iTetrino::rotateCW()
{
	std::memcpy(lastblock, block, sizeof(block));
	for (int i = 0; i < 3; i++) rotate();
}

void iTetrino::moveLeft()
{
	if (IsStatic()) return;
	move = Move::left;
	wasRotated = false;
	Off_X_last = Off_X--;
	Off_Y_last = Off_Y;
}

void iTetrino::moveRight()
{
	if (IsStatic()) return;
	move = Move::right;
	wasRotated = false;
	Off_X_last = Off_X++;
	Off_Y_last = Off_Y;
}

void iTetrino::moveDown()
{
	if (IsStatic()) return;
	move = Move::down;
	wasRotated = false;
	Off_X_last = Off_X;
	Off_Y_last = Off_Y++;
}

bool iTetrino::moveToLastPos()
{
	if (IsStatic()) return false;
	if (Off_X == Off_X_last && Off_Y == Off_Y_last && !wasRotated) return false; //If last pos is the same return false meaning returning failed
	Off_X = Off_X_last;
	Off_Y = Off_Y_last;
	if (wasRotated) std::memcpy(block, lastblock, sizeof(lastblock));
	return true;
}

sf::Color iTetrino::getColor()
{
	return color;
}

uint16_t iTetrino::getOff_Y()
{
	return Off_Y;
}

int16_t iTetrino::getOff_X()
{
	return Off_X;
}

int iTetrino::getLength()
{
	return length;
}

bool iTetrino::IsStatic()
{
	return State;
}

void iTetrino::setStatic()
{
	State = true;
}

iTetrino::Move iTetrino::lastMove()
{
	return move;
}
