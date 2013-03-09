#include "FontManager.h"

using namespace helicopter;

FontManager *FontManager::m_Instance = 0;

FontManager* FontManager::GetInstance()
{
	if(m_Instance == 0)
	{
		m_Instance = new FontManager();
	}
	return m_Instance;
}

void FontManager::Destroy()
{
	if (m_Instance != 0)
	{
		delete m_Instance;
		m_Instance = 0;
	}
}

sf::Font& FontManager::GetFont(void)
{
	return m_font;
}

void FontManager::SetFont(std::string name)
{
	std::string FileName = "Fonts/" + name + ".ttf";
	m_font.loadFromFile(FileName);
}
