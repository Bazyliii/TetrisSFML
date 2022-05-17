#pragma once
#include <SFML/Graphics.hpp>


class iTetrino
{
public:
	static const int width = 4;
	static const int height = 4;
	sf::Color color;
	int block[height][width];
	iTetrino() :
		block{}, color{1}
	{}
private:
};


class Box :public iTetrino
{
	Box();
};

class TShape :public iTetrino
{
	TShape();
};

class IShape :public iTetrino
{
	IShape();
};

class LShapeRight :public iTetrino
{
	LShapeRight();
};

class LShapeLeft :public iTetrino
{
	LShapeLeft();
};

class ZShapeLeft :public iTetrino
{
	ZShapeLeft();
};

class ZShapeRight :public iTetrino
{
	ZShapeRight();
};