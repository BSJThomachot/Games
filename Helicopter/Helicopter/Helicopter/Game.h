#ifndef __GAME_H_
#define __GAME_H_
#include "Player.h"

namespace helicopter
{


class Game
{
public:
	Game(void);
	~Game(void);

	void SetUp(sf::Texture& texturePlayer);

	void Update(float dt, bool up);
	void Draw(sf::RenderWindow * window);

private:
	Player * m_player;
};

}

#endif

