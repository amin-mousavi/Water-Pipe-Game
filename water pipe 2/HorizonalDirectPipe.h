#pragma once

#ifndef HORIZONAL_DIRECT_PIPE
#define HORIZONAL_DIRECT_PIPE
#include "Pipe.h"

class HorizonalDirectPipe : public Pipe {

public:

	HorizonalDirectPipe();
	~HorizonalDirectPipe();

	virtual void set_texture();
	virtual sf::Texture get_texture();

	virtual void set_sprite();
	virtual sf::Sprite get_sprite();

	void draw(sf::RenderWindow& pictureWindow, int row, int col, int title_size);
};

#endif