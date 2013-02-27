#include "Player.h"

using namespace helicopter;

Player::Player(void)
{
	m_velocityX = 0;
	m_velocityY = 0;
}

Player::Player(sf::Texture& texture, float x, float y, float width, float height) : Entity(texture,x,y,width,height)
{
	m_velocityX = 0;
	m_velocityY = 0;
}

Player::~Player(void)
{

}

void Player::Update(float dt, bool up)
{
	sf::Vector2f pos = GetPosition();
	
	m_velocityY += 4.9f * dt * dt;
	if (up)
	{
		m_velocityY -= 50.0f * dt * dt;
	}
	pos.y += m_velocityY;
	SetPosition(pos.x,pos.y);
}
