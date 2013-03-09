#ifndef __FONTMANAGER_H_
#define __FONTMANAGER_H_
#include <SFML/Graphics.hpp>

namespace helicopter {

class FontManager
{
public:

	static FontManager* m_Instance;
	static FontManager* GetInstance();
	static void			Destroy();

	sf::Font& GetFont(void);
	void SetFont(std::string name);
	
private:

	FontManager(void) {};
	~FontManager(void) {};
	
	sf::Font m_font;
};

}

#endif