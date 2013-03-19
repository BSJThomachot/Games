#ifndef __ENEMY_H_
#define __ENEMY_H_
#include "Entity.h"

namespace helicopter {

class Enemy : public Entity
{
public:
	Enemy(void) {};
	Enemy(std::string name, float x, float y, float width, float height) : Entity(name,x,y,width,height) {};
	~Enemy(void) {};

	virtual void Update(float dt) = 0;
};

}

#endif 

