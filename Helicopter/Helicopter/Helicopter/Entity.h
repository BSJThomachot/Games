#ifndef __ENTITY_H_
#define __ENTITY_H_
#include <SFML/Graphics.hpp>

namespace helicopter
{

class Entity
{
public:
	Entity(void);
	Entity(sf::Texture& texture, float x, float y, float width, float height);
	virtual ~Entity(void);

	void SetPosition(float x, float y);
	void SetPosition(const sf::Vector2f& Pos);
	sf::Vector2f GetPosition(void);
	void SetSprite(sf::Sprite sprite);
	sf::Sprite GetSprite(void);
	void SetWidth(float w);
	float GetWidth(void);
	void SetHeight(float h);
	float GetHeight(void);

	bool Collides(Entity * other);
	
	virtual void Draw(sf::RenderWindow * window);

private:

	float m_x;
	float m_y;
	sf::Vector2f m_position;
	sf::Sprite m_image;
	float m_width;
	float m_height;
};
}
#endif

