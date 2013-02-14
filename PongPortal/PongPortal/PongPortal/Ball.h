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
	// getters and setters
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
	// coordinates
	float m_x;
	float m_y;
	// direction
	int m_dirX;
	int m_dirY;
	// speed
	float m_speed;
	// scale
	float m_scale;

	// radius
	float m_dimension;
	// sprite of the ball
	sf::Sprite m_sprite;
	// is warpping
	bool m_warpping;
	// is colliding
	bool m_colliding;

	bool m_inGame;
	// a timer
	float m_timer;
	// Time info
	sf::Text m_timerText;
};

}

#endif 
