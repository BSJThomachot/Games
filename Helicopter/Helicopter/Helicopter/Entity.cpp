#include "Entity.h"

using namespace helicopter;

Entity::Entity(void)
{
}

Entity::Entity(std::string name, float x, float y, float width, float height)
{
	m_image = sf::Sprite(TextureManager::GetInstance()->GetTexture(name));
	SetPosition(x,y);
	m_image.setPosition(x,y);
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
	m_image.setPosition(x,y);
}

void Entity::SetPosition(const sf::Vector2f& Pos)
{
	m_x = Pos.x;
	m_y = Pos.y;
	m_position.x = Pos.x;
	m_position.y = Pos.y;
	m_image.setPosition(Pos);
}

sf::Vector2f Entity::GetPosition(void)
{
	return m_position;
}

void Entity::SetSprite(sf::Sprite sprite)
{
	m_image = sprite;
}

sf::Sprite Entity::GetSprite(void)
{
	return m_image;
}

const sf::Texture* Entity::GetTexture() const
{
	return m_image.getTexture();
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

bool Entity::Collides(Entity * other)
{
	if (m_x > other->GetPosition().x + other->GetWidth() || other->GetPosition().x > m_x + m_width)
	{
		return false;
	}
	if (m_y > other->GetPosition().y + other->GetHeight() || other->GetPosition().y > m_y + m_height)
	{
		return false;
	}

	return true;
}

void Entity::Draw(sf::RenderWindow * window)
{
	window->draw(m_image);
}