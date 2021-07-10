#include "LPipe2.h"



LPipe2::LPipe2() :Pipe()
{
}


LPipe2::~LPipe2()
{
}

void LPipe2::set_texture()
{
	this->pictureTexture.loadFromFile("image/3-2.png");
}
sf::Texture LPipe2::get_texture()
{
	return this->pictureTexture;
}

void LPipe2::set_sprite()
{
	this->pictureSprite.setTexture(get_texture());
}
sf::Sprite LPipe2::get_sprite()
{
	return this->pictureSprite;
}

void LPipe2::draw(sf::RenderWindow& pictureWindow, int row, int col, int title_size)
{
	sf::Vector2f offset(120, 110);

	pictureTexture.loadFromFile("image/3-2.png");
	pictureTexture.setSmooth(true);
	pictureSprite.setTexture(pictureTexture);
	pictureSprite.setOrigin(27, 27);

	pictureSprite.setRotation(getOrientation() * 90);

	pictureSprite.setPosition(col * title_size, row * title_size);
	pictureSprite.move(offset);
	//////////////////////////////////////////////////////////////////////////////////////
	pictureWindow.draw(pictureSprite);
}