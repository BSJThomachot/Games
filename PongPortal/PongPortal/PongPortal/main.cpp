#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Game.h"


int main()
{
	// SFML window
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT), "Pong Portal");
	// loading ressources
	// loading Font
	sf::Font font;
	if (!font.loadFromFile("Fonts/bebas.ttf"))
	{
		return EXIT_SUCCESS;
	}
	// loading images
	sf::Texture texturePlayer;
    if (!texturePlayer.loadFromFile("Images/Pad.png"))
	{
		return EXIT_SUCCESS;
	}
	sf::Texture textureBall;
    if (!textureBall.loadFromFile("Images/Ball.png"))
	{
		return EXIT_SUCCESS;
	}
	sf::Texture texturePortal1;
	if (!texturePortal1.loadFromFile("Images/PortalBlue.png"))
	{
		return EXIT_SUCCESS;
	}
	sf::Texture texturePortal2;
	if (!texturePortal2.loadFromFile("Images/PortalOrange.png"))
	{
		return EXIT_SUCCESS;
	}
	
	// Create game
	Game * PongGame = new Game();
	PongGame->SetUP(texturePlayer,textureBall,texturePortal1,texturePortal2,font);

	// keys to press
	bool bUpPressed			= false;
	bool bDownPressed		= false;
	bool bWPressed			= false;
	bool bSPressed			= false;
	bool bSpacePressed		= false;
	bool bSpaceJustPressed  = false;

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
			// check key press
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
				if (event.key.code == sf::Keyboard::Space)
				{
					bSpacePressed = true;
				}
			}
			// check key release
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
				if (event.key.code == sf::Keyboard::Space)
				{
					bSpacePressed = false;
				}
			}
		}
		// update PongGame
		PongGame->Update(bUpPressed,bDownPressed,bWPressed,bSPressed,bSpacePressed,bSpaceJustPressed,dt.asSeconds());
		// clear window
		window.clear(sf::Color(0,0,0,255));
		PongGame->Draw(&window);
		window.display();
		
		// stop space repetition
		bSpaceJustPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
	}

	// clean up
	delete PongGame;

	return EXIT_SUCCESS;
}