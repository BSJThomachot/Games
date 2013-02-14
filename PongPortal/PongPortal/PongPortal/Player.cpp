#include "Player.h"

using namespace portalpong;

// empty constructor
Player::Player(void)
{

}

// constructor
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
	m_speed = 250;
}

// destructor
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
}
	
int Player::GetScore(void)
{
	return m_score;
}

void Player::Draw(sf::RenderWindow * window)
{
	// printing player's sprite
	window->draw(m_sprite);
	// then info
	window->draw(m_info);
}

// update player
void Player::Update(bool up, bool down, float dt)
{
	if (up)
	{
		m_y -= dt * m_speed;
		if (m_y <= 0)
		{
			m_y = 0;
		}
	}
	if (down)
	{
		m_y += dt * m_speed;
		if (m_y >= SCREEN_HEIGHT - m_height)
		{
			m_y = (float)(SCREEN_HEIGHT - m_height);
		}
	}
	// adjust sprite position
	m_sprite.setPosition(GetPosition());
}
