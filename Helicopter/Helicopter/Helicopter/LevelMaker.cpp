#include "LevelMaker.h"

using namespace helicopter;

LevelMaker::LevelMaker(void)
{
	m_lastXBuilding = 0;
	m_lastXShip = 0;
}

LevelMaker::LevelMaker(sf::Texture& textureBuilding, sf::Texture textureMotherShip, sf::Texture textureCannon)
{
	m_textureBuilding = textureBuilding;
	m_textureMotherShip = textureMotherShip;
	m_textureCannon = textureCannon;
	m_lastXBuilding = 0;
	m_lastXShip = 0;
}


LevelMaker::~LevelMaker(void)
{
	if (bottom.size() > 0)
	{
		std::list<Entity*>::iterator iter;
		for (iter = bottom.begin(); iter != bottom.end();)
		{
			delete (*iter);
			iter = bottom.erase(iter);
		}
	}
	bottom.clear();

	if (top.size() > 0)
	{
		std::list<Entity*>::iterator iter2;
		for (iter2 = top.begin(); iter2 != top.end();)
		{
			delete (*iter2);
			iter2 = top.erase(iter2);
		}
	}
	top.clear();
}

void LevelMaker::SetUp()
{
	int i;
	m_lastXBuilding = 0;
	m_lastXShip = 0;
	for (i = 0; i < 15; ++i)
	{
		Entity * building = new Entity(m_textureBuilding,m_lastXBuilding,400,64,256);
		bottom.push_back(building);
		m_lastXBuilding += building->GetWidth();
	}
	for (i = 0; i < 3; ++i)
	{
		Entity * ship = new Entity(m_textureMotherShip,m_lastXShip,0,512,64);
		top.push_back(ship);
		m_lastXShip += ship->GetWidth();
	}
}


void LevelMaker::Update(float dt, float edge, Player * player)
{
	float a = dt;
	
	int counter = 0;
	std::list<Entity*>::iterator iter;
	for (iter = bottom.begin(); iter != bottom.end();)
	{
		if (player->Collides((*iter)))
		{
			printf("COLLIDING \n");
		}
		if ((*iter)->GetPosition().x + (*iter)->GetWidth() <= edge)
	 	{
	 		delete (*iter);
	 		iter = bottom.erase(iter);
			++counter;
	 	}
	 	else
		{
	 		++iter;
			++a;
		}
	}

	if (counter > 0)
	{
		Entity * building = new Entity(m_textureBuilding,m_lastXBuilding,400,64,256);
		bottom.push_back(building);
		m_lastXBuilding += building->GetWidth();
	}

	counter = 0;
	std::list<Entity*>::iterator iter2;
	for (iter2 = top.begin(); iter2 != top.end();)
	{
		if (player->Collides((*iter2)))
		{
			printf("COLLIDING \n");
		}		
		if ((*iter2)->GetPosition().x + (*iter2)->GetWidth() <= edge)
	 	{
	 		delete (*iter2);
	 		iter2 = top.erase(iter2);
			++counter;
	 	}
	 	else
		{
	 		++iter2;
			++a;
		}
	}

	if (counter > 0)
	{
		Entity * ship = new Entity(m_textureMotherShip,m_lastXShip,0,512,64);
		top.push_back(ship);
		m_lastXShip += ship->GetWidth();
	}


}

void LevelMaker::Draw(sf::RenderWindow * window)
{
	std::list<Entity*>::iterator iter;
	for (iter = bottom.begin(); iter != bottom.end(); ++iter)
	{
		(*iter)->Draw(window);
	}
	std::list<Entity*>::iterator iter2;
	for (iter2 = top.begin(); iter2 != top.end(); ++iter2)
	{
		(*iter2)->Draw(window);
	}
}

