#pragma once
#ifndef DIRECT_PIPE
#define DIRECT_PIPE

#include "Pipe.h"

class DirectPipe : public Pipe
{
public:
	DirectPipe();
	~DirectPipe();

	virtual void set_texture();
	virtual sf::Texture get_texture();

	virtual void set_sprite();
	virtual sf::Sprite get_sprite();

	void draw(sf::RenderWindow& pictureWindow, int row, int col, int title_size);
};

#endif