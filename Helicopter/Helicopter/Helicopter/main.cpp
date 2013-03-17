#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Game.h"

using namespace helicopter;

int main()
{
	sf::RenderWindow window(sf::VideoMode((int)SCREEN_WIDTH,(int)SCREEN_HEIGHT), "Helicopter");

	Game * CopterGame = new Game();
	CopterGame->SetUp();

	bool upPressed = false;
	bool spacePressed = false;
	bool spaceJustPressed = false;
	bool returnPressed = false;
	bool rPressed = false;
	bool rJustPressed = false;

	sf::Clock clock;
	while (window.isOpen())
	{	
		spaceJustPressed = false;
		rJustPressed = false;
		
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
				if (event.key.code == sf::Keyboard::Escape)
				{
					window.close();
				}
				if (event.key.code == sf::Keyboard::Up)
				{
					upPressed = true;
				}
				if (event.key.code == sf::Keyboard::Space)
				{
					spacePressed = true;
					spaceJustPressed = true;
				}
				if (event.key.code == sf::Keyboard::R)
				{
					rPressed = true;
					rJustPressed = true;
				}
				if (event.key.code == sf::Keyboard::Return)
				{
					returnPressed = true;
				}
			}
			// check key release
			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Up)
				{
					upPressed = false;
				}
				if (event.key.code == sf::Keyboard::Space)
				{
					spacePressed = false;
				}
				if (event.key.code == sf::Keyboard::R)
				{
					rPressed = false;
				}
			}
		}

		CopterGame->Update(dt,dt.asSeconds(),upPressed,spacePressed,spaceJustPressed,rPressed,rJustPressed,returnPressed);
		window.clear(sf::Color(0,0,0,255));
		CopterGame->Draw(&window);
		window.display();
	}

	TextureManager::Destroy();
	FontManager::Destroy();
	delete CopterGame;
	
	return EXIT_SUCCESS;
}