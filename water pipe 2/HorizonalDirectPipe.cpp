#include "HorizonalDirectPipe.h"



HorizonalDirectPipe::HorizonalDirectPipe():Pipe()
{
}


HorizonalDirectPipe::~HorizonalDirectPipe()
{
}

void HorizonalDirectPipe::set_texture()
{
	this->pictureTexture.loadFromFile("image/2-2.png");
}
sf::Texture HorizonalDirectPipe::get_texture()
{
	return this->pictureTexture;
}

void HorizonalDirectPipe::set_sprite()
{
	this->pictureSprite.setTexture(get_texture());
}
sf::Sprite HorizonalDirectPipe::get_sprite()
{
	return this->pictureSprite;
}

void HorizonalDirectPipe::draw(sf::RenderWindow& pictureWindow, int row, int col, int title_size)
{

	sf::Vector2f offset(120, 110);
	pictureTexture.loadFromFile("image/2-2.png");
	pictureTexture.setSmooth(true);
	pictureSprite.setTexture(pictureTexture);
	pictureSprite.setOrigin(27, 27);

	pictureSprite.setRotation(getOrientation() * 90);
	
	pictureSprite.setPosition(col * title_size, row * title_size);
	pictureSprite.move(offset);
	//////////////////////////////////////////////////////////////////////////////////////
	pictureWindow.draw(pictureSprite);

}