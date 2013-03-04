#ifndef __UFO_H_
#define __UFO_H_
#include "Entity.h"

namespace helicopter
{

class Ufo : public Entity
{
public:
	Ufo(void);
	Ufo(sf::Texture& texture, float x, float y, float width, float height);
	~Ufo(void);

	void Update(float dt);
};

}

#endif 
