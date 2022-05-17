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
