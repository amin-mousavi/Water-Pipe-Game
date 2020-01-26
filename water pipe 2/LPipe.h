#pragma once
#ifndef L_PIPE
#define L_PIPE

#include "Pipe.h"

class LPipe : public Pipe
{
public:
	LPipe();
	~LPipe();

	void draw(sf::RenderWindow& pictureWindow, int row, int col, int title_size);

};

#endif