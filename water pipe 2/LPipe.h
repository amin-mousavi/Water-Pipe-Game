#pragma once
#ifndef L_PIPE
#define L_PIPE

#include "Pipe.h"

class LPipe : public Pipe
{
public:
	LPipe();
	~LPipe();

	virtual void set_texture();
	virtual sf::Texture get_texture();

	virtual void set_sprite();
	virtual sf::Sprite get_sprite();

	void draw(sf::RenderWindow& pictureWindow, int row, int col, int title_size);
};

#endif