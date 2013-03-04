#include "Game.h"

using namespace helicopter;

Game::Game(void)
{
	sf::FloatRect cam(0,0,800,600);
	m_camera = sf::View(cam);
	m_paused = false;
}


Game::~Game(void)
{
	delete m_player;
	delete m_level;
}

void Game::SetUp(sf::Font& font, sf::Texture& texturePlayer, sf::Texture& textureBuilding, sf::Texture& textureMotherShip, sf::Texture& textureCannon, sf::Texture& textureUFO)
{
	m_info = sf::Text("PAUSE",font);
	m_info.setPosition(400.0f,400.0f);
	
	m_level = new LevelMaker(textureBuilding,textureMotherShip,textureCannon,textureUFO);
	m_player = new Player(texturePlayer,200,200,96,64);

	m_level->SetUp();
}

void Game::Draw(sf::RenderWindow * window)
{
	window->setView(m_camera);
	window->clear();
	m_level->Draw(window);
	m_player->Draw(window);

	if (m_paused)
	{
		window->draw(m_info);
	}
}

void Game::Update(float dt, bool up, bool space, bool justSpace)
{
	if (space && justSpace)
	{
		m_paused = !m_paused;
	}
	
	if (!m_paused)
	{
		m_info.setPosition(m_camera.getCenter());
		m_camera.move(dt*100.0f,0);
		float edge = m_camera.getCenter().x - (m_camera.getSize().x/2.0f);
		m_level->Update(dt,edge,m_player);
		m_player->Update(dt,up);
	}
}
