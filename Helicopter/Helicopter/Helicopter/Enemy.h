#ifndef __ENEMY_H_
#define __ENEMY_H_
#include "entity.h"

namespace helicopter {

class Enemy : public Entity
{
public:
	Enemy(void) {};
	Enemy(sf::Texture& texture, float x, float y, float width, float height) : Entity(texture,x,y,width,height) {};
	~Enemy(void) {};

	virtual void Update(float dt) = 0;
};

}

#endif 

