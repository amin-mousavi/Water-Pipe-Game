#pragma once
#ifndef PLUS_PIPE
#define PLUS_PIPE

#include "Pipe.h"

class PlusPipe : public Pipe {
public:

	PlusPipe();
	~PlusPipe();

	virtual void set_texture();
	virtual sf::Texture get_texture();

	virtual void set_sprite();
	virtual sf::Sprite get_sprite();

	void draw(sf::RenderWindow& pictureWindow, int row, int col, int title_size);
};

#endif