#pragma once
#include "Misc.h"
#include <SFML/Graphics.hpp>

class Ball
{
private:
	// coordinates
	float fX;
	float fY;
	// dimensions
	float fWidth;
	float fHeight;
	// sprite of the player
	sf::Sprite sprite;

public:
	Ball(void);
	~Ball(void);
};

