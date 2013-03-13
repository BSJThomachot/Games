#ifndef __LEVELMAKER_H_
#define __LEVELMAKER_H_
#include <list>
#include "Player.h"
#include "Ufo.h"
#include "Cannon.h"
#include "Survivor.h"

namespace helicopter
{

class LevelMaker
{
public:
	LevelMaker(void);
	~LevelMaker(void);

	void Update(float dt, float edge, Player * player);
	void Draw(sf::RenderWindow * window);

	void SetUp(void);
	void ClearLists(void);

private:

	std::list<Entity*> obstacles;
	std::list<Entity*> top;
	std::list<Entity*> bottom;
	std::list<Enemy*> enemies;
	std::list<Survivor*> survivors;

	float m_lastXBuilding;
	float m_lastYBuilding;
	float m_lastXShip;
	float m_lastXCannon;

	int m_level;

	int m_skylineHeight;

	float m_UFOFrequency;
	float m_UFOTimer;
	float m_CannonFrequency;
	float m_CannonTimer;

};

}

#endif 
