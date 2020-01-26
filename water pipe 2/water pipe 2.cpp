#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <array>

#include "DirectPipe.h"
#include "HorizonalDirectPipe.h"
#include "LPipe.h"
#include "LPipe2.h"
#include "LPipe3.h"
#include "LPipe4.h"
#include "PlusPipe.h"

const int length = 5;
int tileSize = 54;
sf::Vector2f offset(120, 110);



using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(445, 445), "Water Pipe Game", sf::Style::Default);

	srand(static_cast<unsigned int>(time(0)));


	sf::Texture t1, t2, t3, t4, begin, end;
	if (!t1.loadFromFile("image/background1.jpg"))
	{
		cout << "error" << endl;
	}
	t1.loadFromFile("image/background1.jpg");
	/*t2.loadFromFile("image/2.png");
	t3.loadFromFile("image/3.png");
	t4.loadFromFile("image/4.png");
	t4.setSmooth(true);
	*/

	begin.loadFromFile("image/begin.png");
	end.loadFromFile("image/end.png");

	sf::Sprite sBackground(t1), sDirectPipe(t2), sLPipe(t3), sPlusPipe(t4);
	sf::Sprite sBegin(begin), sEnd(end);
	/*
	sDirectPipe.setOrigin(27, 27);
	sLPipe.setOrigin(27, 27);
	sPlusPipe.setOrigin(27, 27);
	*/
	sBegin.setPosition(35, 82);
	sEnd.setPosition(363, 298);

	array <array<Pipe*, length>, length> puzzle;
	DirectPipe directPipe;
	HorizonalDirectPipe horizonalDirectPipe;
	LPipe lPipe;
	LPipe2 lPipe2;
	LPipe3 lPipe3;
	LPipe4 lPipe4;
	PlusPipe plusPipe;

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < puzzle[i].size(); j++)
		{
			int randomNumber = rand() % 7;

			if (0 == randomNumber)
			{
				puzzle[i][j] = &directPipe;
			}
			if (1 == randomNumber)
			{
				puzzle[i][j] = &horizonalDirectPipe;
			}
			if (2 == randomNumber)
			{
				puzzle[i][j] = &lPipe;
			}
			if (3 == randomNumber)
			{
				puzzle[i][j] = &lPipe2;
			}
			if (4 == randomNumber)
			{
				puzzle[i][j] = &lPipe3;
			}
			if (5 == randomNumber)
			{
				puzzle[i][j] = &lPipe4;
			}
			if (6 == randomNumber)
			{
				puzzle[i][j] = &plusPipe;
			}
		}
	}
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::MouseButtonPressed)
				if (event.key.code == sf::Mouse::Left)
				{
					sf::Vector2i pos = sf::Mouse::getPosition(window) + sf::Vector2i(tileSize / 2, tileSize / 2) - sf::Vector2i(offset);
					pos /= tileSize;
					puzzle[pos.x][pos.y]->setOrientation((puzzle[pos.x][pos.y]->getOrientation()) + 1);

					/*
					if (isOut(pos)) continue;
					cell(pos).orientation++;
					cell(pos).rotate();

					for (int i = 0; i < N; i++)
						for (int j = 0; j < N; j++)
							grid[j][i].on = 0;

					drop(servPos);
					*/
				}
		}

		window.clear();
		window.draw(sBackground);
		window.draw(sBegin);
		window.draw(sEnd);

		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < length; j++)
			{
				puzzle[i][j]->draw(window, i, j, tileSize);

				/*pipe& p = grid[j][i];

				int kind = p.dirs.size();
				if (kind == 2 && p.dirs[0] == -p.dirs[1]) kind = 0;

				p.angle += 5;
				if (p.angle > p.orientation * 90) p.angle = p.orientation * 90;

				sPipe.setTextureRect(IntRect(ts * kind, 0, ts, ts));
				sPipe.setRotation(p.angle);
				sPipe.setPosition(j * ts, i * ts); sPipe.move(offset);
				app.draw(sPipe);

				if (kind == 1)
				{
					if (p.on) sComp.setTextureRect(IntRect(53, 0, 36, 36));
					else sComp.setTextureRect(IntRect(0, 0, 36, 36));
					sComp.setPosition(j * ts, i * ts); sComp.move(offset);
					app.draw(sComp);
				}*/


			}

		}

		window.display();

	}
	return 0;
}