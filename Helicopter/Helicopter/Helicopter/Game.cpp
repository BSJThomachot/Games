#include "Game.h"

using namespace helicopter;

Game::Game(void)
{
	sf::FloatRect cam(0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
	m_camera = sf::View(cam);
	m_paused = false;
	m_started = false;
}


Game::~Game(void)
{
	delete m_player;
	delete m_level;
}

void Game::SetUp(void)
{
	FontManager::GetInstance()->SetFont("bebas");
	m_info = sf::Text("Helicopter Game",FontManager::GetInstance()->GetFont());
	m_info.setPosition(SCREEN_WIDTH/2.0f,SCREEN_HEIGHT/2.0f);
	m_info2 = sf::Text("Press Enter to Start",FontManager::GetInstance()->GetFont());
	m_info2.setPosition(SCREEN_WIDTH/2.0f,SCREEN_HEIGHT/2.0f + 100.0f);
	
	m_level = new LevelMaker();
	m_player = new Player("CopterRescueSprites",100,200,COPTER_WIDTH,COPTER_HEIGHT);

	m_level->SetUp();
}

void Game::Restart()
{
	m_player->Restart(100.0f,200.0f);
	m_level->SetUp();
	sf::FloatRect cam(0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
	m_camera = sf::View(cam);
	m_info.setString("PAUSE");
	m_info2.setString("Press R to Restart");
}

void Game::Draw(sf::RenderWindow * window)
{
	window->setView(m_camera);
	window->clear(sf::Color(25,25,112));
	m_level->Draw(window);
	m_player->Draw(window);

	if (m_paused)
	{
		window->draw(m_info);
	}
	else if (m_player->IsDead())
	{
		m_info.setString("GAME OVER");
		m_info2.setString("Press R to Restart");
		window->draw(m_info);
		window->draw(m_info2);
	}
	else if (!m_started)
	{
		m_info.setString("Helicopter Game");
		m_info2.setString("Press Enter to Start");
		window->draw(m_info);
		window->draw(m_info2);
	}
}

void Game::Update(sf::Time deltaTime, float dt, bool up, bool space, bool justSpace, bool R, bool justR, bool returnKey)
{
	if (space && justSpace && !m_player->IsDead() && m_started)
	{
		m_paused = !m_paused;
	}

	if (R && justR)
	{
		Restart();
	}

	if (returnKey)
	{
		m_started = true;
	}
	
	if (!m_paused && !m_player->IsDead() && m_started)
	{
		m_info.setPosition(m_camera.getCenter());
		m_info2.setPosition(m_camera.getCenter() + sf::Vector2f(0,100.0f));
		m_camera.move(dt*GAMESPEED,0);
		float edge = m_camera.getCenter().x - (m_camera.getSize().x/2.0f);
		m_level->Update(dt,edge,m_player);
		m_player->Update(deltaTime,up);
	}
}
