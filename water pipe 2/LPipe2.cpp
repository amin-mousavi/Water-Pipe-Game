#include "LPipe2.h"



LPipe2::LPipe2() :Pipe()
{
}


LPipe2::~LPipe2()
{
}

void LPipe2::draw(sf::RenderWindow& pictureWindow, int row, int col, int title_size)
{
	sf::Vector2f offset(120, 110);

	pictureTexture.loadFromFile("image/3-2.png");
	pictureSprite.setTexture(pictureTexture);
	pictureSprite.setOrigin(27, 27);

	//pictureSprite.setTextureRect(sf::IntRect(title_size * 2, 0, title_size, title_size));
	pictureSprite.setRotation(orientation * 90);
	pictureSprite.setPosition(col * title_size, row * title_size);
	pictureSprite.move(offset);
	//////////////////////////////////////////////////////////////////////////////////////
	pictureWindow.draw(pictureSprite);
}