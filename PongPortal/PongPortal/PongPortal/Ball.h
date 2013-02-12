// definition of the ball class
#pragma once
#include "Player.h"
#include <SFML/Graphics.hpp>

class Ball
{
public:
	Ball(void);
	Ball(sf::Texture& texture, float x, float y, float radius);
	~Ball(void);
	// getters and setters
	void SetPosition(float x, float y);
	void SetPosition(sf::Vector2f& vPos);
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
	float m_fX;
	float m_fY;
	// direction
	int m_iDirX;
	int m_iDirY;
	// speed
	float m_fSpeed;
	// scale
	float m_fScale;

	// radius
	float m_fDimension;
	// sprite of the ball
	sf::Sprite m_sprite;
	// is warpping
	bool m_bWarpping;
	// is colliding
	bool m_colliding;

	bool binGame;
	// a timer
	float Timer;
	// time info
	sf::Text m_time;
};

