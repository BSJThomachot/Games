#pragma once
#include "Misc.h"
#include <SFML/Graphics.hpp>

class Player
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
	Player(void);
	Player(sf::Texture& texture, float x, float y, float width, float height);
	~Player(void);

	void setPosition(float x, float y);
	void setPosition(sf::Vector2f vPos);
	sf::Vector2f getPosition(void);
	void setWidth(float w);
	float getWidth(void);
	void setHeight(float h);
	float getHeight(void);
	
	void draw(sf::RenderWindow * window);
	void update(bool up, bool down, float dt);

};

