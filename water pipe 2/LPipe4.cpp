#include "LPipe4.h"



LPipe4::LPipe4()
{
}


LPipe4::~LPipe4()
{
}

void LPipe4::set_texture()
{
	this->pictureTexture.loadFromFile("image/3-4.png");
}
sf::Texture LPipe4::get_texture()
{
	return this->pictureTexture;
}

void LPipe4::set_sprite()
{
	this->pictureSprite.setTexture(get_texture());
}
sf::Sprite LPipe4::get_sprite()
{
	return this->pictureSprite;
}

void LPipe4::draw(sf::RenderWindow& pictureWindow, int row, int col, int title_size)
{
	sf::Vector2f offset(120, 110);

	pictureTexture.loadFromFile("image/3-4.png");
	pictureTexture.setSmooth(true);
	pictureSprite.setTexture(pictureTexture);
	pictureSprite.setOrigin(27, 27);

	pictureSprite.setRotation(getOrientation() * 90);
	
	pictureSprite.setPosition(col * title_size, row * title_size);
	pictureSprite.move(offset);
	//////////////////////////////////////////////////////////////////////////////////////
	pictureWindow.draw(pictureSprite);
}