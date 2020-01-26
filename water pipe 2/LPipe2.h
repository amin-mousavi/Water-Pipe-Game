#pragma once
#ifndef L_PIPE2
#define L_PIPE2

#include "Pipe.h"

class LPipe2 : public Pipe
{
public:
	LPipe2();
	~LPipe2();

	void draw(sf::RenderWindow& pictureWindow, int row, int col, int title_size);
};

#endif