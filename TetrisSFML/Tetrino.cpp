#include "Tetrino.h"

Box::Box()
{
	block[1][1] = 1;	//0,0,0,0
	block[1][2] = 1;	//0,1,1,0
	block[2][1] = 1;	//0,1,1,0
	block[2][2] = 1;	//0,0,0,0
}

TShape::TShape()
{
	block[1][0] = 1;	//0,1,0,0
	block[1][1] = 1;	//0,1,1,0
	block[1][2] = 1;	//0,1,0,0
	block[2][2] = 1;	//0,0,0,0
}

IShape::IShape()
{
	block[1][0] = 1;	//0,1,0,0
	block[1][1] = 1;	//0,1,0,0
	block[1][2] = 1;	//0,1,0,0
	block[1][3] = 1;	//0,1,0,0
}

LShapeRight::LShapeRight()
{
	block[1][0] = 1;	//0,1,0,0
	block[1][1] = 1;	//0,1,0,0
	block[1][2] = 1;	//0,1,1,0
	block[2][2] = 1;	//0,0,0,0
}

LShapeLeft::LShapeLeft()
{
	block[2][0] = 1;	//0,0,1,0
	block[2][1] = 1;	//0,0,1,0
	block[1][2] = 1;	//0,1,1,0
	block[2][2] = 1;	//0,0,0,0
}

ZShapeRight::ZShapeRight()
{
	block[0][1] = 1;	//0,0,0,0
	block[1][1] = 1;	//1,1,0,0
	block[1][2] = 1;	//0,1,1,0
	block[2][2] = 1;	//0,0,0,0
}

ZShapeLeft::ZShapeLeft()
{
	block[2][1] = 1;	//0,0,0,0
	block[3][1] = 1;	//0,0,1,1
	block[1][2] = 1;	//0,1,1,0
	block[2][2] = 1;	//0,0,0,0
}