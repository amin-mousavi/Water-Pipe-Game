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

	void setAngle(float);
	float getAngle();

	void setOn(bool);
	bool getOn();

	void rotation();
	bool isConnect(sf::Vector2i);

	virtual void draw(sf::RenderWindow& pictureWindow, int, int, int) = 0;


protected:
	int orientation;
	float angle;
	bool on;
	sf::Texture pictureTexture;
	sf::Sprite pictureSprite;
	std::vector <sf::Vector2i> dirs;

};

#endif