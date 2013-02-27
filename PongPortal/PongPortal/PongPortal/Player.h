// Definition of the Player class
#ifndef __PLAYER_H_
#define __PLAYER_H_
#include "Misc.h"
#include <SFML/Graphics.hpp>

namespace portalpong
{

class Player
{
private:

	float m_x;
	float m_y;
	int m_width;
	int m_height;
	sf::Sprite m_sprite;
	float m_speed;
	int m_score;
	sf::Text m_info;

public:
	Player(void);
	Player(sf::Texture& texture, float x, float y, int width, int height, sf::Font& font, int id);
	~Player(void);

	void SetPosition(float x, float y);
	void SetPosition(sf::Vector2f vPos);
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

}

#endif
