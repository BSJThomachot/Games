#ifndef __LASER_H_
#define __LASER_H_
#include "Player.h"
#include "Enemy.h"

namespace helicopter
{

class Laser : public Enemy
{
public:
	Laser(void);
	Laser(std::string name, float x, float y, float width, float height);
	~Laser(void);

	void Update(float dt, Player * p);

private:

	float m_speed;
};

}

#endif

