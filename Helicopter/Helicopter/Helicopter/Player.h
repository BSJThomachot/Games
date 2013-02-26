#pragma once
#include "entity.h"
class Player : public Entity
{
public:
	Player(void);
	Player(sf::Texture& texture, float x, float y, float width, float height);
	~Player(void);

	void Update(float dt);

private:
	// velocity of the player
	float m_velX;
	float m_velY;
	sf::Vector2f m_velocity;
};

