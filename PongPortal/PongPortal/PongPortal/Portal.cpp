#include "Portal.h"

using namespace portalpong;

// empty constructor
Portal::Portal(void)
{
}

// constructor
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
}

// destructor
Portal::~Portal(void)
{
}

// set position with x and y
void Portal::SetPosition(float x, float y)
{
	m_x = x;
	m_y = y;
	m_sprite.setPosition(x,y);
}

// set position with a vector
void Portal::SetPosition(const sf::Vector2f& vPos) 
{
	m_x = vPos.x;
	m_y = vPos.y;
	m_sprite.setPosition(vPos);
}

// get position
sf::Vector2f Portal::GetPosition(void)
{	
	return sf::Vector2f( m_x, m_y);
}

// set width
void Portal::SetWidth(int w)
{
	m_width = w;
}

// get width
int Portal::GetWidth(void)
{
	return m_width;
}

// set height
void Portal::SetHeight(int h)
{
	m_height = h;
}

// get height
int Portal::GetHeight(void)
{
	return m_height;
}

// set type
void Portal::SetType(PortalType type)
{
	m_type = type;
}

// get type
PortalType Portal::GetType(void)
{
	return m_type;
}

// is portal active?
bool Portal::IsActive(void)
{
	return m_active;
}

// de/activate portal
void Portal::Activate(bool val)
{
	m_active = val;
}

// pair portal to another one
void Portal::Pair(Portal * other)
{
	m_other = other;
}

// warp the ball 
void Portal::Warp(Ball * ball)
{
	// warp the ball
	ball->Warpping(true);
	if (m_type == BIG)
	{
		// make ball bigger
		ball->SetScale(2.0f);
	}
	else if (m_type == SMALL)
	{
		// make ball smaller
		ball->SetScale(0.5f);
	}
	else if (m_type == INVERSE)
	{
		// invert directions!
		ball->SetDirection(ball->GetDirection()*-1);
	}
	else if (m_type == FAST)
	{
		// faster!
		ball->SetSpeed(ball->GetSpeed()*1.5f);
	}
	// go to other portal
	ball->SetPosition(m_other->GetPosition());
}

// check if a ball is in the portal
bool Portal::Intersects(Ball * ball)
{
	return !((ball->GetPosition().x > m_x + m_width)
			||(ball->GetPosition().x + ball->GetDim() < m_x)
			||(ball->GetPosition().y > m_y + m_height)
			||(ball->GetPosition().y + ball->GetDim() < m_y));
}

// draw portal
void Portal::Draw(sf::RenderWindow * window)
{
	// draw if active
	if (m_active)
	{
		window->draw(m_sprite);
	}
}

// Update portal
void Portal::Update(Ball * ball)
{
	// if portal is active
	if (m_active)
	{
		// ball is inside the portal
		if (Intersects(ball))
		{
			// if the ball is not already warpping
			if (!ball->IsWarpping())
			{
				// warp ball!
				Warp(ball);
			}
		}
		else // if not
		{
			// if ball the other portal is not intersecting either
			if (!m_other->Intersects(ball))
			{
				ball->Warpping(false); // then set to false!
			}
		}
	}
}
