#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Game.h"

using namespace portalpong;

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
	
	
	Game * PongGame = new Game();
	PongGame->SetUP(texturePlayer,textureBall,texturePortal1,texturePortal2,font);

	// keys to press
	bool UpPressed			= false;
	bool DownPressed		= false;
	bool WPressed			= false;
	bool SPressed			= false;
	bool SpacePressed		= false;
	bool SpaceJustPressed  = false;

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
				if (event.key.code == sf::Keyboard::Down)
				{
					DownPressed = true;
				}
				if (event.key.code == sf::Keyboard::W)
				{
					WPressed = true;
				}
				if (event.key.code == sf::Keyboard::S)
				{
					SPressed = true;
				}
				if (event.key.code == sf::Keyboard::Space)
				{
					SpacePressed = true;
				}
			}
			// check key release
			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Up)
				{
					UpPressed = false;
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					DownPressed = false;
				}
				if (event.key.code == sf::Keyboard::W)
				{
					WPressed = false;
				}
				if (event.key.code == sf::Keyboard::S)
				{
					SPressed = false;
				}
				if (event.key.code == sf::Keyboard::Space)
				{
					SpacePressed = false;
				}
			}
		}
		PongGame->Update(UpPressed,DownPressed,WPressed,SPressed,SpacePressed,SpaceJustPressed,dt.asSeconds());
		window.clear(sf::Color(0,0,0,255));
		PongGame->Draw(&window);
		window.display();
		
		// stop space repetition
		SpaceJustPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
	}

	delete PongGame;

	return EXIT_SUCCESS;
}