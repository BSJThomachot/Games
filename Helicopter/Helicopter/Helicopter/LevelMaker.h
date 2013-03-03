#ifndef __LEVELMAKER_H_
#define __LEVELMAKER_H_
#include <list>
#include "Player.h"

namespace helicopter
{

class LevelMaker
{
public:
	LevelMaker(void);
	LevelMaker(sf::Texture& textureBuilding, sf::Texture textureMotherShip, sf::Texture textureCannon);
	~LevelMaker(void);

	void Update(float dt, float edge, Player * player);
	void Draw(sf::RenderWindow * window);

	void SetUp();

private:

	std::list<Entity*> bottom;
	std::list<Entity*> top;
	std::list<Entity*> entities;

	sf::Texture m_textureBuilding;
	sf::Texture m_textureMotherShip;
	sf::Texture m_textureCannon;
	sf::Texture m_textureUFO;
	sf::Texture m_textureSurvivor;
	float m_lastXBuilding;
	float m_lastXShip;

};

}

#endif 
