#include "Laser.h"

using namespace helicopter;

Laser::Laser(void)
{
	m_speed = GAMESPEED;
}

Laser::Laser(std::string name, float x, float y, float width, float height) : Enemy(name,x,y,width,height)
{
	m_speed = GAMESPEED;
}


Laser::~Laser(void)
{
}

void Laser::Update(float dt, Player * p)
{
	if (Collides(p))
	{
		p->Dead(true);
	}	
	sf::Vector2f pos = GetPosition();
	pos.y += dt*m_speed;
	SetPosition(pos.x,pos.y);
}
