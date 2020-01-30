#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <array>
#include <sstream>
#include <typeinfo>
#include <string>

#include "DirectPipe.h"
#include "HorizonalDirectPipe.h"
#include "LPipe.h"
#include "LPipe2.h"
#include "LPipe3.h"
#include "LPipe4.h"
#include "PlusPipe.h"

using namespace std;

void pathMaker();

const int length = 5;
int tileSize = 54;
//sf::Vector2f offset(120, 110);
array <array<Pipe*, length>, length> puzzle;

void pathMaker();

int main()
{
	sf::RenderWindow window(sf::VideoMode(445, 445), "Water Pipe Game", sf::Style::Default);

	srand(static_cast<unsigned int>(time(0)));

	sf::Texture t1, begin, end;
	
	//sf::Texture t2, t3, t4,;
	
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

	sf::Sprite sBackground(t1);
	//sf::Sprite sDirectPipe(t2), sLPipe(t3), sPlusPipe(t4);
	sf::Sprite sBegin(begin), sEnd(end);
	
	sBegin.setPosition(35, 82);    
	sEnd.setPosition(363, 298);

	/*
	DirectPipe directPipe;
	HorizonalDirectPipe horizonalDirectPipe;
	LPipe lPipe;
	LPipe2 lPipe2;
	LPipe3 lPipe3;
	LPipe4 lPipe4;
	PlusPipe plusPipe;
	*/
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < puzzle[i].size(); j++)
		{
			int randomNumber = rand() % 7;

			if (0 == randomNumber)
			{
				puzzle[i][j] = new DirectPipe();
				puzzle[i][j]->startPipe[0] = 1;
				puzzle[i][j]->startPipe[1] = 1;
				puzzle[i][j]->endPipe[0] = 1;
				puzzle[i][j]->endPipe[1] = 1;
			}
			else if (1 == randomNumber)
			{
				puzzle[i][j] = new HorizonalDirectPipe;
				puzzle[i][j]->startPipe[2] = 1;
				puzzle[i][j]->startPipe[3] = 1;
				puzzle[i][j]->endPipe[2] = 1;
				puzzle[i][j]->endPipe[3] = 1;
			}
			else if(2 == randomNumber)
			{
				puzzle[i][j] = new LPipe;
				puzzle[i][j]->startPipe[1] = 1;
				puzzle[i][j]->startPipe[3] = 1;
				puzzle[i][j]->endPipe[1] = 1;
				puzzle[i][j]->endPipe[3] = 1;
			}
			else if(3 == randomNumber)
			{
				puzzle[i][j] = new LPipe2;
				puzzle[i][j]->startPipe[1] = 1;
				puzzle[i][j]->startPipe[2] = 1;
				puzzle[i][j]->endPipe[1] = 1;
				puzzle[i][j]->endPipe[2] = 1;
			}
			else if(4 == randomNumber)
			{
				puzzle[i][j] = new LPipe3;
				puzzle[i][j]->startPipe[0] = 1;
				puzzle[i][j]->startPipe[2] = 1;
				puzzle[i][j]->endPipe[0] = 1;
				puzzle[i][j]->endPipe[2] = 1;
			}
			else if(5 == randomNumber)
			{
				puzzle[i][j] = new LPipe4;
				puzzle[i][j]->startPipe[0] = 1;
				puzzle[i][j]->startPipe[3] = 1;
				puzzle[i][j]->endPipe[0] = 1;
				puzzle[i][j]->endPipe[3] = 1;
			}
			else
			{
				puzzle[i][j] = new PlusPipe;
				puzzle[i][j]->startPipe[0] = 1;
				puzzle[i][j]->startPipe[1] = 1;
				puzzle[i][j]->startPipe[2] = 1;
				puzzle[i][j]->startPipe[3] = 1;
				puzzle[i][j]->endPipe[0] = 1;
				puzzle[i][j]->endPipe[1] = 1;
				puzzle[i][j]->endPipe[2] = 1;
				puzzle[i][j]->endPipe[3] = 1;
			}
		}
	}
//////////////////////////////////////////////////////////////////////////////////////////
	pathMaker();
