#include "LevelMaker.h"

using namespace helicopter;

LevelMaker::LevelMaker(void)
{
	srand((unsigned int)time(NULL));
}


LevelMaker::~LevelMaker(void)
{
	ClearLists();
}

void LevelMaker::SetUp()
{
	m_lastXBuilding = 0;
	m_lastXShip = 0;
	m_lastXCannon = 0;
	m_skylineHeight = 50;
	m_lastYBuilding = 600.0f - m_skylineHeight;

	m_level = 1;

	m_UFOTimer = 0;
	m_CannonTimer = 0;
	m_UFOFrequency = 10.0f;
	m_CannonFrequency = 5.0f;

	ClearLists();

	int i;
	for (i = 0; i < 15; ++i)
	{
		Entity * building = new Entity("Building",m_lastXBuilding,m_lastYBuilding,BUILDING_WIDTH,BUILDING_HEIGHT);
		bottom.push_back(building);
		m_lastXBuilding += building->GetWidth();
	}
	for (i = 0; i < 3; ++i)
	{
		Entity * ship = new Entity("MotherShip",m_lastXShip,0,512,64);
		top.push_back(ship);
		m_lastXShip += ship->GetWidth();
	}
}


void LevelMaker::ClearLists()
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
		std::list<Entity*>::iterator iter;
		for (iter = top.begin(); iter != top.end();)
		{
			delete (*iter);
			iter = top.erase(iter);
		}
	}
	top.clear();

	if (cannons.size() > 0)
	{
		std::list<Cannon*>::iterator iter;
		for (iter = cannons.begin(); iter != cannons.end();)
		{
			delete (*iter);
			iter = cannons.erase(iter);
		}
	}
	cannons.clear();

	if (enemies.size() > 0)
	{
		std::list<Enemy*>::iterator iter;
		for (iter = enemies.begin(); iter != enemies.end();)
		{
			delete (*iter);
			iter = enemies.erase(iter);
		}
	}
	enemies.clear();

	if (survivors.size() > 0)
	{
		std::list<Survivor*>::iterator iter;
		for (iter = survivors.begin(); iter != survivors.end();)
		{
			delete (*iter);
			iter = survivors.erase(iter);
		}
	}
	survivors.clear();
}

