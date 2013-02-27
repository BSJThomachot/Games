#ifndef __PLAYER_H_
#define __PLAYER_H_
#include "Entity.h"

namespace helicopter
{

class Player : public Entity
{
public:
	Player(void);
	Player(sf::Texture& texture, float x, float y, float width, float height);
	~Player(void);

	void Update(float dt, bool up);

private:
	float m_velocityX;
	float m_velocityY;
	sf::Vector2f m_velocity;
};

}
#endif

