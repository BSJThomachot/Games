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

	void SetUp(void);
	void Restart(void);

	void Update(float dt, bool up, bool space, bool justSpace, bool R, bool justR, bool returnKey);
	void Draw(sf::RenderWindow * window);

private:
	LevelMaker * m_level;
	Player * m_player;

	sf::View m_camera;

	sf::Text m_info;
	sf::Text m_info2;

	bool m_started;
	bool m_paused;
};

}

#endif

