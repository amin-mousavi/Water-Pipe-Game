
#include "Pipe.h"

Pipe::Pipe()
{
	orientation = 0;
	
	
}
void Pipe::setOrientation(int orientation)
{
	this->orientation = orientation;
}
int Pipe::getOrientation()
{
	return orientation;
}

void Pipe::draw(sf::RenderWindow & pictureWindow, int, int, int)
{

}
/*
void set_texture()
{

}
sf::Texture get_texture()
{

}

void set_sprite()
{

}
sf::Sprite get_sprite()
{

}
*/
Pipe::~Pipe()
{
}
