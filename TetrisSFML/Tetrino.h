#pragma once
#include <SFML/Graphics.hpp>
#include "Colors.h"


class iTetrino
{
private:
	static const int width = 4;
	static const int height = 4;
	bool wasRotated;
	bool State;
	uint16_t Off_Y;
	int16_t Off_X;
	uint16_t Off_Y_last;
	int16_t Off_X_last;
	void rotate();
public:
	int length;
	sf::Color color;
	sf::Color block[height][width];
	sf::Color lastblock[height][width];
	iTetrino();
	void rotateCCW();
	void rotateCW();
	void moveLeft();
	void moveRight();
	void moveDown();
	bool moveToLastPos();
	sf::Color getColor();
	uint16_t getOff_Y();
	int16_t getOff_X();
	int getLength();
	bool IsStatic();
	void setStatic();
};


class Box :public iTetrino
{
public:
	Box();
};

class TShape :public iTetrino
{
public:
	TShape();
};

class IShape :public iTetrino
{
public:
	IShape();
};

class LShapeRight :public iTetrino
{
public:
	LShapeRight();
};

class LShapeLeft :public iTetrino
{
public:
	LShapeLeft();
};

class ZShapeLeft :public iTetrino
{
public:
	ZShapeLeft();
};

class ZShapeRight :public iTetrino
{
public:
	ZShapeRight();
};