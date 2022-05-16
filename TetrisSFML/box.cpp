#include "box.h"

void Box::setColor()
{

}

Box::Box()
{
	// define a 120x50 rectangle
	rectangle = RectangleShape(Vector2f(120, 50));

	// change the size to 100x100
	rectangle.setSize(Vector2f(100, 100));
}
