#ifndef __CANNON_H_
#define __CANNON_H_
#include "Laser.h"
#include <list>

namespace helicopter 
{

class Cannon : public Enemy
{
public:
	Cannon(void);
	Cannon(sf::Texture& texture, sf::Texture& TextureLaser, float x, float y, float width, float height);
	~Cannon(void);

	void Update(float dt);
	void Draw(sf::RenderWindow * window);
	void Shoot(void);

private:

	float m_fireRate;
	float m_timer;

	sf::Texture m_textureLaser;

	std::list<Laser*> lasers;
};

}
#endif

