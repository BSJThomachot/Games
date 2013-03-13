#ifndef __PLAYER_H_
#define __PLAYER_H_
#include "Entity.h"
#include "FontManager.h"

namespace helicopter
{

class Player : public Entity
{
public:
	Player(void);
	Player(std::string name, float x, float y, float width, float height);
	~Player(void);

	bool IsDead(void);
	void Dead(bool value);
	void SetScore(float value);
	float GetScore(void);

	void Restart(float x, float y);
	void Update(float dt, bool up);
	void Draw(sf::RenderWindow * window);

private:
	float m_velocityX;
	float m_velocityY;
	sf::Vector2f m_velocity;

	float m_score;
	float m_distance;

	bool m_dead;

	float m_delay;
	float m_textTimer;
	float m_textTime;
	sf::Text m_info;
	sf::Text m_scoreInfo;
};

}
#endif

