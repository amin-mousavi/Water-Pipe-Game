#include "LPipe.h"

LPipe::LPipe():Pipe()
{
}


LPipe::~LPipe()
{
}

void LPipe::set_texture()
{
	this->pictureTexture.loadFromFile("image/3.png");
}
sf::Texture LPipe::get_texture()
{
	return this->pictureTexture;
}

void LPipe::set_sprite()
{
	this->pictureSprite.setTexture(get_texture());
}
sf::Sprite LPipe::get_sprite()
{
	return this->pictureSprite;
}


void LPipe::draw(sf::RenderWindow& pictureWindow, int row, int col, int title_size)
{
	sf::Vector2f offset(120, 110);

	pictureTexture.loadFromFile("image/3.png");
	pictureTexture.setSmooth(true);
	pictureSprite.setTexture(pictureTexture);
	pictureSprite.setOrigin(27, 27);

	pictureSprite.setRotation(getOrientation() * 90);
	
	pictureSprite.setPosition(col * title_size, row * title_size);
	pictureSprite.move(offset);
	//////////////////////////////////////////////////////////////////////////////////////
	pictureWindow.draw(pictureSprite);

}