//////////////////////////////////////////////////////////////////////////////////////////
	bool paused = true;
//////////////////////////////////////////////////////////////////////////////////////	
	int score = 0;

	sf::Text messageText, scoreText;
	sf::Font font;
	if (!font.loadFromFile("font/VtksDracena.ttf"))
		cout << "ERROR,Font not open" << endl;

	font.loadFromFile("font/VtksDracena.ttf");
	
	messageText.setFont(font);
	scoreText.setFont(font);

	messageText.setString("Press Enter to start");
	scoreText.setString("Score ");

	messageText.setCharacterSize(50);
	scoreText.setCharacterSize(30);

	messageText.setFillColor(sf::Color::Blue);
	scoreText.setFillColor(sf::Color::Blue);

	//Position the text
	sf::FloatRect textRect = messageText.getLocalBounds();
	messageText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	messageText.setPosition(445 / 2.0f, 448 / 2.0f);
	scoreText.setPosition(0, 0);
/////////////////////////////////////////////////////////////////////////////////////////
	//variable to control time itself
	sf::Clock clock;

	//Time bar
	sf::RectangleShape timeBar(sf::Vector2f(400, 80));
	float timeBarStartWidth = 445;
	float timeBarHeight = 3;
	timeBar.setSize(sf::Vector2f(timeBarStartWidth, timeBarHeight));
	timeBar.setFillColor(sf::Color::Blue);
	//timeBar.setPosition((445 / 2.0f) - timeBarStartWidth / 2.0f, 448);
	timeBar.setPosition(0,0);

	sf::Time gameTimeTotal;
	float timeRemaining = 6.0f;
	float timeBarWidthPerSecond = timeBarStartWidth / timeRemaining;  
	
////////////////////////////////////////////////////////////////////////////////////////////
	//add sound effect
	sf::Music gameMusic;
	gameMusic.openFromFile("sound/game.wav");
	gameMusic.setVolume(50);
	gameMusic.play();
	gameMusic.setLoop(true);

	sf::Music gameOverMusic;
	gameOverMusic.openFromFile("sound/gameOver.wav");
	gameOverMusic.setVolume(50);
	
