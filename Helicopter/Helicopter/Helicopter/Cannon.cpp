#include "Cannon.h"

using namespace helicopter;

Cannon::Cannon(void)
{
	m_timer = 0;
	m_fireRate = (float)(rand() % 4 + 2);
}

Cannon::Cannon(std::string name, float x, float y, float width, float height) : Enemy(name,x,y,width,height)
{
	m_timer = 0;
	m_fireRate = (float)(rand() % 3 + 2);
	m_laserSpawn = sf::Vector2f(GetPosition().x + GetWidth()/2.0f,GetPosition().y + GetHeight());
}

Cannon::~Cannon(void)
{
	if (lasers.size() > 0)
	{
		std::list<Laser*>::iterator iter;
		for (iter = lasers.begin(); iter != lasers.end();)
		{
			delete (*iter);
			iter = lasers.erase(iter);
		}
	}
	lasers.clear();
}

void Cannon::Update(float dt, Player * p)
{
	m_timer += dt;
	if (m_timer >= m_fireRate)
	{
		Shoot();
		m_timer = 0;
	}
	if (Collides(p))
	{
		p->Dead(true);
	}
	if (lasers.size() > 0)
	{
		std::list<Laser*>::iterator iter;
		for (iter = lasers.begin(); iter != lasers.end();)
		{
			(*iter)->Update(dt,p);
			if ((*iter)->GetPosition().y + (*iter)->GetHeight() >= SCREEN_HEIGHT || (*iter)->GetPosition().x + (*iter)->GetWidth() < 0 )
			{
				delete (*iter);
				iter = lasers.erase(iter);
			}
	 		else
			{
	 			++iter;
			}
		}
	}
}

void Cannon::Shoot(void)
{
	Laser * laser = new Laser("Laser",m_laserSpawn.x,m_laserSpawn.y,LASER_WIDTH,LASER_HEIGHT);
	lasers.push_back(laser);
}

void Cannon::Draw(sf::RenderWindow * window)
{
	Entity::Draw(window);
	if (lasers.size() > 0)
	{
		std::list<Laser*>::iterator iter;
		for (iter = lasers.begin(); iter != lasers.end(); ++iter)
		{
			(*iter)->Draw(window);
		}
	}
}
