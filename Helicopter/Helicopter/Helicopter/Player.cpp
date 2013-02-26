#include "Player.h"


Player::Player(void)
{
	// initialise velocity
	m_velX = 0;
	m_velY = 0;
}

Player::Player(sf::Texture& texture, float x, float y, float width, float height) : Entity(texture,x,y,width,height)
{

}

Player::~Player(void)
{

}

void Player::Update(float dt)
{
	// get current position
	sf::Vector2f pos = GetPosition();

	// update position
	sf::Vector2f newPos;
	newPos.x += m_velX*dt;
	newPos.y += m_velY*dt;

}
