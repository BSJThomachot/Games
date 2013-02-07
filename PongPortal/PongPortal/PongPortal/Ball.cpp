#include "Ball.h"


Ball::Ball(void)
{
}

Ball::Ball(sf::Texture& texture, float x, float y, float radius)
{
	this->sprite = sf::Sprite(texture);
	this->setPosition(x,y);
	this->sprite.setPosition(x,y);
	this->fRadius = radius;
	this->iDirX = 1;
	this->iDirY = 1;

	// start at 50 speed?
	this->fSpeed = 100;

}


Ball::~Ball(void)
{
}

void Ball::setPosition(float x, float y)
{
	this->fX = x;
	this->fY = y;
}

void Ball::setPosition(sf::Vector2f vPos)
{
	this->fX = vPos.x;
	this->fY = vPos.y;
}

sf::Vector2f Ball::getPosition(void)
{
	return sf::Vector2f(this->fX,this->fY);
}

void Ball::setDirection(int x, int y)
{
	this->iDirX = x;
	this->iDirY = y;
}

void Ball::setDirection(sf::Vector2i vDir)
{
	this->iDirX = vDir.x;
	this->iDirY = vDir.y;
}
	
sf::Vector2i Ball::getDirection(void)
{
	return sf::Vector2i(this->iDirX,this->iDirY);
}

void Ball::setRadius(float r)
{
	this->fRadius = r;
}

float Ball::getRadius(void)
{
	return this->fRadius;
}

void Ball::draw(sf::RenderWindow * window)
{
	window->draw(this->sprite);
}

void Ball::update(Player * p1, Player * p2, float dt)
{
	// update coordinates according to direction
	this->fX += this->iDirX*this->fSpeed*dt;
	this->fY += this->iDirY*this->fSpeed*dt;
	// check if getting out of the screen
	if (this->fY > SCREEN_HEIGHT - 32)
	{
		this->fY = SCREEN_HEIGHT - 32;
		this->iDirY *= -1;
	}
	else if (this->fY < 0)
	{
		this->fY = 0;
		this->iDirY *= -1;
	}
	// will have to score points, for now just boucing
	else if (this->fX > SCREEN_WIDTH - 32)
	{
		this->fX = SCREEN_WIDTH - 32;
		this->iDirX *= -1;
	}
	else if (this->fX < 0)
	{
		this->fX = 0;
		this->iDirX *= -1;
	} 
	else if (this->fX < p1->getPosition().x + p1->getWidth() &&
				this->fY > p1->getPosition().y && 
				this->fY < p1->getPosition().y + p1->getHeight())
	{
		this->iDirX *= -1;
		this->fSpeed += 5;
	}
	else if (this->fX + this->fRadius > p2->getPosition().x &&
				this->fY > p2->getPosition().y && 
				this->fY < p2->getPosition().y + p2->getHeight())
	{
		this->iDirX *= -1;
		this->fSpeed += 5;
	}


	// set sprite
	this->sprite.setPosition(this->fX,this->fY);

}
