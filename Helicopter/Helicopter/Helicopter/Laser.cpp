#include "Laser.h"

using namespace helicopter;

Laser::Laser(void)
{
	m_speed = 25.0f;
}

Laser::Laser(sf::Texture& texture, float x, float y, float width, float height) : Enemy(texture,x,y,width,height)
{
	m_speed = 25.0f;
}


Laser::~Laser(void)
{
}

void Laser::Update(float dt)
{
	sf::Vector2f pos = GetPosition();
	pos.y += dt*m_speed;
	SetPosition(pos.x,pos.y);
}
