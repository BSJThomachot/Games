#pragma once
#include "Misc.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

class Ball
{
private:
	// coordinates
	float fX;
	float fY;
	int iDirX;
	int iDirY;
	float fSpeed;

	// radius
	float fRadius;
	// sprite of the ball
	sf::Sprite sprite;

public:
	Ball(void);
	Ball(sf::Texture& texture, float x, float y, float radius);
	~Ball(void);

	void setPosition(float x, float y);
	void setPosition(sf::Vector2f vPos);
	sf::Vector2f getPosition(void);
	void setDirection(int x, int y);
	void setDirection(sf::Vector2i vPos);
	sf::Vector2i getDirection(void);
	void setRadius(float r);
	float getRadius(void);

	void draw(sf::RenderWindow * window);
	void update(Player * p1, Player * p2, float dt);
};

