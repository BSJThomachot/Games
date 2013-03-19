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
	Cannon(std::string name, float x, float y, float width, float height);
	~Cannon(void);

	void Update(float dt);
	void Draw(sf::RenderWindow * window);
	void Shoot(void);

	std::list<Laser*> lasers;

private:

	float m_fireRate;
	float m_timer;

	sf::Vector2f m_laserSpawn;
};

}
#endif

