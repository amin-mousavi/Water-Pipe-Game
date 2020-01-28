#include "DirectPipe.h"


DirectPipe::DirectPipe()
{
}


DirectPipe::~DirectPipe()
{
}

void DirectPipe::draw(sf::RenderWindow& pictureWindow, int row, int col, int title_size)
{


	/*int type = dirs.size();
	if (type == 2 && dirs[0] == -dirs[1]) type = 0;

	angle += 5;
	if (angle > orientation * 90)
	{
		angle = orientation * 90;
	}
	*/
	sf::Vector2f offset(120, 110);

	pictureTexture.loadFromFile("image/2.png");
	pictureTexture.setSmooth(true);
	pictureSprite.setTexture(pictureTexture);
	pictureSprite.setOrigin(27, 27);

	//pictureSprite.setTextureRect(sf::IntRect(title_size * 2 , 0, title_size , title_size));
	pictureSprite.setRotation(getOrientation() * 90);
	pictureSprite.setPosition(col * title_size, row * title_size);
	pictureSprite.move(offset);
	//////////////////////////////////////////////////////////////////////////////////////
	pictureWindow.draw(pictureSprite);

}

/*
void DirectPipe::Draw(sf::RenderWindow& PictureWindow, Pipe* pPtr, int Row, int Col, int TileSize)
{
	/*int type = dirs.size();
	if (type == 2 && dirs[0] == -dirs[1]) type = 0;

	angle += 5;
	if (angle > orientation * 90)
	{
		angle = orientation * 90;
	}
	
	sf::Vector2f offset(120, 110);

	pictureTexture.loadFromFile("image/2.png");
	pictureTexture.setSmooth(true);
	pictureSprite.setTexture(pictureTexture);
	pictureSprite.setOrigin(27, 27);

	//pictureSprite.setTextureRect(sf::IntRect(title_size * 2 , 0, title_size , title_size));
	pictureSprite.setRotation(getOrientation() * 90);
	pictureSprite.setPosition(Col * TileSize, Row * TileSize);
	//pictureSprite.move(offset);
	//////////////////////////////////////////////////////////////////////////////////////
	//PictureWindow.draw(pictureSprite);
}

*/