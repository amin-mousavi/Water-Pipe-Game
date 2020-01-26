#pragma once

#ifndef HORIZONAL_DIRECT_PIPE
#define HORIZONAL_DIRECT_PIPE
#include "Pipe.h"

class HorizonalDirectPipe : public Pipe {

public:

	HorizonalDirectPipe();
	~HorizonalDirectPipe();
	void draw(sf::RenderWindow& pictureWindow, int row, int col, int title_size);
};

#endif