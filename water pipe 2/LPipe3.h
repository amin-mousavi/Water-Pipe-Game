#pragma once
#ifndef L_PIPE3
#define L_PIPE3

#include "Pipe.h"

class LPipe3 : public Pipe
{
public:
	LPipe3();
	~LPipe3();

	virtual void set_texture();
	virtual sf::Texture get_texture();

	virtual void set_sprite();
	virtual sf::Sprite get_sprite();

	void draw(sf::RenderWindow& pictureWindow, int row, int col, int title_size);
};

#endif