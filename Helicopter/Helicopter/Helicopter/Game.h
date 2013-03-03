#ifndef __GAME_H_
#define __GAME_H_
#include "Player.h"
#include "LevelMaker.h"

namespace helicopter
{


class Game
{
public:
	Game(void);
	~Game(void);

	void SetUp(sf::Texture& texturePlayer, sf::Texture& textureBuilding, sf::Texture textureMotherShip, sf::Texture textureCannon);

	void Update(float dt, bool up);
	void Draw(sf::RenderWindow * window);

private:
	LevelMaker * m_level;
	Player * m_player;

	sf::View m_camera;

	bool m_initialsed;
	
};

}

#endif

