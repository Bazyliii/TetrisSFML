#pragma once

class box
{
private:
	RectangleShape rectangle
		setColor()
	{

	}
public:
	box()
	{
		// define a 120x50 rectangle
		RectangleShape rectangle(Vector2f(120, 50));

		// change the size to 100x100
		rectangle.setSize(Vector2f(100, 100));
	}
};