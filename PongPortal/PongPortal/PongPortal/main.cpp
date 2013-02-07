#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Misc.h"
#include "Player.h"
#include "Ball.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT), "Pong Portal");

	// loading images
	sf::Texture texture;
    texture.loadFromFile("Images/Pad.png"); // pad image
	sf::Texture textureBall;
    textureBall.loadFromFile("Images/Ball.png"); // ball image

	// The players
	Player * player1 = new Player(texture,0,SCREEN_HEIGHT/2 - 64,32,128);
	Player * player2 = new Player(texture,SCREEN_WIDTH - 32,SCREEN_HEIGHT/2 - 64,32,128);
	Ball * ball = new Ball(textureBall,SCREEN_WIDTH/2,SCREEN_HEIGHT/2,16);


	bool bUpPressed		= false;
	bool bDownPressed   = false;
	bool bWPressed		= false;
	bool bSPressed		= false;	

	// The Game's clock
	sf::Clock clock;
	while (window.isOpen())
	{
		// get delta time
		sf::Time dt = clock.restart();
		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Up)
				{
					bUpPressed = true;
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					bDownPressed = true;
				}
				if (event.key.code == sf::Keyboard::W)
				{
					bWPressed = true;
				}
				if (event.key.code == sf::Keyboard::S)
				{
					bSPressed = true;
				}
			}
			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Up)
				{
					bUpPressed = false;
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					bDownPressed = false;
				}
				if (event.key.code == sf::Keyboard::W)
				{
					bWPressed = false;
				}
				if (event.key.code == sf::Keyboard::S)
				{
					bSPressed = false;
				}
			}
		}

		// update players
		player1->update(bUpPressed,bDownPressed,dt.asSeconds());
		player2->update(bWPressed,bSPressed,dt.asSeconds());
		ball->update(player1,player2,dt.asSeconds());


		// clear window
		window.clear(sf::Color(0,0,0,255));
		player1->draw(&window);
		player2->draw(&window);
		ball->draw(&window);
		window.display();
	}

	// clean up
	delete ball;
	delete player2;
	delete player1;

	return EXIT_SUCCESS;
}