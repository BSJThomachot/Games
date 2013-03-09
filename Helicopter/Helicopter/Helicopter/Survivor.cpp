#include "Survivor.h"

using namespace helicopter;

Survivor::Survivor(void)
{
	m_help = sf::Text("Help!",FontManager::GetInstance()->GetFont());
	m_help.setPosition(GetPosition().x,GetPosition().y - 16.0f);	
	m_timer = 0;
	m_speechTime = 1.0f;
	m_isTalking = false;
	m_rescued = false;
}

Survivor::Survivor(std::string name, float x, float y, float width, float height) : Entity(name,x,y,width,height)
{
	m_help = sf::Text("Help!",FontManager::GetInstance()->GetFont());
	m_help.setPosition(GetPosition().x,GetPosition().y - 16.0f);
	m_help.setScale(0.5f,0.5f);
	m_timer = 0;
	m_speechTime = 1.0f;
	m_isTalking = false;
	m_rescued = false;
}



Survivor::~Survivor(void)
{
}

bool Survivor::isRescued(void)
{
	return m_rescued;
}


void Survivor::Rescue(bool value)
{
	m_rescued = value;
}

void Survivor::Draw(sf::RenderWindow * window)
{
	Entity::Draw(window);
	if (m_isTalking)
	{
		window->draw(m_help);
	}
}


void Survivor::Update(float dt)
{
	m_timer += dt;
	if (m_timer >= m_speechTime)
	{
		m_isTalking = !m_isTalking;
		m_timer = 0;
	}
}
