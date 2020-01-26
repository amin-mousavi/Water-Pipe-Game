#pragma once
#ifndef L_PIPE3
#define L_PIPE3

#include "Pipe.h"

class LPipe3 : public Pipe
{
public:
	LPipe3();
	~LPipe3();

	void draw(sf::RenderWindow& pictureWindow, int row, int col, int title_size);
};

#endif