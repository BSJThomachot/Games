// definition of the Portal class
#ifndef __PORTAl_H_
#define __PORTAL_H_
#include <SFML/Graphics.hpp> 
#include "Ball.h"

namespace portalpong
{

// Types of Portal
enum PortalType
{
	MOVE,
	INVERSE,
	SMALL,
	BIG,
	FAST,

	COUNT
};

// class Ball;

class Portal
{
public:
	Portal(void);
	Portal(sf::Texture& texture, float x, float y, int width, int height);
	~Portal(void);

	// getters and setters
	void SetPosition(float x, float y);
	void SetPosition(const sf::Vector2f& vPos);
	sf::Vector2f GetPosition(void);
	void SetWidth(int w);
	int GetWidth(void);
	void SetHeight(int h);
	int GetHeight(void);
	void SetType(PortalType type);
	PortalType GetType(void);
	void Pair(Portal * other);
	bool IsActive(void);
	void Activate(bool val);
	
	
	void Warp(Ball * ball);
	bool Intersects(Ball * ball);

	void Draw(sf::RenderWindow * window);
	void Update(Ball * ball);

private:
	// coordinates
	float m_x;
	float m_y;
	// dimensions
	int m_width;
	int m_height;
	// sprite of the portal
	sf::Sprite m_sprite;
	// the other portal linked to it
	Portal * m_other;
	// the type of the portal
	PortalType m_type;

	bool m_active;
	bool m_ready;


};

}

#endif 
