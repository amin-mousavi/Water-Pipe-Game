#include "LPipe3.h"



LPipe3::LPipe3() :Pipe()
{
}


LPipe3::~LPipe3()
{
}

void LPipe3::set_texture()
{
	this->pictureTexture.loadFromFile("image/3-3.png");
}
sf::Texture LPipe3::get_texture()
{
	return this->pictureTexture;
}

void LPipe3::set_sprite()
{
	this->pictureSprite.setTexture(get_texture());
}
sf::Sprite LPipe3::get_sprite()
{
	return this->pictureSprite;
}

void LPipe3::draw(sf::RenderWindow& pictureWindow, int row, int col, int title_size)
{
	sf::Vector2f offset(120, 110);

	pictureTexture.loadFromFile("image/3-3.png");
	pictureTexture.setSmooth(true);
	pictureSprite.setTexture(pictureTexture);
	pictureSprite.setOrigin(27, 27);

	pictureSprite.setRotation(getOrientation() * 90);

	pictureSprite.setPosition(col * title_size, row * title_size);
	pictureSprite.move(offset);
	//////////////////////////////////////////////////////////////////////////////////////
	pictureWindow.draw(pictureSprite);
}