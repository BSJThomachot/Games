// Definition of the Player class
#pragma once
#include "Misc.h"
#include <SFML/Graphics.hpp>

class Player
{
private:
	// coordinates
	float m_fX;
	float m_fY;
	// dimensions
	int m_fWidth;
	int m_fHeight;
	// sprite of the player
	sf::Sprite m_sprite;
	// Speed of the player
	float m_fSpeed;
	// score of the player
	int m_iScore;
	// player's info
	sf::Text m_Info;

public:
	Player(void);
	Player(sf::Texture& texture, float x, float y, int width, int height, sf::Font& font, int id);
	~Player(void);

	// getters and setters
	void SetPosition(float x, float y);
	void SetPosition(sf::Vector2f& vPos);
	sf::Vector2f GetPosition(void);
	void SetWidth(int w);
	int GetWidth(void);
	void SetHeight(int h);
	int GetHeight(void);
	void SetScore(int s);
	int GetScore(void);
	

	void Draw(sf::RenderWindow * window);
	void Update(bool up, bool down, float dt);

};

