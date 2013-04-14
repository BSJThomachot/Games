#include "Portal.h"

using namespace portalpong;


Portal::Portal(void)
{
}


Portal::Portal(sf::Texture& texture, float x, float y, int width, int height)
{
	m_sprite = sf::Sprite(texture);
	SetPosition(x,y);
	m_sprite.setPosition(x,y);
	m_width = width;
	m_height = height;
	m_other = NULL;
	m_type = MOVE;
	m_active = true;
	SetScale(0.15f);
}


Portal::~Portal(void)
{
}


void Portal::SetPosition(float x, float y)
{
	m_x = x;
	m_y = y;
	m_sprite.setPosition(x,y);
}


void Portal::SetPosition(const sf::Vector2f& vPos) 
{
	m_x = vPos.x;
	m_y = vPos.y;
	m_sprite.setPosition(vPos);
}


sf::Vector2f Portal::GetPosition(void)
{	
	return sf::Vector2f( m_x, m_y);
}


void Portal::SetWidth(int w)
{
	m_width = w;
}


int Portal::GetWidth(void)
{
	return m_width;
}


void Portal::SetHeight(int h)
{
	m_height = h;
}


int Portal::GetHeight(void)
{
	return m_height;
}


void Portal::SetType(PortalType type)
{
	m_type = type;
}


PortalType Portal::GetType(void)
{
	return m_type;
}


bool Portal::IsActive(void)
{
	return m_active;
}


void Portal::Activate(bool val)
{
	m_active = val;
}


void Portal::Pair(Portal * other)
{
	m_other = other;
}

void Portal::SetScale(float scale)
{
	m_sprite.setScale(scale,scale);
	m_scale = scale;
}

float Portal::GetScale(void)
{
	return m_scale;
}


void Portal::Warp(Ball * ball)
{
	// warp the ball
	ball->Warpping(true);
	if (m_type == BIG)
	{
		ball->SetScale(2.0f);
	}
	else if (m_type == SMALL)
	{
		ball->SetScale(0.5f);
	}
	else if (m_type == INVERSE)
	{
		ball->SetDirection(ball->GetDirection()*-1);
	}
	else if (m_type == FAST)
	{
		ball->SetSpeed(ball->GetSpeed()*1.5f);
	}
	ball->SetPosition(m_other->GetPosition());
}

// check if a ball is in the portal
bool Portal::Intersects(Ball * ball)
{
	if (m_x > ball->GetPosition().x + ball->GetDim() || ball->GetPosition().x > m_x + (float)m_width*m_scale)
	{
		return false;
	}
	if (m_y > ball->GetPosition().y + ball->GetDim()  || ball->GetPosition().y > m_y + (float)m_height*m_scale)
	{
		return false;
	}
	
	return true;
}

void Portal::Draw(sf::RenderWindow * window)
{
	if (m_scale > 0.1f)
	{
		window->draw(m_sprite);
	}
}

void Portal::Update(Ball * ball, float dt)
{
	if (m_active)
	{
		if (m_scale < 1)
		{
			m_scale += (1.0f - m_scale) * 10.0f * dt;
			SetScale(m_scale);
		}
		
		if (Intersects(ball))
		{
			if (!ball->IsWarpping())
			{
				Warp(ball);
			}
		}
		else 
		{
			if (!m_other->Intersects(ball))
			{
				ball->Warpping(false);
			}
		}
	}
	else
	{
		if (m_scale > 0.1f)
		{
			m_scale += (0.05f - m_scale) * 10.0f * dt;
			SetScale(m_scale);

			if (Intersects(ball))
			{
				if (!ball->IsWarpping())
				{
					Warp(ball);
				}
			}
			else 
			{
				if (!m_other->Intersects(ball))
				{
					ball->Warpping(false);
				}
			}
		}
	}
}
