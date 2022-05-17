#pragma once
#include <SFML/Graphics.hpp>


class iTetrino
{
public:
	static const int width = 4;
	static const int height = 4;
	sf::Color block[height][width];
	iTetrino() :
		block{}
	{}
private:
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