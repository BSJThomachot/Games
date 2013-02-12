#include "Ball.h"

// default constructor
Ball::Ball(void)
{
}

// constructor
Ball::Ball(sf::Texture& texture, float x, float y, float radius)
{
	this->m_sprite = sf::Sprite(texture);
	this->SetPosition(x,y);
	this->m_sprite.setPosition(x,y);
	this->m_fDimension = radius;
	this->m_iDirX = 1;
	this->m_iDirY = 1;

	this->m_fSpeed = 200.0f;
	this->Timer = 0;
	this->m_fScale = 1.0f;

	this->binGame = false;
	this->Timer = 3;

	this->m_bWarpping = false;
	this->m_colliding = false;

}

// destructor
Ball::~Ball(void)
{
}

// set position with x and y
void Ball::SetPosition(float x, float y)
{
	this->m_fX = x;
	this->m_fY = y;
}

// set position with a vector
void Ball::SetPosition(sf::Vector2f& vPos)
{
	this->m_fX = vPos.x;
	this->m_fY = vPos.y;
}

// get position
sf::Vector2f Ball::GetPosition(void)
{
	return sf::Vector2f(this->m_fX,this->m_fY);
}

// set direction with x and y 
void Ball::SetDirection(int x, int y)
{
	this->m_iDirX = x;
	this->m_iDirY = y;
}

// set direction with a vector
void Ball::SetDirection(sf::Vector2i vDir)
{
	this->m_iDirX = vDir.x;
	this->m_iDirY = vDir.y;
}

// get direction
sf::Vector2i Ball::GetDirection(void)
{
	return sf::Vector2i(this->m_iDirX,this->m_iDirY);
}

// set speed
void Ball::SetSpeed(float s)
{
	this->m_fSpeed = s;
}

// get speed
float Ball::GetSpeed(void)
{
	return this->m_fSpeed;
}

// set dimension
void Ball::SetDim(float value)
{
	this->m_fDimension = value;
}

// get dimension of the ball
float Ball::GetDim(void)
{
	return this->m_fDimension * this->m_fScale;
}

// Set Scale
void Ball::SetScale(float s)
{
	this->m_sprite.setScale(s,s);
	this->m_fScale = s;
}

// get Scale
float Ball::GetScale(void)
{
	return this->m_fScale;
}

// warp or not the ball
void Ball::Warpping(bool val)
{
	this->m_bWarpping = val;
}

// is the ball being warpped?
bool Ball::IsWarpping(void)
{
	return this->m_bWarpping;
}

// check if intersects with player
bool Ball::Intersects(Player * p)
{
	return !((p->GetPosition().x > this->m_fX + this->GetDim())
			||(p->GetPosition().x + p->GetWidth() < this->m_fX)
			||(p->GetPosition().y > this->m_fY + this->GetDim())
			||(p->GetPosition().y + p->GetHeight() < this->m_fY));
}

// launch the ball
void Ball::Launch(void)
{	
	// back in the game!
	this->binGame = true;
	// reset timer
	this->Timer = 3;
	// reset speed
	this->m_fSpeed = 200.0f;
}

// Draw the ball
void Ball::Draw(sf::RenderWindow * window)
{
	window->draw(this->m_sprite);
	// draw countdown when appropriate
	if (!this->binGame)
	{
		window->draw(this->m_time);
	}
}

// Update the ball
void Ball::Update(Player * p1, Player * p2, float dt)
{
	// if the ball is in game
	if (this->binGame)
	{
		// update coordinates according to direction
		this->m_fX += this->m_iDirX*this->m_fSpeed*dt;
		this->m_fY += this->m_iDirY*this->m_fSpeed*dt;
		// check if getting out of the screen
		if (this->m_fY > SCREEN_HEIGHT - 32)
		{
			this->m_fY = SCREEN_HEIGHT - 32;
			this->m_iDirY *= -1;
		}
		else if (this->m_fY < 0)
		{
			this->m_fY = 0;
			this->m_iDirY *= -1;
		}
		// Score!
		else if (this->m_fX > SCREEN_WIDTH - 32)
		{
			p1->SetScore(p1->GetScore() + 1);
			this->binGame = false;
			// reset position
			this->SetPosition(SCREEN_WIDTH/2 - this->m_fDimension/2,SCREEN_HEIGHT/2 - this->m_fDimension/2);
			// reset scale
			this->SetScale(1.0f);
			// face other player
			this->m_iDirX = -1;
		}
		else if (this->m_fX < 0)
		{
			p2->SetScore(p2->GetScore() + 1);
			this->binGame = false;
			// reset position
			this->SetPosition(SCREEN_WIDTH/2 - this->m_fDimension/2,SCREEN_HEIGHT/2 - this->m_fDimension/2);
			// reset scale
			this->SetScale(1.0f);
			// face other player
			this->m_iDirX = 1;
		} 
		else if (this->Intersects(p1) || this->Intersects(p2))
		{
			// if already colling
			if (this->m_colliding)
			{
				this->m_iDirY *= -1;
				this->m_colliding = false;
			}
			else
			{
				// bounce
				this->m_iDirX *= -1;
				// and increase speed! 
				this->m_fSpeed *= 1.1f;
				// is colliding
				this->m_colliding = true;
			}
		}
		else
		{
			this->m_colliding = false;
		}
	}
	else // not in game
	{
		this->Timer -= dt;
		int second = (int)this->Timer + 1;
		char buf[32]; 
		sprintf(buf,"%i",second);
		this->m_time.setString(sf::String(buf));
		this->m_time.setPosition(SCREEN_WIDTH/2,SCREEN_HEIGHT/2);
		// countdown over!
		if (this->Timer < 0)
		{
			this->Launch();
		}
	}

	// set m_sprite
	this->m_sprite.setPosition(this->m_fX,this->m_fY);

}