///////////////////////////////////////////////////////////////////////////////////////////
	sf::Vector2f offset(120, 110);


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
					pos.x /= tileSize;
					pos.y /= tileSize;
					//cout << "(x , y) " << pos.x << "  " << pos.y << endl;
					if (pos.x >= 0 && pos.y >= 0 && pos.x<5 && pos.y<5)
					{
						puzzle[pos.y][pos.x]->setOrientation((puzzle[pos.y][pos.x]->getOrientation()) + 1);
						
						if (!strcmp((typeid(*(puzzle[pos.y][pos.x])).name()) , "class DirectPipe"))
						{
							puzzle[pos.y][pos.x]->startPipe[0] = 0;
							puzzle[pos.y][pos.x]->startPipe[1] = 0;
							puzzle[pos.y][pos.x]->startPipe[2] = 1;
							puzzle[pos.y][pos.x]->startPipe[3] = 1;
							puzzle[pos.y][pos.x]->endPipe[0] = 0;
							puzzle[pos.y][pos.x]->endPipe[1] = 0;
							puzzle[pos.y][pos.x]->endPipe[2] = 1;
							puzzle[pos.y][pos.x]->endPipe[3] = 1;
						}
						if (!strcmp((typeid(*(puzzle[pos.y][pos.x])).name()), "class HorizonalDirectPipe"))
						{
							puzzle[pos.y][pos.x]->startPipe[0] = 1;
							puzzle[pos.y][pos.x]->startPipe[1] = 1;
							puzzle[pos.y][pos.x]->startPipe[2] = 0;
							puzzle[pos.y][pos.x]->startPipe[3] = 0;
							puzzle[pos.y][pos.x]->endPipe[0] = 1;
							puzzle[pos.y][pos.x]->endPipe[1] = 1;
							puzzle[pos.y][pos.x]->endPipe[2] = 0;
							puzzle[pos.y][pos.x]->endPipe[3] = 0;

						}
						if (!strcmp((typeid(*(puzzle[pos.y][pos.x])).name()), "class LPipe"))
						{
							puzzle[pos.y][pos.x]->startPipe[0] = 0;
							puzzle[pos.y][pos.x]->startPipe[1] = 1;
							puzzle[pos.y][pos.x]->startPipe[2] = 1;
							puzzle[pos.y][pos.x]->startPipe[3] = 0;
							puzzle[pos.y][pos.x]->endPipe[0] = 0;
							puzzle[pos.y][pos.x]->endPipe[1] = 1;
							puzzle[pos.y][pos.x]->endPipe[2] = 1;
							puzzle[pos.y][pos.x]->endPipe[3] = 0;

						}
						if (!strcmp((typeid(*(puzzle[pos.y][pos.x])).name()), "class LPipe2"))
						{
							puzzle[pos.y][pos.x]->startPipe[0] = 1;
							puzzle[pos.y][pos.x]->startPipe[1] = 0;
							puzzle[pos.y][pos.x]->startPipe[2] = 1;
							puzzle[pos.y][pos.x]->startPipe[3] = 0;
							puzzle[pos.y][pos.x]->endPipe[0] = 1;
							puzzle[pos.y][pos.x]->endPipe[1] = 0;
							puzzle[pos.y][pos.x]->endPipe[2] = 1;
							puzzle[pos.y][pos.x]->endPipe[3] = 0;

						}
						if (!strcmp((typeid(*(puzzle[pos.y][pos.x])).name()), "class LPipe3"))
						{
							puzzle[pos.y][pos.x]->startPipe[0] = 1;
							puzzle[pos.y][pos.x]->startPipe[1] = 0;
							puzzle[pos.y][pos.x]->startPipe[2] = 0;
							puzzle[pos.y][pos.x]->startPipe[3] = 1;
							puzzle[pos.y][pos.x]->endPipe[0] = 1;
							puzzle[pos.y][pos.x]->endPipe[1] = 0;
							puzzle[pos.y][pos.x]->endPipe[2] = 0;
							puzzle[pos.y][pos.x]->endPipe[3] = 1;
						}
						if (!strcmp((typeid(*(puzzle[pos.y][pos.x])).name()), "class LPipe4"))
						{
							puzzle[pos.y][pos.x]->startPipe[0] = 0;
							puzzle[pos.y][pos.x]->startPipe[1] = 1;
							puzzle[pos.y][pos.x]->startPipe[2] = 0;
							puzzle[pos.y][pos.x]->startPipe[3] = 1;
							puzzle[pos.y][pos.x]->endPipe[0] = 0;
							puzzle[pos.y][pos.x]->endPipe[1] = 1;
							puzzle[pos.y][pos.x]->endPipe[2] = 0;
							puzzle[pos.y][pos.x]->endPipe[3] = 1;
						}
						if (!strcmp((typeid(*(puzzle[pos.y][pos.x])).name()), "class PlusPipe"))
						{
							puzzle[pos.y][pos.x]->startPipe[0] = 1;
							puzzle[pos.y][pos.x]->startPipe[1] = 1;
							puzzle[pos.y][pos.x]->startPipe[2] = 1;
							puzzle[pos.y][pos.x]->startPipe[3] = 1;
							puzzle[pos.y][pos.x]->endPipe[0] = 1;
							puzzle[pos.y][pos.x]->endPipe[1] = 1;
							puzzle[pos.y][pos.x]->endPipe[2] = 1;
							puzzle[pos.y][pos.x]->endPipe[3] = 1;
						}

					}
					

				}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return))
		{
			paused = false;
			//Reset the time and the time score
			score = 0;
			//timeRemaining = 6;
		}

		if (!paused)
		{

			if (timeRemaining <= 3.0f)
			{
				timeBar.setFillColor(sf::Color::Red);
			}

			sf::Time dt = clock.restart();  //Measure time

			//Subtractfrom the amount of time remaining
			timeRemaining -= dt.asSeconds() * 0.03f;
			//size up the time bar
			timeBar.setSize(sf::Vector2f(timeBarWidthPerSecond * timeRemaining, timeBarHeight));

			if (timeRemaining <= 0.0f)
			{
				//pause the game
				paused = true;

				//change the message shown to the player
				messageText.setString("Out of time");

				//Reposition the text based on its new size

				sf::FloatRect textRect = messageText.getLocalBounds();
				messageText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
				messageText.setPosition(445 / 2.0f, 448 / 2.0f);
				gameMusic.pause();
				gameOverMusic.play();
			}



			window.clear();
			window.draw(sBackground);
			window.draw(scoreText);
			window.draw(sBegin);
			window.draw(sEnd);
			window.draw(timeBar);

			for (int i = 0; i < length; i++)
			{
				for (int j = 0; j < length; j++)
				{
					puzzle[i][j]->draw(window, i, j, tileSize);
				}
			}

			stringstream ss;
			ss << "Score " << score;
			scoreText.setString(ss.str());

		}// End of if(!paused)
		if (paused)
		{
			window.draw(sBackground);
			window.draw(messageText);
		}
		window.display();
	
	}
	for(size_t i=0 ; i <length ; i++)
		for(size_t j=0 ; j < length ; j++)
			delete puzzle[i][j];           

			
	return 0;
}


