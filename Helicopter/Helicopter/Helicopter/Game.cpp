#include "Game.h"

using namespace helicopter;

Game::Game(void)
{
}


Game::~Game(void)
{
	delete m_player;
}

void Game::SetUp(sf::Texture& texturePlayer)
{
	m_player = new Player(texturePlayer,400,400,32,32);
}

void Game::Draw(sf::RenderWindow * window)
{
	m_player->Draw(window);
}

void Game::Update(float dt, bool up)
{
	m_player->Update(dt,up);
	int i = 0;
	if (up)
	{
		i = 2;
	}
}
