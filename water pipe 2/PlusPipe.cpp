#include "PlusPipe.h"



PlusPipe::PlusPipe()
{

}


PlusPipe::~PlusPipe()
{
}


void PlusPipe::set_texture()
{
	this->pictureTexture.loadFromFile("image/3-4.png");
}
sf::Texture PlusPipe::get_texture()
{
	return this->pictureTexture;
}

void PlusPipe::set_sprite()
{
	this->pictureSprite.setTexture(get_texture());
}
sf::Sprite PlusPipe::get_sprite()
{
	return this->pictureSprite;
}

void PlusPipe::draw(sf::RenderWindow& pictureWindow, int row, int col, int title_size)
{
	sf::Vector2f offset(120, 110);

	pictureTexture.loadFromFile("image/4.png");
	pictureTexture.setSmooth(true);
	pictureSprite.setTexture(pictureTexture);
	pictureSprite.setOrigin(27, 27);

	pictureSprite.setRotation(getOrientation() * 90);

	pictureSprite.setPosition(col * title_size, row * title_size);
	pictureSprite.move(offset);
	//////////////////////////////////////////////////////////////////////////////////////
	pictureWindow.draw(pictureSprite);
}
