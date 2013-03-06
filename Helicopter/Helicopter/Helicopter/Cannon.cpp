#include "Cannon.h"

using namespace helicopter;

Cannon::Cannon(void)
{
	m_timer = 0;
	m_fireRate = 5;
}

Cannon::Cannon(sf::Texture& texture, sf::Texture& textureLaser, float x, float y, float width, float height) : Enemy(texture,x,y,width,height)
{
	m_timer = 0;
	m_fireRate = 5;
	m_textureLaser = textureLaser;
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

void Cannon::Update(float dt)
{
	m_timer += dt;
	if (m_timer >= m_fireRate)
	{
		Shoot();
		m_timer = 0;
	}
	if (lasers.size() > 0)
	{
		std::list<Laser*>::iterator iter;
		for (iter = lasers.begin(); iter != lasers.end();)
		{
			(*iter)->Update(dt);
			if ((*iter)->GetPosition().y + (*iter)->GetHeight() >= 600)
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
	Laser * laser = new Laser(m_textureLaser,GetPosition().x,GetPosition().y,8,16);
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
