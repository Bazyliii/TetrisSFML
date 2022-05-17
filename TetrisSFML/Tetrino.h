#pragma once

class iTetrino
{
public:
	static const int width = 4;
	static const int height = 4;
	int block[height][width];
	iTetrino() :
		block {}
	{}
private:
};


class Box :public iTetrino
{
	Box()
	{
		block[1][1] = 1;
		block[1][2] = 1;
		block[2][1] = 1;
		block[2][2] = 1;
	}
};

class Box :public iTetrino
{
	Box()
	{
		block[1][1] = 1;
		block[1][2] = 1;
		block[2][1] = 1;
		block[2][2] = 1;
	}
};