#include "Ball.h"

using namespace portalpong;

Ball::Ball(void)
{
}


Ball::Ball(sf::Texture& texture, float x, float y, float radius)
{
	m_sprite = sf::Sprite(texture);
	SetPosition(x,y);
	m_sprite.setPosition(x,y);
	m_dimension = radius;
	m_dirX = 1;
	m_dirY = 1;

	m_speed = 200.0f;
	m_scale = 1.0f;

	m_inGame = false;
	m_timer = 3;

	m_warpping = false;
	m_colliding = false;

}


Ball::~Ball(void)
{
}


void Ball::SetPosition(float x, float y)
{
	m_x = x;
	m_y = y;
}


void Ball::SetPosition(const sf::Vector2f& vPos)
{
	m_x = vPos.x;
	m_y = vPos.y;
}


sf::Vector2f Ball::GetPosition(void)
{
	return sf::Vector2f( m_x, m_y);
}


void Ball::SetDirection( int x, int y)
{
	m_dirX = x;
	m_dirY = y;
}


void Ball::SetDirection(sf::Vector2i vDir)
{
	m_dirX = vDir.x;
	m_dirY = vDir.y;
}


sf::Vector2i Ball::GetDirection(void)
{
	return sf::Vector2i( m_dirX, m_dirY);
}


void Ball::SetSpeed(float s)
{
	m_speed = s;
}


float Ball::GetSpeed(void)
{
	return m_speed;
}


void Ball::SetDim(float value)
{
	m_dimension = value;
}


float Ball::GetDim(void)
{
	return m_dimension * m_scale;
}


void Ball::SetScale(float s)
{
	m_sprite.setScale(s,s);
	m_scale = s;
}


float Ball::GetScale(void)
{
	return m_scale;
}


void Ball::Warpping(bool val)
{
	m_warpping = val;
}


bool Ball::IsWarpping(void)
{
	return m_warpping;
}


bool Ball::Intersects(Player * p)
{
	if (m_x > p->GetPosition().x + p->GetWidth() || p->GetPosition().x > m_x + m_dimension)
	{
		return false;
	}
	if (m_y > p->GetPosition().y + p->GetHeight() || p->GetPosition().y > m_y + m_dimension)
	{
		return false;
	}
	
	return true;
}


void Ball::Launch(void)
{	
	// back in the game!
	m_inGame = true;
	m_timer = 3;
	m_speed = 200.0f;
}


void Ball::Draw(sf::RenderWindow * window)
{
	window->draw(m_sprite);
	if (!m_inGame)
	{
		window->draw(m_timerText);
	}
}

// Update the ball
void Ball::Update(Player * p1, Player * p2, float dt)
{
	// if the ball is in game
	if (this->m_inGame)
	{
		if (m_sprite.getScale().x > m_scale)
		{
			float scaleX = m_sprite.getScale().x;
			float scaleY = m_sprite.getScale().y;
			scaleX += (m_scale - scaleX) * 10.0f * dt;
			scaleY += (m_scale - scaleY) * 10.0f * dt;
			m_sprite.setScale(scaleX,scaleY);
		}
		
		
		// update coordinates according to direction
		m_x += m_dirX*m_speed*dt;
		m_y += m_dirY*m_speed*dt;
		// check if getting out of the screen
		if (m_y > SCREEN_HEIGHT - 32)
		{
			m_y = SCREEN_HEIGHT - 32;
			m_dirY *= -1;
			m_sprite.setScale(m_scale*1.25f,m_scale*1.25f);
		}
		else if (m_y < 0)
		{
			m_y = 0;
			m_dirY *= -1;
			m_sprite.setScale(m_scale*1.25f,m_scale*1.25f);
		}
		// Score!
		else if (m_x > SCREEN_WIDTH - 32)
		{
			p1->SetScore(p1->GetScore() + 1);
			m_inGame = false;
			// reset position
			SetPosition(SCREEN_WIDTH/2 - m_dimension/2,SCREEN_HEIGHT/2 - m_dimension/2);
			// reset scale
			SetScale(1.0f);
			// face other player
			m_dirX = -1;
		}
		else if (m_x < 0)
		{
			p2->SetScore(p2->GetScore() + 1);
			m_inGame = false;
			// reset position
			SetPosition(SCREEN_WIDTH/2 - m_dimension/2,SCREEN_HEIGHT/2 - m_dimension/2);
			// reset scale
			SetScale(1.0f);
			// face other player
			m_dirX = 1;
		} 
		else if (Intersects(p1) || Intersects(p2))
		{
			// if already colling
			if (m_colliding)
			{
				m_dirY *= -1;
				m_colliding = false;
			}
			else
			{
				// bounce
				m_dirX *= -1;
				// and increase speed! 
				m_speed *= 1.1f;
				// is colliding
				m_colliding = true;
				m_sprite.setScale(m_scale*1.25f,m_scale*1.25f);
			}
		}
		else
		{
			m_colliding = false;
		}
	}
	else // not in game
	{
		m_timer -= dt;
		int second = (int)m_timer + 1;
		char buf[32]; 
		sprintf_s(buf,32,"%i",second);
		m_timerText.setString(sf::String(buf));
		m_timerText.setPosition( SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
		if (m_timer < 0)
		{
			Launch();
		}
	}

	m_sprite.setPosition( m_x, m_y);
}
