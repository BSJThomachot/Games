// definition of the game class
#pragma once
#include <SFML/Graphics.hpp>
#include "Misc.h"
#include "Player.h"
#include "Ball.h"
#include "Portal.h"

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

	// Players
	Player * m_pPlayer1;
	Player * m_pPlayer2;
	// Ball 
	Ball * m_pBall;
	// Portals
	Portal * m_pPortalA;
	Portal * m_pPortalB;

	// has the game been initialised
	bool m_bInitialised;
	// is the game paused?
	bool m_bPaused;
	// Pause text
	sf::Text m_Pause;
	// duration of the portals
	float m_fPortalOFF;
	float m_fPortalON;
	// a timer
	float Timer;
};

