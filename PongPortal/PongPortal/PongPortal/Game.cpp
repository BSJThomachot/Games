#include "Game.h"
#include <ctime> 

using namespace portalpong;

Game::Game(void)
{
	m_paused = false;
	m_initialised = false;
	m_portalOFF = 3; // portal will be off for 3 seconds
	m_portalON = 6; // portal will be on for 6 seconds
	m_timer = m_portalON;
	srand((unsigned int)time(NULL));
}

Game::~Game(void)
{
	if (m_initialised)
	{
		delete m_portalB;
		delete m_portalA;
		delete m_ball;
		delete m_player2;
		delete m_player1;
	}
}


void Game::Pause(bool val)
{
	m_paused = val;
}


bool Game::isPaused(void)
{
	return m_paused;
}


void Game::SetUP(sf::Texture& texturePlayer, sf::Texture& textureBall, sf::Texture& texturePortalA, sf::Texture& texturePortalB, sf::Font& font)
{
	int players = 1;
	m_player1 = new Player( texturePlayer, 0, SCREEN_HEIGHT/2 - PLAYER_HEIGHT/2, PLAYER_WIDTH, PLAYER_HEIGHT, font,players);
	++players;
	m_player2 = new Player( texturePlayer, SCREEN_WIDTH - PLAYER_WIDTH, SCREEN_HEIGHT/2 - PLAYER_HEIGHT/2, PLAYER_WIDTH, PLAYER_HEIGHT, font,players);
	m_ball = new Ball( textureBall, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, (float)BALL_DIM);
	m_portalA = new Portal(texturePortalA, SCREEN_WIDTH/3*2, SCREEN_HEIGHT/3*2, PORTAL_WIDTH, PORTAL_HEIGHT);
	m_portalB = new Portal(texturePortalB, SCREEN_WIDTH/3*2, SCREEN_HEIGHT/3*2, PORTAL_WIDTH, PORTAL_HEIGHT);
	m_portalA->SetPosition((float)(SCREEN_WIDTH/4 + rand()%(SCREEN_WIDTH/2)), (float)(SCREEN_HEIGHT/4 + rand()%(SCREEN_HEIGHT/2)));
	m_portalB->SetPosition((float)(SCREEN_WIDTH/4 + rand()%(SCREEN_WIDTH/2)), (float)(SCREEN_HEIGHT/4 + rand()%(SCREEN_HEIGHT/2)));
	m_portalA->Pair(m_portalB);
	m_portalB->Pair(m_portalA);
	m_pause = sf::Text("PAUSE",font);
	m_pause.setPosition(SCREEN_WIDTH/2,SCREEN_HEIGHT/2);
	m_initialised = true;
}

void Game::Draw(sf::RenderWindow * window)
{
	if (m_initialised && !m_paused)
	{
		m_player1->Draw(window);
		m_player2->Draw(window);
		m_ball->Draw(window);
		m_portalA->Draw(window);
		m_portalB->Draw(window);
	}
	else if (m_paused) // game is paused
	{
		window->draw(m_pause);
	}
}

void Game::Update(bool up1, bool down1, bool up2, bool down2, bool space,  bool spaceJustPressed, float dt)
{
	if (space && spaceJustPressed)
	{
		m_paused = !m_paused;
	}

	if (m_initialised && !m_paused)
	{	
	
		m_player1->Update( up1, down1, dt);
		m_player2->Update( up2, down2, dt);
		m_ball->Update( m_player1, m_player2, dt);
		m_portalA->Update(m_ball,dt);
		m_portalB->Update(m_ball,dt);

		m_timer -= dt;

		if (m_portalA->IsActive() && m_portalB->IsActive())
		{
			if (m_timer <= 0) // time out, stop portal
			{
				m_portalA->Activate(false);
				m_portalB->Activate(false);
				m_timer = m_portalOFF;
			}
		}
		else 
		{
			if (m_timer <= 0) // time to set portal back On
			{
				m_portalA->Activate(true);
				m_portalB->Activate(true);
				m_timer = m_portalON;
				m_portalA->SetPosition((float)(SCREEN_WIDTH/4 + rand()%(SCREEN_WIDTH/2)), (float)(SCREEN_HEIGHT/4 + rand()%(SCREEN_HEIGHT/2)));
				m_portalB->SetPosition((float)(SCREEN_WIDTH/4 + rand()%(SCREEN_WIDTH/2)), (float)(SCREEN_HEIGHT/4 + rand()%(SCREEN_HEIGHT/2)));
				PortalType type = (PortalType)(rand() % COUNT);
				m_portalA->SetType(type);
				m_portalB->SetType(type);
			}
		}
	}
}
