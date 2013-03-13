#include "Player.h"

using namespace helicopter;

Player::Player(void)
{
	m_velocityX = 0;
	m_velocityY = 0;
	m_delay = 2.0f;
	m_dead = false;
	m_info = sf::Text("Press Up",FontManager::GetInstance()->GetFont());
	m_scoreInfo = sf::Text("0",FontManager::GetInstance()->GetFont());
	m_scoreInfo.scale(0.5f,0.5f);
	m_scoreInfo.setPosition(50.0f,100.0f);
	m_textTimer = 0;
	m_textTime = 2;
	m_score = 0;
}

Player::Player(std::string name, float x, float y, float width, float height) : Entity(name,x,y,width,height)
{
	m_velocityX = 0;
	m_velocityY = 0;
	m_delay = 2.0f;
	m_dead = false;
	m_info = sf::Text("Press Up",FontManager::GetInstance()->GetFont());
	m_scoreInfo = sf::Text("0",FontManager::GetInstance()->GetFont());
	m_scoreInfo.scale(0.5f,0.5f);
	m_scoreInfo.setPosition(50.0f,100.0f);
	m_textTimer = 0;
	m_textTime = 2;
	m_score = 0;
}

Player::~Player(void)
{

}

bool Player::IsDead(void)
{
	return m_dead;
}

void Player::Dead(bool value)
{
	m_dead = value;
}

void Player::SetScore(float value)
{
	m_score = value;
	char buf[32];
	sprintf_s( buf, 32, "%i", (int)value);
	m_scoreInfo.setString(sf::String(buf));
}

float Player::GetScore(void)
{
	return m_score;
}

void Player::Restart(float x, float y)
{
	SetPosition(x,y);
	m_delay = 2.0f;
	m_dead = false;
	m_textTimer = 0;
	m_textTime = 2;
	m_score = 0;
}

void Player::Draw(sf::RenderWindow * window)
{
	Entity::Draw(window);
	if (m_textTimer > 0 && m_textTimer < m_textTime)
	{
		window->draw(m_info);
	}
	window->draw(m_scoreInfo);
}

void Player::Update(float dt, bool up)
{
	if (!m_dead)
	{
		sf::Vector2f pos = GetPosition();
		if (m_delay > 0)
		{
			m_delay -= dt;
		}
		else
		{
			
			if (m_textTimer < m_textTime)
			{
				m_textTimer += dt;
				m_info.setPosition(GetPosition() + sf::Vector2f(0,100));
			}
			
			m_velocityY += 4.9f * dt * dt; // 9.8 / 2
			if (up)
			{
				m_velocityY -= 9.8f * dt * dt;
			}
			pos.y += m_velocityY*GAMESPEED/2.0f;
		}

		pos.x += dt*GAMESPEED;
		SetScore(m_score + dt*GAMESPEED);
		SetPosition(pos.x,pos.y);
		m_scoreInfo.setPosition(pos.x - 50.0f,100.0f);
	}
}
