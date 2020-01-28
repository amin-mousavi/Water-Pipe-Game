#pragma once
#ifndef DIRECT_PIPE
#define DIRECT_PIPE

#include "Pipe.h"

class DirectPipe : public Pipe
{
public:
	DirectPipe();
	~DirectPipe();

	void draw(sf::RenderWindow& pictureWindow, int row, int col, int title_size);

	//void Draw(sf::RenderWindow& pictureWindow, Pipe*, int, int, int);
};

#endif