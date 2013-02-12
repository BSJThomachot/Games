#include "Game.h"
#include <ctime> 

// Constuctor
Game::Game(void)
{
	this->m_bPaused = false;
	this->m_bInitialised = false;
	this->m_fPortalOFF = 3; // portal will be off for 3 seconds
	this->m_fPortalON = 6; // portal will be on for 6 seconds
	this->Timer = this->m_fPortalON;
	// seed the random function
	srand(time(0));
}

// destuctor
Game::~Game(void)
{
	if (this->m_bInitialised)
	{
		delete this->m_pPortalB;
		delete this->m_pPortalA;
		delete this->m_pBall;
		delete this->m_pPlayer2;
		delete this->m_pPlayer1;
	}
}

// pause/unpause
void Game::Pause(bool val)
{
	this->m_bPaused = val;
}

// is the game paused? 
bool Game::isPaused(void)
{
	return this->m_bPaused;
}

// set up the game
void Game::SetUP(sf::Texture& texturePlayer, sf::Texture& textureBall, sf::Texture& texturePortalA, sf::Texture& texturePortalB, sf::Font& font)
{
	// The players
	int players = 1;
	this->m_pPlayer1 = new Player(texturePlayer,0,SCREEN_HEIGHT/2 - PLAYER_HEIGHT/2,PLAYER_WIDTH,PLAYER_HEIGHT,font,players);
	++players;
	this->m_pPlayer2 = new Player(texturePlayer,SCREEN_WIDTH - PLAYER_WIDTH,SCREEN_HEIGHT/2 - PLAYER_HEIGHT/2,PLAYER_WIDTH,128,font,players);
	// The Ball
	this->m_pBall = new Ball(textureBall,SCREEN_WIDTH/2,SCREEN_HEIGHT/2,BALL_DIM);
	// The Portals
	this->m_pPortalA = new Portal(texturePortalA, SCREEN_WIDTH/3*2, SCREEN_HEIGHT/3*2, PORTAL_WIDTH, PORTAL_HEIGHT);
	this->m_pPortalB = new Portal(texturePortalB, SCREEN_WIDTH/3*2, SCREEN_HEIGHT/3*2, PORTAL_WIDTH, PORTAL_HEIGHT);
	this->m_pPortalA->SetPosition((float)(SCREEN_WIDTH/4 + rand()%(SCREEN_WIDTH/2)),(float)(SCREEN_HEIGHT/4 + rand()%(SCREEN_HEIGHT/2)));
	this->m_pPortalB->SetPosition((float)(SCREEN_WIDTH/4 + rand()%(SCREEN_WIDTH/2)),(float)(SCREEN_HEIGHT/4 + rand()%(SCREEN_HEIGHT/2)));
	this->m_pPortalA->Pair(this->m_pPortalB);
	this->m_pPortalB->Pair(this->m_pPortalA);
	// set up text
	this->m_Pause = sf::Text("PAUSE",font);
	this->m_Pause.setPosition(SCREEN_WIDTH/2,SCREEN_HEIGHT/2);
	// Game is now initialised
	this->m_bInitialised = true;
}

// Draw game
void Game::Draw(sf::RenderWindow * window)
{
	if (this->m_bInitialised && !this->m_bPaused)
	{
		this->m_pPlayer1->Draw(window);
		this->m_pPlayer2->Draw(window);
		this->m_pBall->Draw(window);
		this->m_pPortalA->Draw(window);
		this->m_pPortalB->Draw(window);
	}
	else if (this->m_bPaused) // game is paused
	{
		window->draw(this->m_Pause);
	}
}

// Update game
void Game::Update(bool up1, bool down1, bool up2, bool down2, bool space,  bool spaceJustPressed, float dt)
{
	// toggle pause
	if (space && !spaceJustPressed)
	{
		this->m_bPaused = !this->m_bPaused;
	}

	if (this->m_bInitialised && !this->m_bPaused)
	{	
		// update players
		this->m_pPlayer1->Update(up1,down1,dt);
		this->m_pPlayer2->Update(up2,down2,dt);
		// update ball
		this->m_pBall->Update(this->m_pPlayer1,this->m_pPlayer2,dt);
		// update portals
		this->m_pPortalA->Update(this->m_pBall,dt);
		this->m_pPortalB->Update(this->m_pBall,dt);

		this->Timer -= dt;

		if (this->m_pPortalA->IsActive() && this->m_pPortalB->IsActive())
		{
			if (this->Timer <= 0) // time out, stop portal
			{
				this->m_pPortalA->Activate(false);
				this->m_pPortalB->Activate(false);
				this->Timer = this->m_fPortalOFF;
			}
		}
		else 
		{
			if (this->Timer <= 0) // time to set portal back On
			{
				this->m_pPortalA->Activate(true);
				this->m_pPortalB->Activate(true);
				this->Timer = this->m_fPortalON;
				// pick another positions (around the centre)
				this->m_pPortalA->SetPosition((float)(SCREEN_WIDTH/4 + rand()%(SCREEN_WIDTH/2)),(float)(SCREEN_HEIGHT/4 + rand()%(SCREEN_HEIGHT/2)));
				this->m_pPortalB->SetPosition((float)(SCREEN_WIDTH/4 + rand()%(SCREEN_WIDTH/2)),(float)(SCREEN_HEIGHT/4 + rand()%(SCREEN_HEIGHT/2)));
				Portal::PortalType type = (Portal::PortalType)(rand() % Portal::PortalType::COUNT);
				// set the other portal to the same type! 
				this->m_pPortalA->SetType(type);
				this->m_pPortalB->SetType(type);

			}
		}
	}
}
