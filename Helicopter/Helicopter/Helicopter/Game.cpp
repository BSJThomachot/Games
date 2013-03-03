#include "Game.h"

using namespace helicopter;

Game::Game(void)
{
	sf::FloatRect cam(0,0,800,600);
	m_camera = sf::View(cam);
}


Game::~Game(void)
{
	delete m_player;
	delete m_level;
}

void Game::SetUp(sf::Texture& texturePlayer, sf::Texture& textureBuilding, sf::Texture textureMotherShip, sf::Texture textureCannon)
{
	m_level = new LevelMaker(textureBuilding,textureMotherShip,textureCannon);
	m_player = new Player(texturePlayer,200,200,96,64);

	m_level->SetUp();
}

void Game::Draw(sf::RenderWindow * window)
{
	window->setView(m_camera);
	window->clear();
	m_level->Draw(window);
	m_player->Draw(window);
}

void Game::Update(float dt, bool up)
{
	m_camera.move(dt*50.0f,0);
	float edge = m_camera.getCenter().x - (m_camera.getSize().x/2.0f);
	m_level->Update(dt,edge,m_player);
	m_player->Update(dt,up);
}
