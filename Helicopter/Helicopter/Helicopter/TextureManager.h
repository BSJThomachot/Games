#ifndef __TEXTUREMANAGER_H_
#define __TEXTUREMANAGER_H_
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <map>
#include <string>

namespace helicopter {
// Singleton Class that stores Textures used in the game
class TextureManager
{
public:

	static TextureManager* m_Instance;
	static TextureManager* GetInstance();
	static void			Destroy();

	sf::Texture& GetTexture(std::string name);
	
private:

	TextureManager(void) {};
	~TextureManager(void) {};
	
	typedef std::map<std::string, sf::Texture> TextureMap;
	TextureMap textureList;

};

}

#endif