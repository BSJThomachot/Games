#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Game.h"

using namespace helicopter;

int main()
{
	// SFML window
	sf::RenderWindow window(sf::VideoMode(800,600), "Helicopter");

	// texture for Player (a ball for now
	sf::Texture textureBall;
    if (!textureBall.loadFromFile("Images/Ball.png"))
	{
		return EXIT_SUCCESS;
	}

	Game * CopterGame = new Game();
	CopterGame->SetUp(textureBall);

	bool UpPressed = false;

	sf::Clock clock;
	while (window.isOpen())
	{	
		sf::Time dt = clock.restart();
		sf::Event event;
		while (window.pollEvent(event))
		{	
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			// check key press
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Up)
				{
					UpPressed = true;
				}
			}
			// check key release
			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Up)
				{
					UpPressed = false;
				}
			}
		}

		CopterGame->Update(dt.asSeconds(),UpPressed);
		window.clear(sf::Color(0,0,0,255));
		CopterGame->Draw(&window);
		window.display();
	}

	delete CopterGame;

	return EXIT_SUCCESS;
}