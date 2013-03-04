#include "Ufo.h"

using namespace helicopter;

Ufo::Ufo(void)
{
}

Ufo::Ufo(sf::Texture& texture, float x, float y, float width, float height) : Entity(texture,x,y,width,height)
{

}

Ufo::~Ufo(void)
{

}


void Ufo::Update(float dt)
{
	dt = 0;
}
