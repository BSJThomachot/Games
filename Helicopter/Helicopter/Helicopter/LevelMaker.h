#ifndef __LEVELMAKER_H_
#define __LEVELMAKER_H_
#include <list>
#include "Player.h"
#include "Ufo.h"
#include "Cannon.h"

namespace helicopter
{

class LevelMaker
{
public:
	LevelMaker(void);
	LevelMaker(sf::Texture& textureBuilding, sf::Texture& textureMotherShip, sf::Texture& textureCannon, sf::Texture& texutreUFO, sf::Texture& textureLaser);
	~LevelMaker(void);

	void Update(float dt, float edge, Player * player);
	void Draw(sf::RenderWindow * window);

	void SetUp();

private:

	std::list<Entity*> bottom;
	std::list<Entity*> top;
	std::list<Enemy*> entities;

	sf::Texture m_textureBuilding;
	sf::Texture m_textureMotherShip;
	sf::Texture m_textureCannon;
	sf::Texture m_textureUFO;
	sf::Texture m_textureLaser;
	sf::Texture m_textureSurvivor;
	float m_lastXBuilding;
	float m_lastYBuilding;
	float m_lastXShip;
	float m_lastXCannon;

	float m_skyline;

	float m_UFOFrequency;
	float m_UFOTimer;
	float m_CannonFrequency;
	float m_CannonTimer;

};

}

#endif 
