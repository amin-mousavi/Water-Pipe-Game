#include "DirectPipe.h"


DirectPipe::DirectPipe()
{
}


DirectPipe::~DirectPipe()
{
}


void DirectPipe::set_texture()
{
	this->pictureTexture.loadFromFile("image/2.png");
}
sf::Texture DirectPipe::get_texture()
{
	return this->pictureTexture;
}

void DirectPipe::set_sprite()
{
	this->pictureSprite.setTexture(get_texture());
}
sf::Sprite DirectPipe::get_sprite()
{
	return this->pictureSprite;
}


void DirectPipe::draw(sf::RenderWindow& pictureWindow, int row, int col, int title_size)
{
	sf::Vector2f offset(120, 110);

	pictureTexture.loadFromFile("image/2.png");
	pictureTexture.setSmooth(true);
	pictureSprite.setTexture(pictureTexture);
	pictureSprite.setOrigin(27, 27);


	pictureSprite.setRotation(getOrientation() * 90);
	pictureSprite.setPosition(col * title_size, row * title_size);
	pictureSprite.move(offset);
	//////////////////////////////////////////////////////////////////////////////////////
	pictureWindow.draw(pictureSprite);

}