void pathMaker()
{
	srand(static_cast<unsigned int>(time(0)));
	int randomPath = (rand() % 2) + 1;
	if ((!strcmp((typeid(*(puzzle[0][0])).name()), "class DirectPipe")) || (!strcmp((typeid(*(puzzle[0][0])).name()), "class HorizonalDirectPipe")))
	{
		if ((!strcmp((typeid(*(puzzle[4][4])).name()), "class LPipe")) || (!strcmp((typeid(*(puzzle[4][4])).name()), "class LPipe2")) ||
			(!strcmp((typeid(*(puzzle[4][4])).name()), "class LPipe3")) || (!strcmp((typeid(*(puzzle[4][4])).name()), "class LPipe4")))
		{
			if (1 == randomPath)
			{
				delete puzzle[0][1]; puzzle[0][1] = new DirectPipe;
				delete puzzle[0][2]; puzzle[0][2] = new LPipe;
				delete puzzle[1][2]; puzzle[1][2] = new PlusPipe;
				delete puzzle[2][2]; puzzle[2][2] = new LPipe2;
				delete puzzle[2][3]; puzzle[2][3] = new LPipe4;
				delete puzzle[1][3]; puzzle[1][3] = new LPipe3;
				delete puzzle[1][1]; puzzle[1][1] = new LPipe4;
				delete puzzle[2][1]; puzzle[2][1] = new DirectPipe;
				delete puzzle[3][1]; puzzle[3][1] = new LPipe3;
				delete puzzle[3][2]; puzzle[3][2] = new DirectPipe;
				delete puzzle[3][3]; puzzle[3][3] = new HorizonalDirectPipe;
				delete puzzle[3][4]; puzzle[3][4] = new LPipe3;
			}
			if (2 == randomPath)
			{
				delete puzzle[0][1]; puzzle[0][1] = new LPipe;
				delete puzzle[1][1]; puzzle[1][1] = new LPipe3;
				delete puzzle[1][2]; puzzle[1][2] = new LPipe4;
				delete puzzle[2][2]; puzzle[2][2] = new LPipe2;
				delete puzzle[2][3]; puzzle[2][3] = new LPipe4;
				delete puzzle[3][3]; puzzle[3][3] = new LPipe3;
				delete puzzle[3][4]; puzzle[3][4] = new LPipe;
			}
		}
	}
	if ((!strcmp((typeid(*(puzzle[0][0])).name()), "class DirectPipe")) || (!strcmp((typeid(*(puzzle[0][0])).name()), "class HorizonalDirectPipe")))
	{
		if ((!strcmp((typeid(*(puzzle[4][4])).name()), "class DirectPipe")) || (!strcmp((typeid(*(puzzle[4][4])).name()), "class HorizonalDirectPipe")))
		{
			if (1 == randomPath)
			{
				delete puzzle[0][1]; puzzle[0][1] = new LPipe;
				delete puzzle[1][1]; puzzle[1][1] = new HorizonalDirectPipe;
				delete puzzle[2][1]; puzzle[2][1] = new PlusPipe;
				delete puzzle[3][1]; puzzle[3][1] = new LPipe2;
				delete puzzle[3][0]; puzzle[3][0] = new LPipe3;
				delete puzzle[4][0]; puzzle[4][0] = new LPipe;
				delete puzzle[4][1]; puzzle[4][1] = new DirectPipe;
				delete puzzle[4][2]; puzzle[4][2] = new DirectPipe;
				delete puzzle[4][3]; puzzle[4][3] = new HorizonalDirectPipe;
			}
			if (2 == randomPath)
			{
				delete puzzle[0][1]; puzzle[0][1] = new DirectPipe;
				delete puzzle[0][2]; puzzle[0][2] = new DirectPipe;
				delete puzzle[0][3]; puzzle[0][3] = new LPipe4;
				delete puzzle[1][3]; puzzle[1][3] = new LPipe2;
				delete puzzle[1][4]; puzzle[1][4] = new LPipe;
				delete puzzle[2][4]; puzzle[2][4] = new HorizonalDirectPipe;
				delete puzzle[3][4]; puzzle[3][4] = new LPipe;
				delete puzzle[3][3]; puzzle[3][3] = new LPipe4;
				delete puzzle[4][3]; puzzle[4][3] = new LPipe;
			}
		}
	}
	if ((!strcmp((typeid(*(puzzle[0][0])).name()), "class DirectPipe")) || (!strcmp((typeid(*(puzzle[0][0])).name()), "class HorizonalDirectPipe")))
	{
		if ((!strcmp((typeid(*(puzzle[4][4])).name()), "class PlusPipe")))
		{
			if (1 == randomPath)
			{
				delete puzzle[0][1]; puzzle[0][1] = new LPipe;
				delete puzzle[1][1]; puzzle[1][1] = new LPipe2;
				delete puzzle[1][0]; puzzle[1][0] = new LPipe4;
				delete puzzle[2][0]; puzzle[2][0] = new LPipe2;
				delete puzzle[2][1]; puzzle[2][1] = new PlusPipe;
				delete puzzle[2][2]; puzzle[2][2] = new LPipe;
				delete puzzle[1][2]; puzzle[1][2] = new LPipe4;
				delete puzzle[1][3]; puzzle[1][3] = new LPipe3;
				delete puzzle[2][3]; puzzle[2][3] = new PlusPipe;
				delete puzzle[3][3]; puzzle[3][3] = new DirectPipe;
				delete puzzle[4][3]; puzzle[4][3] = new LPipe;
			}
			if (2 == randomPath)
			{
				delete puzzle[0][1]; puzzle[0][1] = new LPipe;
				delete puzzle[1][1]; puzzle[1][1] = new PlusPipe;
				delete puzzle[2][1]; puzzle[2][1] = new PlusPipe;
				delete puzzle[3][1]; puzzle[3][1] = new LPipe;
				delete puzzle[3][2]; puzzle[3][2] = new LPipe4;
				delete puzzle[4][2]; puzzle[4][2] = new HorizonalDirectPipe;
				delete puzzle[4][3]; puzzle[4][3] = new DirectPipe;
			}
		}
	}
	if ((!strcmp((typeid(*(puzzle[0][0])).name()), "class LPipe")) || (!strcmp((typeid(*(puzzle[0][0])).name()), "class LPipe2")) ||
		(!strcmp((typeid(*(puzzle[0][0])).name()), "class LPipe3")) || (!strcmp((typeid(*(puzzle[0][0])).name()), "class LPipe4")))
	{
		if ((!strcmp((typeid(*(puzzle[4][4])).name()), "class PlusPipe")))
		{
			cout << "L      +" << endl;
			if (1 == randomPath)
			{
				delete puzzle[1][0]; puzzle[1][0] = new HorizonalDirectPipe;
				delete puzzle[2][0]; puzzle[2][0] = new LPipe;
				delete puzzle[2][1]; puzzle[2][1] = new DirectPipe;
				delete puzzle[2][2]; puzzle[2][2] = new DirectPipe;
				delete puzzle[2][3]; puzzle[2][3] = new LPipe4;
				delete puzzle[3][3]; puzzle[3][3] = new LPipe2;
				delete puzzle[3][2]; puzzle[3][2] = new LPipe4;
				delete puzzle[4][2]; puzzle[4][2] = new LPipe3;
				delete puzzle[4][3]; puzzle[4][3] = new DirectPipe;
			}
			if (2 == randomPath)
			{
				delete puzzle[1][0]; puzzle[1][0] = new LPipe;
				delete puzzle[1][1]; puzzle[1][1] = new LPipe4;
				delete puzzle[2][0]; puzzle[2][0] = new LPipe3;
				delete puzzle[2][1]; puzzle[2][1] = new LPipe;
				delete puzzle[3][0]; puzzle[3][0] = new LPipe3;
				delete puzzle[3][1]; puzzle[3][1] = new LPipe2;
				delete puzzle[4][1]; puzzle[4][1] = new LPipe;
				delete puzzle[4][2]; puzzle[4][2] = new LPipe2;
				delete puzzle[3][2]; puzzle[3][2] = new LPipe2;
				delete puzzle[3][3]; puzzle[3][3] = new LPipe4;
				delete puzzle[4][3]; puzzle[4][3] = new LPipe2;
			}
		}
	}
	if ((!strcmp((typeid(*(puzzle[0][0])).name()), "class LPipe")) || (!strcmp((typeid(*(puzzle[0][0])).name()), "class LPipe2")) ||
		(!strcmp((typeid(*(puzzle[0][0])).name()), "class LPipe3")) || (!strcmp((typeid(*(puzzle[0][0])).name()), "class LPipe4")))
	{
		if ((!strcmp((typeid(*(puzzle[4][4])).name()), "class DirectPipe")) || (!strcmp((typeid(*(puzzle[4][4])).name()), "class HorizonalDirectPipe")))
		{
			cout << "L      -" << endl;
			if (1 == randomPath)
			{
				delete puzzle[1][0]; puzzle[1][0] = new LPipe;
				delete puzzle[1][1]; puzzle[1][1] = new LPipe2;
				delete puzzle[0][1]; puzzle[0][1] = new LPipe4;
				delete puzzle[0][2]; puzzle[0][2] = new LPipe3;
				delete puzzle[1][2]; puzzle[1][2] = new PlusPipe;
				delete puzzle[2][2]; puzzle[2][2] = new LPipe2;
				delete puzzle[2][3]; puzzle[2][3] = new LPipe4;
				delete puzzle[3][3]; puzzle[3][3] = new DirectPipe;
				delete puzzle[4][3]; puzzle[4][3] = new LPipe;
			}
			if (2 == randomPath)
			{
				delete puzzle[1][0]; puzzle[1][0] = new LPipe;
				delete puzzle[1][1]; puzzle[1][1] = new LPipe4;
				delete puzzle[2][0]; puzzle[2][0] = new LPipe3;
				delete puzzle[2][1]; puzzle[2][1] = new LPipe;
				delete puzzle[3][0]; puzzle[3][0] = new LPipe3;
				delete puzzle[3][1]; puzzle[3][1] = new DirectPipe;
				delete puzzle[3][2]; puzzle[3][2] = new PlusPipe;
				delete puzzle[3][3]; puzzle[3][3] = new LPipe3;
				delete puzzle[4][3]; puzzle[4][3] = new LPipe;
			}
		}
	}
	if ((!strcmp((typeid(*(puzzle[0][0])).name()), "class LPipe")) || (!strcmp((typeid(*(puzzle[0][0])).name()), "class LPipe2")) ||
		(!strcmp((typeid(*(puzzle[0][0])).name()), "class LPipe3")) || (!strcmp((typeid(*(puzzle[0][0])).name()), "class LPipe4")))
	{
		if ((!strcmp((typeid(*(puzzle[4][4])).name()), "class LPipe")) || (!strcmp((typeid(*(puzzle[4][4])).name()), "class LPipe2")) ||
			(!strcmp((typeid(*(puzzle[4][4])).name()), "class LPipe3")) || (!strcmp((typeid(*(puzzle[4][4])).name()), "class LPipe4")))
		{
			cout << "L      L" << endl;
			if (1 == randomPath)
			{
				delete puzzle[1][0]; puzzle[1][0] = new LPipe;
				delete puzzle[1][1]; puzzle[1][1] = new LPipe2;
				delete puzzle[0][1]; puzzle[0][1] = new LPipe4;
				delete puzzle[0][2]; puzzle[0][2] = new LPipe3;
				delete puzzle[1][2]; puzzle[1][2] = new PlusPipe;
				delete puzzle[2][2]; puzzle[2][2] = new LPipe2;
				delete puzzle[2][3]; puzzle[2][3] = new PlusPipe;
				delete puzzle[2][4]; puzzle[2][4] = new LPipe4;
				delete puzzle[3][4]; puzzle[3][4] = new HorizonalDirectPipe;
			}
			if (2 == randomPath)
			{
				delete puzzle[1][0]; puzzle[1][0] = new LPipe;
				delete puzzle[1][1]; puzzle[1][1] = new HorizonalDirectPipe;
				delete puzzle[1][2]; puzzle[1][2] = new PlusPipe;
				delete puzzle[1][3]; puzzle[1][3] = new LPipe2;
				delete puzzle[0][3]; puzzle[0][3] = new LPipe4;
				delete puzzle[0][4]; puzzle[0][4] = new LPipe3;
				delete puzzle[1][4]; puzzle[1][4] = new HorizonalDirectPipe;
				delete puzzle[2][4]; puzzle[2][4] = new DirectPipe;
				delete puzzle[3][4]; puzzle[3][4] = new PlusPipe;
			}
			/////////////////////////////////////////////////////////////////////////////////
		}
	}
	if ((!strcmp((typeid(*(puzzle[0][0])).name()), "class PlusPipe")))
	{
		if ((!strcmp((typeid(*(puzzle[4][4])).name()), "class PlusPipe")))
		{
			cout << "+      +" << endl;
			if (1 == randomPath)
			{
				delete puzzle[0][1]; puzzle[0][1] = new DirectPipe;
				delete puzzle[0][2]; puzzle[0][2] = new HorizonalDirectPipe;
				delete puzzle[0][3]; puzzle[0][3] = new LPipe;
				delete puzzle[1][3]; puzzle[1][3] = new PlusPipe;
				delete puzzle[2][3]; puzzle[2][3] = new PlusPipe;
				delete puzzle[3][3]; puzzle[3][3] = new HorizonalDirectPipe;
				delete puzzle[4][3]; puzzle[4][3] = new LPipe3;
			}
			if (2 == randomPath)
			{
				delete puzzle[1][0]; puzzle[1][0] = new LPipe;
				delete puzzle[1][1]; puzzle[1][1] = new LPipe3;
				delete puzzle[2][1]; puzzle[2][1] = new LPipe2;
				delete puzzle[2][2]; puzzle[2][2] = new LPipe4;
				delete puzzle[1][2]; puzzle[1][2] = new PlusPipe;
				delete puzzle[0][2]; puzzle[0][2] = new LPipe2;
				delete puzzle[0][3]; puzzle[0][3] = new LPipe3;
				delete puzzle[0][4]; puzzle[0][4] = new LPipe4;
				delete puzzle[1][4]; puzzle[1][4] = new LPipe;
				delete puzzle[1][3]; puzzle[1][3] = new LPipe3;
				delete puzzle[2][3]; puzzle[2][3] = new PlusPipe;
				delete puzzle[3][3]; puzzle[3][3] = new HorizonalDirectPipe;
				delete puzzle[4][3]; puzzle[4][3] = new LPipe;
				
			}
		}
	}
	if ((!strcmp((typeid(*(puzzle[0][0])).name()), "class PlusPipe")))
	{
		if ((!strcmp((typeid(*(puzzle[4][4])).name()), "class DirectPipe")) || (!strcmp((typeid(*(puzzle[4][4])).name()), "class HorizonalDirectPipe")))
		{
			cout << "+      -" << endl;
			if (1== randomPath)
			{
				delete puzzle[0][1]; puzzle[0][1] = new DirectPipe;
				delete puzzle[0][2]; puzzle[0][2] = new HorizonalDirectPipe;
				delete puzzle[0][3]; puzzle[0][3] = new LPipe;
				delete puzzle[1][3]; puzzle[1][3] = new PlusPipe;
				delete puzzle[2][3]; puzzle[2][3] = new LPipe2;
				delete puzzle[2][2]; puzzle[2][2] = new PlusPipe;
				delete puzzle[2][1]; puzzle[2][1] = new LPipe;
				delete puzzle[3][1]; puzzle[3][1] = new PlusPipe;
				delete puzzle[4][1]; puzzle[4][1] = new LPipe3;
				delete puzzle[4][2]; puzzle[4][2] = new HorizonalDirectPipe;
				delete puzzle[4][3]; puzzle[4][3] = new DirectPipe;
			}
			if (2 == randomPath)
			{
				delete puzzle[1][0]; puzzle[1][0] = new LPipe;
				delete puzzle[1][1]; puzzle[1][1] = new LPipe3;
				delete puzzle[2][1]; puzzle[2][1] = new LPipe2;
				delete puzzle[2][2]; puzzle[2][2] = new PlusPipe;
				delete puzzle[2][3]; puzzle[2][3] = new LPipe;
				delete puzzle[3][3]; puzzle[3][3] = new HorizonalDirectPipe;
				delete puzzle[4][3]; puzzle[4][3] = new LPipe;
			}
		}
	}
	if ((!strcmp((typeid(*(puzzle[0][0])).name()), "class PlusPipe")))
	{
		if ((!strcmp((typeid(*(puzzle[4][4])).name()), "class LPipe")) || (!strcmp((typeid(*(puzzle[4][4])).name()), "class LPipe2")) ||
			(!strcmp((typeid(*(puzzle[4][4])).name()), "class LPipe3")) || (!strcmp((typeid(*(puzzle[4][4])).name()), "class LPipe4")))
		{
			cout << "+      L" << endl;
			if (1 == randomPath)
			{
				delete puzzle[0][1]; puzzle[0][1] = new LPipe;
				delete puzzle[1][1]; puzzle[1][1] = new LPipe2;
				delete puzzle[1][2]; puzzle[1][2] = new LPipe;
				delete puzzle[2][2]; puzzle[2][2] = new LPipe4;
				delete puzzle[2][1]; puzzle[2][1] = new LPipe2;
				delete puzzle[3][1]; puzzle[3][1] = new PlusPipe;
				delete puzzle[4][1]; puzzle[4][1] = new LPipe;
				delete puzzle[4][2]; puzzle[4][2] = new DirectPipe;
				delete puzzle[4][3]; puzzle[4][3] = new LPipe4;
				delete puzzle[3][3]; puzzle[3][3] = new LPipe2;
				delete puzzle[3][4]; puzzle[3][4] = new LPipe3;
			}
			if (2 == randomPath)
			{
				delete puzzle[0][1]; puzzle[0][1] = new DirectPipe;
				delete puzzle[0][2]; puzzle[0][2] = new LPipe;
				delete puzzle[1][2]; puzzle[1][2] = new PlusPipe;
				delete puzzle[2][2]; puzzle[2][2] = new HorizonalDirectPipe;
				delete puzzle[3][2]; puzzle[3][2] = new LPipe4;
				delete puzzle[3][1]; puzzle[3][1] = new LPipe3;
				delete puzzle[4][1]; puzzle[4][1] = new LPipe;
				delete puzzle[4][2]; puzzle[4][2] = new DirectPipe;
				delete puzzle[4][3]; puzzle[4][3] = new LPipe4;
				delete puzzle[3][3]; puzzle[3][3] = new HorizonalDirectPipe;
				delete puzzle[2][3]; puzzle[2][3] = new PlusPipe;
				delete puzzle[1][3]; puzzle[1][3] = new LPipe2;
				delete puzzle[1][4]; puzzle[1][4] = new LPipe4;
				delete puzzle[2][4]; puzzle[2][4] = new DirectPipe;
				delete puzzle[3][4]; puzzle[3][4] = new HorizonalDirectPipe;
			}
		}
	}
}