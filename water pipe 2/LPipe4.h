#pragma once
#ifndef L_PIPE4
#define L_PIPE4

#include "Pipe.h"

class LPipe4 : public Pipe
{
public:
	LPipe4();
	~LPipe4();

	virtual void set_texture();
	virtual sf::Texture get_texture();

	virtual void set_sprite();
	virtual sf::Sprite get_sprite();

	void draw(sf::RenderWindow& pictureWindow, int row, int col, int title_size);
};

#endif