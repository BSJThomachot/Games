// definition of the Portal class
#pragma once
#include <SFML/Graphics.hpp> 
#include "Ball.h"
class Portal
{
public:
	Portal(void);
	Portal(sf::Texture& texture, float x, float y, int width, int height);
	~Portal(void);

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
	// getters and setters
	void SetPosition(float x, float y);
	void SetPosition(sf::Vector2f& vPos);
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
	void Update(Ball * ball, float dt);

private:
	// coordinates
	float m_fX;
	float m_fY;
	// dimensions
	int m_fWidth;
	int m_fHeight;
	// sprite of the portal
	sf::Sprite m_sprite;
	// the other portal linked to it
	Portal * m_pOther;
	// the type of the portal
	PortalType eType;

	bool m_bActive;
	bool m_bReady;


};

