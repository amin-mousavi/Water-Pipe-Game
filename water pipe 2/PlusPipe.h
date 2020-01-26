#pragma once
#ifndef PLUS_PIPE
#define PLUS_PIPE

#include "Pipe.h"

class PlusPipe : public Pipe {
public:

	PlusPipe();
	~PlusPipe();

	void draw(sf::RenderWindow& pictureWindow, int row, int col, int title_size);
};

#endif