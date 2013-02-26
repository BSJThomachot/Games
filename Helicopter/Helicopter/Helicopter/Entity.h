#pragma once
#include <SFML/Graphics.hpp>
class Entity
{
public:
	Entity(void);
	Entity(sf::Texture& texture, float x, float y, float width, float height);
	virtual ~Entity(void);

	// getters and setters
	void SetPosition(float x, float y);
	void SetPosition(const sf::Vector2f& Pos);
	sf::Vector2f GetPosition(void);
	void SetSprite(sf::Sprite sprite);
	sf::Sprite GetSprite(void);
	void SetWidth(float w);
	float GetWidth(void);
	void SetHeight(float h);
	float GetHeight(void);

	void Draw(sf::RenderWindow * window);

private:
	// coordinates of the entity
	float m_x;
	float m_y;
	sf::Vector2f m_position;
	// image of the Entity
	sf::Sprite m_img;
	// dimension of the Entity
	float m_width;
	float m_height;
};

