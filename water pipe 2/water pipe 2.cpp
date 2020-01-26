#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <array>
#include <sstream>

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
	sf::RenderWindow window(sf::VideoMode(445, 448), "Water Pipe Game", sf::Style::Default);

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
			else if (1 == randomNumber)
			{
				puzzle[i][j] = &horizonalDirectPipe;
			}
			else if(2 == randomNumber)
			{
				puzzle[i][j] = &lPipe;
			}
			else if(3 == randomNumber)
			{
				puzzle[i][j] = &lPipe2;
			}
			else if(4 == randomNumber)
			{
				puzzle[i][j] = &lPipe3;
			}
			else if(5 == randomNumber)
			{
				puzzle[i][j] = &lPipe4;
			}
			else
			{
				puzzle[i][j] = &plusPipe;
			}
		}
	}

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
	//scoreText.setPosition(0, 0);
/////////////////////////////////////////////////////////////////////////////////////////
	//variable to control time itself
	sf::Clock clock;

	//Time bar
	sf::RectangleShape timeBar(sf::Vector2f(400, 80));
	//sf::RectangleShape rectangle(sf::Vector2f(400, 80));
	//rectangle.setPosition((445 / 2.0f) - 400 / 2.0f, 448);
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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return))
		{
			paused = false;
			//Reset the time and the time score
			score = 0;
			//timeRemaining = 5;
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
			timeBar.setSize(sf::Vector2f(timeBarWidthPerSecond* timeRemaining, timeBarHeight));
			
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
	return 0;
}
