#include "Player.h"

using namespace portalpong;

Player::Player(void)
{

}


Player::Player(sf::Texture& texture, float x, float y, int width, int height, sf::Font& font, int id)
{
	m_sprite = sf::Sprite(texture);
	SetPosition(x,y);
	m_sprite.setPosition(x,y);
	m_width = width;
	m_height = height;
	m_score = 0;
	m_info = sf::Text("0",font);
	m_info.setPosition((float)(SCREEN_WIDTH/3 * id),0);
	if (id == 1)
	{
		m_info.setColor(sf::Color(0,sf::Uint8(255),0,sf::Uint8(255)));
	}
	else
	{
		m_info.setColor(sf::Color(0,0,sf::Uint8(255),sf::Uint8(255)));
	}
	m_speed = 250;
}

Player::~Player(void)
{
}


void Player::SetPosition(float x, float y)
{
	m_x = x;
	m_y = y;
	m_sprite.setPosition(x,y);
}

void Player::SetPosition(sf::Vector2f vPos)
{
	m_x = vPos.x;
	m_y = vPos.y;
	m_sprite.setPosition(vPos);
}


sf::Vector2f Player::GetPosition(void)
{
	return sf::Vector2f( m_x, m_y);
}

void Player::SetWidth(int w)
{
	m_width = w;
}

int Player::GetWidth(void)
{
	return m_width;
}

void Player::SetHeight(int h)
{
	m_height = h;
}

int Player::GetHeight(void)
{
	return m_height;
}

void Player::SetScore(int s)
{
	m_score = s;
	char buf[32];
	sprintf_s( buf, 32, "%i", s);
	m_info.setString(sf::String(buf));
	m_info.setScale(4.0f,4.0f);
}
	
int Player::GetScore(void)
{
	return m_score;
}

void Player::Stretch(float factor, float dt)
{
	float scaleX = m_sprite.getScale().x;
	float scaleY = m_sprite.getScale().y;
	scaleX += ((1.0f - factor) - scaleX) * 5.0f * dt;
	scaleY += ((1.0f + factor) - scaleY) * 5.0f * dt;
	m_sprite.setScale(scaleX,scaleY);
}

void Player::Draw(sf::RenderWindow * window)
{
	window->draw(m_sprite);
	window->draw(m_info);
}

void Player::Update(bool up, bool down, float dt)
{
	if (m_info.getScale().x > 1.0f)
	{
		float scaleX = m_info.getScale().x;
		float scaleY = m_info.getScale().y;
		scaleX += (1.0f - scaleX) * 5.0f * dt;
		scaleY += (1.0f - scaleY) * 5.0f * dt;
		m_info.setScale(scaleX,scaleY);
	}
	
	if (up)
	{
		m_y -= dt * m_speed;
		if (m_y <= 0)
		{
			m_y = 0;
			Stretch(0.0f,dt);
		}
		else
		{
			Stretch(0.15f,dt);
		}
	}
	if (down)
	{
		m_y += dt * m_speed;
		if (m_y >= SCREEN_HEIGHT - m_height)
		{
			m_y = (float)(SCREEN_HEIGHT - m_height);
			Stretch(0.0f,dt);
		}
		else
		{
			Stretch(0.15f,dt);
		}
	}
	else
	{
		Stretch(0.0f,dt);
	}

	m_sprite.setPosition(GetPosition());
}
