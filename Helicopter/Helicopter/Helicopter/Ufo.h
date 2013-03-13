#ifndef __UFO_H_
#define __UFO_H_
#include "Enemy.h"

namespace helicopter
{

class Ufo : public Enemy
{
public:
	Ufo(void);
	Ufo(std::string name, float x, float y, float width, float height);
	~Ufo(void);

	void Update(float dt);

private: 

	float m_originY;
	float m_range;
	float m_speed;
	float m_timer;
};

}

#endif 
