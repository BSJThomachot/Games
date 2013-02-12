#include "Portal.h"

// empty constructor
Portal::Portal(void)
{
}

// constructor
Portal::Portal(sf::Texture& texture, float x, float y, int width, int height)
{
	this->m_sprite = sf::Sprite(texture);
	this->SetPosition(x,y);
	this->m_sprite.setPosition(x,y);
	this->m_fWidth = width;
	this->m_fHeight = height;
	this->m_pOther = NULL;
	this->eType = MOVE;
	this->m_bActive = true;
}

// destructor
Portal::~Portal(void)
{
}

// set position with x and y
void Portal::SetPosition(float x, float y)
{
	this->m_fX = x;
	this->m_fY = y;
	this->m_sprite.setPosition(x,y);
}

// set position with a vector
void Portal::SetPosition(sf::Vector2f& vPos)
{
	this->m_fX = vPos.x;
	this->m_fY = vPos.y;
	this->m_sprite.setPosition(vPos);
}

// get position
sf::Vector2f Portal::GetPosition(void)
{
	return sf::Vector2f(this->m_fX,this->m_fY);
}

// set width
void Portal::SetWidth(int w)
{
	this->m_fWidth = w;
}

// get width
int Portal::GetWidth(void)
{
	return this->m_fWidth;
}

// set height
void Portal::SetHeight(int h)
{
	this->m_fHeight = h;
}

// get height
int Portal::GetHeight(void)
{
	return this->m_fHeight;
}

// set type
void Portal::SetType(PortalType type)
{
	this->eType = type;
}

// get type
Portal::PortalType Portal::GetType(void)
{
	return this->eType;
}

// is portal active?
bool Portal::IsActive(void)
{
	return this->m_bActive;
}

// de/activate portal
void Portal::Activate(bool val)
{
	this->m_bActive = val;
}

// pair portal to another one
void Portal::Pair(Portal * other)
{
	this->m_pOther = other;
}

// warp the ball 
void Portal::Warp(Ball * ball)
{
	// warp the ball
	ball->Warpping(true);
	if (this->eType == BIG)
	{
		// make ball bigger
		ball->SetScale(2.0f);
	}
	else if (this->eType == SMALL)
	{
		// make ball smaller
		ball->SetScale(0.5f);
	}
	else if (this->eType == INVERSE)
	{
		// invert directions!
		ball->SetDirection(ball->GetDirection()*-1);
	}
	else if (this->eType == FAST)
	{
		// faster!
		ball->SetSpeed(ball->GetSpeed()*1.5f);
	}
	// go to other portal
	ball->SetPosition(this->m_pOther->GetPosition());
}

// check if a ball is in the portal
bool Portal::Intersects(Ball * ball)
{
	return !((ball->GetPosition().x > this->m_fX + this->m_fWidth)
			||(ball->GetPosition().x + ball->GetDim() < this->m_fX)
			||(ball->GetPosition().y > this->m_fY + this->m_fHeight)
			||(ball->GetPosition().y + ball->GetDim() < this->m_fY));
}

// draw portal
void Portal::Draw(sf::RenderWindow * window)
{
	// draw if active
	if (this->m_bActive)
	{
		window->draw(this->m_sprite);
	}
}

// Update portal
void Portal::Update(Ball * ball, float dt)
{
	// if portal is active
	if (this->m_bActive)
	{
		// ball is inside the portal
		if (this->Intersects(ball))
		{
			// if the ball is not already warpping
			if (!ball->IsWarpping())
			{
				// warp ball!
				this->Warp(ball);
			}
		}
		else // if not
		{
			// if ball the other portal is not intersecting either
			if (!this->m_pOther->Intersects(ball))
			{
				ball->Warpping(false); // then set to false!
			}
		}
	}
}
