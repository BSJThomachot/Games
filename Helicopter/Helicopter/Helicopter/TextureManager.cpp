#include "TextureManager.h"
#include <hash_map>
#include <string.h>

using namespace helicopter;

TextureManager *TextureManager::m_Instance = 0;

TextureManager* TextureManager::GetInstance()
{
	if(m_Instance == 0)
	{
		m_Instance = new TextureManager();
	}
	return m_Instance;
}

void TextureManager::Destroy()
{
	if (m_Instance != 0)
	{
		delete m_Instance;
		m_Instance = 0;
	}
}

sf::Texture& TextureManager::GetTexture(std::string name)
{
	TextureMap::iterator it = textureList.find(name);
	if(it != textureList.end())
	{
		return it->second;
	}

	std::string FileName = "Images/" + name + ".png";

	sf::Texture newTexture;
	if (newTexture.loadFromFile(FileName))
	{
		textureList[name] = newTexture;
	}

	return textureList[name];
}
 
