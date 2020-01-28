#include "LPipe.h"

LPipe::LPipe()
{
}


LPipe::~LPipe()
{
}


void LPipe::draw(sf::RenderWindow& pictureWindow, int row, int col, int title_size)
{
	sf::Vector2f offset(120, 110);

	pictureTexture.loadFromFile("image/3.png");
	pictureTexture.setSmooth(true);
	pictureSprite.setTexture(pictureTexture);
	pictureSprite.setOrigin(27, 27);

	//pictureSprite.setTextureRect(sf::IntRect(title_size * 2, 0, title_size, title_size));
	pictureSprite.setRotation(orientation * 90);
	pictureSprite.setPosition(col * title_size, row * title_size);
	pictureSprite.move(offset);
	//////////////////////////////////////////////////////////////////////////////////////
	pictureWindow.draw(pictureSprite);

}
