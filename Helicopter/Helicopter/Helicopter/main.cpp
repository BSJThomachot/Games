#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Game.h"

using namespace helicopter;

int main()
{
	// SFML window
	sf::RenderWindow window(sf::VideoMode(800,600), "Helicopter");

	sf::Font font;
	if (!font.loadFromFile("Fonts/bebas.ttf"))
	{
		return EXIT_SUCCESS;
	}

	sf::Texture texturePlayer;
    if (!texturePlayer.loadFromFile("Images/CopterRescue.png"))
	{
		return EXIT_SUCCESS;
	}
	sf::Texture textureBuilding;
    if (!textureBuilding.loadFromFile("Images/Building.png"))
	{
		return EXIT_SUCCESS;
	}
	sf::Texture textureMotherShip;
    if (!textureMotherShip.loadFromFile("Images/MotherShip.png"))
	{
		return EXIT_SUCCESS;
	}
	sf::Texture textureCannon;
    if (!textureCannon.loadFromFile("Images/Cannon.png"))
	{
		return EXIT_SUCCESS;
	}
	sf::Texture textureUFO;
    if (!textureUFO.loadFromFile("Images/UFO.png"))
	{
		return EXIT_SUCCESS;
	}

	Game * CopterGame = new Game();
	CopterGame->SetUp(font,texturePlayer,textureBuilding,textureMotherShip,textureCannon,textureUFO);

	bool UpPressed = false;
	bool SpacePressed = false;
	bool SpaceJustPressed = false;

	//float lastime = 0

	sf::Clock clock;
	while (window.isOpen())
	{	
		SpaceJustPressed = false;
		
		sf::Time dt = clock.restart();
		//float fps = 1.0f / (dt.asSeconds() - lastime);
		//printf("%f \n",fps);
		//lastime = dt.asSeconds();
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
				if (event.key.code == sf::Keyboard::Space)
				{
					SpacePressed = true;
					SpaceJustPressed = true;
				}
			}
			// check key release
			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Up)
				{
					UpPressed = false;
				}
				if (event.key.code == sf::Keyboard::Space)
				{
					SpacePressed = false;
				}
			}
		}

		CopterGame->Update(dt.asSeconds(),UpPressed,SpacePressed,SpaceJustPressed);
		window.clear(sf::Color(0,0,0,255));
		CopterGame->Draw(&window);
		window.display();
	}

	delete CopterGame;

	return EXIT_SUCCESS;
}