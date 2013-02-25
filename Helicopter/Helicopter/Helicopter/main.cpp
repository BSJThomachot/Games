#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

int main()
{
	// SFML window
	sf::RenderWindow window(sf::VideoMode(1024,768), "Helicopter");

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
		}
	}

	return EXIT_SUCCESS;

}