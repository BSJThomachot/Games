// definition of the game class
#ifndef __GAME_H_
#define __GAME_H_
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Ball.h"
#include "Portal.h"

namespace portalpong
{

class Game
{
public:
	Game(void);
	~Game(void);

	void Pause(bool val);
	bool isPaused(void);

	void SetUP(sf::Texture& texturePlayer, sf::Texture& textureBall, sf::Texture& texturePortalA, sf::Texture& texturePortalB, sf::Font& font);
	void Draw(sf::RenderWindow * window);
	void Update(bool up1, bool down1, bool up2, bool down2, bool space, bool spaceJustPressed, float dt);

private:


	Player * m_player1;
	Player * m_player2;
	Ball * m_ball;
	Portal * m_portalA;
	Portal * m_portalB;

	bool m_initialised;
	bool m_paused;
	sf::Text m_pause;
	// duration of the portals
	float m_portalOFF;
	float m_portalON;
	float m_timer;
};

}

#endif 

