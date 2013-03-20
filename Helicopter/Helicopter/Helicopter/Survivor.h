#ifndef __SURVIVOR_H_
#define __SURVIVOR_H_
#include "Player.h"
#include "FontManager.h"


namespace helicopter
{
class Survivor : public Entity
{
public:
	Survivor(void);
	Survivor(std::string name, float x, float y, float width, float height);
	~Survivor(void);

	void Draw(sf::RenderWindow * window);
	void Update(float dt, Player * p);

	bool isRescued(void);
	void Rescue(bool value);

private:

	sf::Text m_help;

	float m_timer;
	float m_speechTime;
	bool  m_isTalking;
	bool  m_rescued;

};

}

#endif 

