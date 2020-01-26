
#include "Pipe.h"

/*
sf::Vector2i Up(0, -1);
sf::Vector2i Down(0, 1);
sf::Vector2i Right(1, 0);
sf::Vector2i Left(-1, 0);
*/

Pipe::Pipe()
{
	angle = 0;
	orientation = 0;
	on = false;

}
void Pipe::setOrientation(int orientation)
{
	this->orientation = orientation;
}
int Pipe::getOrientation()
{
	return orientation;
}

void Pipe::setAngle(float angle)
{
	this->angle = angle;
}
float Pipe::getAngle()
{
	return angle;
}

void Pipe::setOn(bool on)
{
	this->on = on;
}
bool Pipe::getOn()
{
	return on;
}

void Pipe::rotation()
{
	for (int i = 0; i < dirs.size(); i++)
		if (dirs[i] == sf::Vector2i(0, -1))
		{
			dirs[i] = sf::Vector2i(1, 0);
		}
		else if (dirs[i] == sf::Vector2i(1, 0))
		{
			dirs[i] = sf::Vector2i(0, 1);
		}
		else if (dirs[i] == sf::Vector2i(0, 1))
		{
			dirs[i] = sf::Vector2i(-1, 0);
		}
		else if (dirs[i] == sf::Vector2i(-1, 0))
		{
			dirs[i] = sf::Vector2i(0, -1);
		}
}
bool Pipe::isConnect(sf::Vector2i direction)
{
	for (auto d : dirs)
		if (d == direction) return true;
	return false;
}

void Pipe::draw(sf::RenderWindow & pictureWindow, int, int, int)
{

}
Pipe::~Pipe()
{
}
