#include "Player.h"

// empty constructor
Player::Player(void)
{

}

// constructor
Player::Player(sf::Texture& texture, float x, float y, float width, float height)
{
	this->sprite = sf::Sprite(texture);
	this->setPosition(x,y);
	this->sprite.setPosition(x,y);
	this->fWidth = width;
	this->fHeight = height;
}

// destructor
Player::~Player(void)
{
}


void Player::setPosition(float x, float y)
{
	this->fX = x;
	this->fY = y;
	this->sprite.setPosition(x,y);
}

void Player::setPosition(sf::Vector2f vPos)
{
	this->fX = vPos.x;
	this->fY = vPos.y;
	this->sprite.setPosition(vPos);
}


sf::Vector2f Player::getPosition(void)
{
	return sf::Vector2f(this->fX,this->fY);
}

void Player::setWidth(float w)
{
	this->fWidth = w;
}

float Player::getWidth(void)
{
	return this->fWidth;
}

void Player::setHeight(float h)
{
	this->fHeight = h;
}

float Player::getHeight(void)
{
	return this->fHeight;
}

void Player::draw(sf::RenderWindow * window)
{
	window->draw(this->sprite);
}
	
void Player::update(bool up, bool down, float dt)
{
	if (up)
	{
		this->fY -= dt * 100;
		if (this->fY <= 0)
		{
			this->fY = 0;
		}
	}
	if (down)
	{
		this->fY += dt * 100;
		if (this->fY >= SCREEN_HEIGHT - this->fHeight)
		{
			this->fY = SCREEN_HEIGHT - this->fHeight;
		}
	}
	// adjust sprite position
	this->sprite.setPosition(this->getPosition());
}
