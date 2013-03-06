#include "LevelMaker.h"

using namespace helicopter;

LevelMaker::LevelMaker(void)
{
	m_lastXBuilding = 0;
	m_lastXShip = 0;
	m_lastXCannon = 0;
	srand((unsigned int)time(NULL));
	m_lastYBuilding = 600.0f - (float)(rand() % 200);

	m_UFOTimer = 0;
	m_CannonTimer = 0;
	m_UFOFrequency = 10.0f;
	m_CannonFrequency = 5.0f;
	
}

LevelMaker::LevelMaker(sf::Texture& textureBuilding, sf::Texture& textureMotherShip, sf::Texture& textureCannon, sf::Texture& textureUFO, sf::Texture& textureLaser)
{
	m_textureBuilding = textureBuilding;
	m_textureMotherShip = textureMotherShip;
	m_textureCannon = textureCannon;
	m_textureUFO = textureUFO;
	m_textureLaser = textureLaser;
	m_lastXBuilding = 0;
	m_lastXShip = 0;
	m_lastXCannon = 0;
	srand((unsigned int)time(NULL));
	m_lastYBuilding = 600.0f - (float)(rand() % 200);

	m_UFOTimer = 0;
	m_CannonTimer = 0;
	m_UFOFrequency = 10.0f;
	m_CannonFrequency = 5.0f;
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

	if (entities.size() > 0)
	{
		std::list<Enemy*>::iterator iter3;
		for (iter3 = entities.begin(); iter3 != entities.end();)
		{
			delete (*iter3);
			iter3 = entities.erase(iter3);
		}
	}
	entities.clear();
}

void LevelMaker::SetUp()
{
	int i;
	m_lastXBuilding = 0;
	m_lastXShip = 0;
	for (i = 0; i < 15; ++i)
	{
		Entity * building = new Entity(m_textureBuilding,m_lastXBuilding,m_lastYBuilding,64,256);
		bottom.push_back(building);
		m_lastXBuilding += building->GetWidth();
		float offset = (rand() % 2 == 0) ? -10.0f : 10.0f;
		m_lastYBuilding += offset;
		if (m_lastYBuilding < 400.0f)
		{
			m_lastYBuilding = 400.0f;
		}
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
	// float a = dt;
	std::list<Enemy*>::iterator iter3;
	for (iter3 = entities.begin(); iter3 != entities.end();)
	{
		//if (player->Collides((*iter3)))
		//{
			// printf("COLLIDING \n");
		//}
		(*iter3)->Update(dt);
		if ((*iter3)->GetPosition().x + (*iter3)->GetWidth() <= edge)
	 	{
	 		delete (*iter3);
	 		iter3 = entities.erase(iter3);
	 	}
	 	else
		{
	 		++iter3;
		}
	}


	m_UFOTimer += dt;
	if (m_UFOTimer >= m_UFOFrequency)
	{
		m_UFOTimer = 0;
		Enemy * ufo = new Ufo(m_textureUFO,m_lastXBuilding,400.0f,64,32);
		entities.push_back(ufo);
	}

	m_CannonTimer += dt;
	if (m_CannonTimer >= m_CannonFrequency)
	{
		m_CannonTimer = 0;
		Enemy * cannon = new Cannon(m_textureCannon,m_textureLaser,m_lastXBuilding,64.0f,64,32);
		entities.push_back(cannon);
	}

	int counter = 0;
	std::list<Entity*>::iterator iter;
	for (iter = bottom.begin(); iter != bottom.end();)
	{
		//if (player->Collides((*iter)))
		//{
		// printf("COLLIDING \n");
		//}
		if ((*iter)->GetPosition().x + (*iter)->GetWidth() <= edge)
	 	{
	 		delete (*iter);
	 		iter = bottom.erase(iter);
			++counter;
	 	}
	 	else
		{
	 		++iter;
		}
	}
	// TODO Make skyline go higher and higher (and start low)
	if (counter > 0)
	{
		Entity * building = new Entity(m_textureBuilding,m_lastXBuilding,m_lastYBuilding,64,256);
		bottom.push_back(building);
		m_lastXBuilding += building->GetWidth();
		float offset = (rand() % 2 == 0) ? -10.0f : 10.0f;
		m_lastYBuilding += offset;
		if (m_lastYBuilding < 400.0f)
		{
			m_lastYBuilding = 400.0f;
		}
	}

	counter = 0;
	std::list<Entity*>::iterator iter2;
	for (iter2 = top.begin(); iter2 != top.end();)
	{
		if (player->Collides((*iter2)))
		{
			// printf("COLLIDING \n");
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
	std::list<Enemy*>::iterator iter3;
	for (iter3 = entities.begin(); iter3 != entities.end(); ++iter3)
	{
		(*iter3)->Draw(window);
	}
}

