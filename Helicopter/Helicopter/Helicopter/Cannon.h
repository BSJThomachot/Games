#ifndef __CANNON_H_
#define __CANNON_H_
#include "Entity.h"

namespace helicopter 
{

class Cannon : public Entity
{
public:
	Cannon(void);
	Cannon(sf::Texture& texture, float x, float y, float width, float height);
	~Cannon(void);
};

}
#endif

