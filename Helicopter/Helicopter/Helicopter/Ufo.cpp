#include "Ufo.h"

using namespace helicopter;

Ufo::Ufo(void)
{
	m_range = (float)(rand() % 100);
	m_speed = 25.0f;
	m_originY = 0;
	m_timer = 0;
}

Ufo::Ufo(std::string name, float x, float y, float width, float height) : Enemy(name,x,y,width,height)
{
	m_range = (float)(rand() % 100);
	m_speed = 25.0f;
	m_originY = y;
	m_timer = 0;
}

Ufo::~Ufo(void)
{

}


void Ufo::Update(float dt, Player * p)
{
	if (Collides(p))
	{
		p->Dead(true);
	}		
	
	sf::Vector2f pos = GetPosition();
	m_timer += dt;
	pos.y = m_originY + cos(m_timer)*m_range;
	pos.x -= dt*m_speed;
	SetPosition(pos.x,pos.y);
}
