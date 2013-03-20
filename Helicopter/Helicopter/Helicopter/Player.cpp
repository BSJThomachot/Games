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

	m_animation.setSpriteSheet(*GetSprite().getTexture());
	m_animation.addFrame(sf::IntRect(0,0,96,64));
	m_animation.addFrame(sf::IntRect(96,0,192,64));

	m_sprites = AnimatedSprite(sf::seconds(0.2f));
	m_sprites.setAnimation(m_animation);

	SetPosition(x,y);
	m_sprites.setPosition(x,y);

	m_sprites.play();
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
	m_sprites.setPosition(x,y);
	m_delay = 2.0f;
	m_dead = false;
	m_textTimer = 0;
	m_textTime = 2;
	m_score = 0;
	m_velocityX = 0;
	m_velocityY = 0;
}

void Player::Draw(sf::RenderWindow * window)
{
	window->draw(m_sprites);
	if (m_textTimer > 0 && m_textTimer < m_textTime)
	{
		window->draw(m_info);
	}
	window->draw(m_scoreInfo);
}

void Player::Update(sf::Time deltaTime, bool up)
{
	if (!m_dead)
	{
		m_sprites.update(deltaTime);
		sf::Vector2f pos = GetPosition();
		if (m_delay > 0)
		{
			m_delay -= deltaTime.asSeconds();
		}
		else
		{
			if (m_textTimer < m_textTime)
			{
				m_textTimer += deltaTime.asSeconds();
				m_info.setPosition(GetPosition() + sf::Vector2f(0,100));
			}
			
			m_velocityY += 4.9f * deltaTime.asSeconds() * deltaTime.asSeconds(); // 9.8 / 2
			if (up)
			{
				m_velocityY -= 9.8f * deltaTime.asSeconds() * deltaTime.asSeconds();
			}
			pos.y += m_velocityY*GAMESPEED/2.0f;
		}

		pos.x += deltaTime.asSeconds()*GAMESPEED;
		SetScore(m_score + deltaTime.asSeconds()*GAMESPEED);
		SetPosition(pos.x,pos.y);
		m_sprites.setPosition(pos.x,pos.y);
		m_scoreInfo.setPosition(pos.x - 50.0f,100.0f);
	}
}
