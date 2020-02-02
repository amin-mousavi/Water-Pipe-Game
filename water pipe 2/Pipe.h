#include <SFML/Graphics.hpp>
#include <vector>

#ifndef PIPE_H
#define PIPE_H
/*
sf::Vector2i Up(0, -1);
sf::Vector2i Down(0, 1);
sf::Vector2i Right(1, 0);
sf::Vector2i Left(-1, 0);
*/

class Pipe {
public:
	Pipe();
	virtual ~Pipe();

	void setOrientation(int);
	int getOrientation();

	virtual void set_texture() = 0;
	virtual sf::Texture get_texture() = 0;

	virtual void set_sprite() = 0;
	virtual sf::Sprite get_sprite() = 0;

	virtual void draw(sf::RenderWindow& pictureWindow, int, int, int) = 0;

	bool startPipe[4] = { 0,0,0,0 }; //Up - Down - Left - Right
	bool endPipe[4] = { 0,0,0,0 };   //Up - Down - Left - Right

protected:
	
	int orientation;
	
	sf::Texture pictureTexture;
	sf::Sprite pictureSprite;
};

#endif