void LevelMaker::Update(float dt, float edge, Player * player)
{
	// set difficulty/level according to how far the player is
	if (m_level < 9)
	{
		if (m_level == 1 && player->GetPosition().x > 1000.0f)
		{
			m_level = 2;
			m_lastYBuilding = SCREEN_HEIGHT - 25.0f; 
		}
		else if (m_level == 2 && player->GetPosition().x > 2000.0f)
		{
			m_skylineHeight = 75;
			m_level = 3;
			m_lastYBuilding = SCREEN_HEIGHT - 50.0f; 
		}
		else if (m_level == 3 && player->GetPosition().x > 3000.0f)
		{
			m_skylineHeight = 100;
			m_level = 4;
			m_lastYBuilding = SCREEN_HEIGHT - 75.0f;
		}
		else if (m_level == 4 && player->GetPosition().x > 4000.0f)
		{
			m_skylineHeight = 125;
			m_level = 5;
			m_lastYBuilding = SCREEN_HEIGHT - 100.0f;
		}
		else if (m_level == 5 && player->GetPosition().x > 5000.0f)
		{
			m_skylineHeight = 150;
			m_level = 6;
			m_lastYBuilding = SCREEN_HEIGHT - 125.0f; 
		}
		else if (m_level == 6 && player->GetPosition().x > 6000.0f)
		{
			m_skylineHeight = 175;
			m_level = 7;
			m_lastYBuilding = SCREEN_HEIGHT - 150.0f; 
		}
		else if (m_level == 7 && player->GetPosition().x > 7000.0f)
		{
			m_skylineHeight = 200;
			m_level = 8;
			m_lastYBuilding = SCREEN_HEIGHT - 175.0f; 
		}
		else if (m_level == 8 && player->GetPosition().x > 8000.0f)
		{
			m_skylineHeight = 200;
			m_level = 9;
			m_lastYBuilding = SCREEN_HEIGHT - m_skylineHeight; 
		}
	}
	
	// update enemies
	std::list<Enemy*>::iterator iter3;
	for (iter3 = enemies.begin(); iter3 != enemies.end();)
	{
		(*iter3)->Update(dt,player);
		//if (player->Collides((*iter3)))
		//{
		//	player->Dead(true);
		//}	
		if ((*iter3)->GetPosition().x + (*iter3)->GetWidth() <= edge)
	 	{
	 		delete (*iter3);
	 		iter3 = enemies.erase(iter3);
	 	}
	 	else
		{
	 		++iter3;
		}
	}

	// update cannons
	std::list<Cannon*>::iterator iter5;
	for (iter5 = cannons.begin(); iter5 != cannons.end();)
	{
		(*iter5)->Update(dt,player);
		//if (player->Collides((*iter5)))
		//{
		//	player->Dead(true);
		//}
		//std::list<Laser*>::iterator iterLaser;
		//for (iterLaser = (*iter5)->lasers.begin(); iterLaser != (*iter5)->lasers.end();++iterLaser)
		//{
		//	if (player->Collides((*iterLaser)))
		//	{
		//		player->Dead(true);
		//	}
		//
		//}
		if ((*iter5)->GetPosition().x + (*iter5)->GetWidth() <= edge)
	 	{
	 		delete (*iter5);
	 		iter5 = cannons.erase(iter5);
	 	}
	 	else
		{
	 		++iter5;
		}
	}


	m_UFOTimer += dt;
	if (m_UFOTimer >= m_UFOFrequency)
	{
		m_UFOTimer = 0;
		Enemy * ufo = new Ufo("UFO",m_lastXBuilding,SCREEN_HEIGHT/2.0f,UFO_WIDTH,UFO_HEIGHT);
		enemies.push_back(ufo);
	}

	m_CannonTimer += dt;
	if (m_CannonTimer >= m_CannonFrequency)
	{
		m_CannonTimer = 0;
		Cannon * cannon = new Cannon("Cannon",m_lastXBuilding,64.0f,CANNON_WIDTH,CANNON_HEIGHT);
		cannons.push_back(cannon);
	}

	// update bottom
	int counter = 0;
	std::list<Entity*>::iterator iter;
	for (iter = bottom.begin(); iter != bottom.end();)
	{
		if (player->Collides((*iter)))
		{
			player->Dead(true);
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
		}
	}
	
	if (counter > 0)
	{		
		Entity * building = new Entity("Building",m_lastXBuilding,m_lastYBuilding,BUILDING_WIDTH,BUILDING_HEIGHT);
		bottom.push_back(building);

		bool occupied = ((rand() % 100) >= 90) ? true : false;
		if (occupied)
		{
			Survivor * a_survivor = new Survivor("Survivor",m_lastXBuilding + BUILDING_WIDTH/2.0f,m_lastYBuilding - SURVIVOR_HEIGHT, SURVIVOR_WIDTH, SURVIVOR_HEIGHT); 
			survivors.push_back(a_survivor);
		}

		m_lastXBuilding += building->GetWidth();
		float offset = (rand() % 2 == 0) ? -10.0f : 10.0f;
		m_lastYBuilding += offset;
		if (m_lastYBuilding <= SCREEN_HEIGHT - m_skylineHeight)
		{
			m_lastYBuilding = SCREEN_HEIGHT - m_skylineHeight;
		}
		else if (m_lastYBuilding >= SCREEN_HEIGHT)
		{
			m_lastYBuilding = SCREEN_HEIGHT - 10.0f;
		}
	}
	// top
	counter = 0;
	std::list<Entity*>::iterator iter2;
	for (iter2 = top.begin(); iter2 != top.end();)
	{
		if (player->Collides((*iter2)))
		{
			player->Dead(true);
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
		Entity * ship = new Entity("MotherShip",m_lastXShip,0,SHIP_WIDTH,SHIP_HEIGHT);
		top.push_back(ship);
		m_lastXShip += ship->GetWidth();
	}
	
	std::list<Survivor *>::iterator iter4;
	for (iter4 = survivors.begin(); iter4 != survivors.end();)
	{
		(*iter4)->Update(dt,player);
		//if (player->Collides(*iter4))
		//{
		//	(*iter4)->Rescue(true);
		//	player->SetScore(player->GetScore() + 1000.0f);
		//}
		if ((*iter4)->GetPosition().x + (*iter4)->GetWidth() <= edge || (*iter4)->isRescued())
	 	{
	 		delete (*iter4);
	 		iter4 = survivors.erase(iter4);
			++counter;
	 	}
	 	else
		{
	 		++iter4;
		}
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
	for (iter3 = enemies.begin(); iter3 != enemies.end(); ++iter3)
	{
		(*iter3)->Draw(window);
	}
	std::list<Survivor*>::iterator iter4;
	for (iter4 = survivors.begin(); iter4 != survivors.end();++iter4)
	{
		(*iter4)->Draw(window);
	}
	std::list<Cannon*>::iterator iter5;
	for (iter5 = cannons.begin(); iter5 != cannons.end();++iter5)
	{
		(*iter5)->Draw(window);
	}
}

