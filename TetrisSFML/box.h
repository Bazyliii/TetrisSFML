#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <iostream>

using namespace sf;
class Box
{
private:
	RectangleShape rectangle;
	void setColor();
public:
	Box();
};