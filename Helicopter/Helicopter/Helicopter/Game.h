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

	void SetUp(sf::Font& font, sf::Texture& texturePlayer, sf::Texture& textureBuilding, sf::Texture& textureMotherShip, sf::Texture& textureCannon, sf::Texture& textureUFO);

	void Update(float dt, bool up, bool space, bool justSpace);
	void Draw(sf::RenderWindow * window);

private:
	LevelMaker * m_level;
	Player * m_player;

	sf::View m_camera;

	sf::Text m_info;

	bool m_initialsed;

	bool m_paused;
	
};

}

#endif

