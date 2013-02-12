#include "Player.h"

// empty constructor
Player::Player(void)
{

}

// constructor
Player::Player(sf::Texture& texture, float x, float y, int width, int height, sf::Font& font, int id)
{
	this->m_sprite = sf::Sprite(texture);
	this->SetPosition(x,y);
	this->m_sprite.setPosition(x,y);
	this->m_fWidth = width;
	this->m_fHeight = height;
	this->m_iScore = 0;
	this->m_Info = sf::Text("0",font);
	this->m_Info.setPosition((float)(SCREEN_WIDTH/3 * id),0);
	this->m_fSpeed = 250;
}

// destructor
Player::~Player(void)
{
}


void Player::SetPosition(float x, float y)
{
	this->m_fX = x;
	this->m_fY = y;
	this->m_sprite.setPosition(x,y);
}

void Player::SetPosition(sf::Vector2f& vPos)
{
	this->m_fX = vPos.x;
	this->m_fY = vPos.y;
	this->m_sprite.setPosition(vPos);
}


sf::Vector2f Player::GetPosition(void)
{
	return sf::Vector2f(this->m_fX,this->m_fY);
}

void Player::SetWidth(int w)
{
	this->m_fWidth = w;
}

int Player::GetWidth(void)
{
	return this->m_fWidth;
}

void Player::SetHeight(int h)
{
	this->m_fHeight = h;
}

int Player::GetHeight(void)
{
	return this->m_fHeight;
}

void Player::SetScore(int s)
{
	this->m_iScore = s;
	char buf[32];
	sprintf(buf,"%i",s);
	this->m_Info.setString(sf::String(buf));
}
	
int Player::GetScore(void)
{
	return this->m_iScore;
}

void Player::Draw(sf::RenderWindow * window)
{
	// printing player's sprite
	window->draw(this->m_sprite);
	// then info
	window->draw(this->m_Info);
}

// update player
void Player::Update(bool up, bool down, float dt)
{
	if (up)
	{
		this->m_fY -= dt * this->m_fSpeed;
		if (this->m_fY <= 0)
		{
			this->m_fY = 0;
		}
	}
	if (down)
	{
		this->m_fY += dt * this->m_fSpeed;
		if (this->m_fY >= SCREEN_HEIGHT - this->m_fHeight)
		{
			this->m_fY = (float)(SCREEN_HEIGHT - this->m_fHeight);
		}
	}
	// adjust sprite position
	this->m_sprite.setPosition(this->GetPosition());
}
