// definition of the ball class
#ifndef __BALL_H_
#define __BALL_H_
#include "Player.h"
#include <SFML/Graphics.hpp>

namespace portalpong
{

class Ball
{
public:
	Ball(void);
	Ball(sf::Texture& texture, float x, float y, float radius);
	~Ball(void);
	
	void SetPosition(float x, float y);
	void SetPosition(const sf::Vector2f& vPos);
	sf::Vector2f GetPosition(void);
	void SetDirection(int x, int y);
	void SetDirection(sf::Vector2i vPos);
	sf::Vector2i GetDirection(void);
	void SetSpeed(float s);
	float GetSpeed(void);
	void SetDim(float value);
	float GetDim(void);
	void SetScale(float s);
	float GetScale(void);

	void Warpping(bool val);
	bool IsWarpping(void);
	bool Intersects(Player * p);
	void Launch(void);

	void Draw(sf::RenderWindow * window);
	void Update(Player * p1, Player * p2, float dt);

private:
	
	float m_x;
	float m_y;
	int m_dirX;
	int m_dirY;
	float m_speed;
	float m_scale;

	float m_dimension;
	sf::Sprite m_sprite;
	bool m_warpping;
	bool m_colliding;

	bool m_inGame;
	float m_timer;
	sf::Text m_timerText;
};

}

#endif 
