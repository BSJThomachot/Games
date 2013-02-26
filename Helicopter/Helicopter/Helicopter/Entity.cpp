#include "Entity.h"


Entity::Entity(void)
{
}

Entity::Entity(sf::Texture& texture, float x, float y, float width, float height)
{
	m_img = sf::Sprite(texture);
	SetPosition(x,y);
	m_img.setPosition(x,y);
	m_width = width;
	m_height = height;
}

Entity::~Entity(void)
{
}

void Entity::SetPosition(float x, float y)
{
	m_x = x;
	m_y = y;
	m_position.x = x;
	m_position.y = y;
}

void Entity::SetPosition(const sf::Vector2f& Pos)
{
	m_x = Pos.x;
	m_y = Pos.y;
	m_position.x = Pos.x;
	m_position.y = Pos.y;
}

sf::Vector2f Entity::GetPosition(void)
{
	return m_position;
}

void Entity::SetSprite(sf::Sprite sprite)
{
	m_img = sprite;
}

sf::Sprite Entity::GetSprite(void)
{
	return m_img;
}

void Entity::SetWidth(float w)
{
	m_width = w;
}

float Entity::GetWidth(void)
{
	return m_width;
}

void Entity::SetHeight(float h)
{
	m_height = h;
}

float Entity::GetHeight(void)
{
	return m_height;
}

void Entity::Draw(sf::RenderWindow * window)
{
	window->draw(m_img);
}
