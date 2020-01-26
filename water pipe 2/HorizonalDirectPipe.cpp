#include "HorizonalDirectPipe.h"



HorizonalDirectPipe::HorizonalDirectPipe() :Pipe()
{
}


HorizonalDirectPipe::~HorizonalDirectPipe()
{
}

void HorizonalDirectPipe::draw(sf::RenderWindow& pictureWindow, int row, int col, int title_size)
{
	/*
	int type = dirs.size();
	if (type == 2 && dirs[0] == -dirs[1]) type = 0;

	angle += 5;
	if (angle > orientation * 90)
	{
		angle = orientation * 90;
	}
	*/

	sf::Vector2f offset(120, 110);
	pictureTexture.loadFromFile("image/2-2.png");
	pictureSprite.setTexture(pictureTexture);
	pictureSprite.setOrigin(27, 27);

	//pictureSprite.setTextureRect(sf::IntRect(title_size * 2 , 0, title_size , title_size));
	pictureSprite.setRotation(orientation * 90);
	pictureSprite.setPosition(col * title_size, row * title_size);
	pictureSprite.move(offset);
	//////////////////////////////////////////////////////////////////////////////////////
	pictureWindow.draw(pictureSprite);

}