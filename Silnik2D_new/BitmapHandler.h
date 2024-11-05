#ifndef BITMAPHANDLER_H
#define BITMAPHANDLER_H

#include <SFML/Graphics.hpp>
#include <string>

class BitmapHandler {
private:
    sf::Image bitmap1, bitmap2, bitmap3, bitmap4, bitmap5, bitmap6, bitmap7, bitmap8, bitmap9, bitmap10, bitmap11, bitmap12, bitmap13, bitmap14, bitmap15, bitmap16; // Dwie bitmapy
    sf::Texture texture1, texture2, texture3, texture4, texture5, texture6, texture7, texture8, texture9, texture10, texture11, texture12, texture13, texture14, texture15, texture16; // Dwie tekstury
public:
    BitmapHandler();
    bool loadFromFile(const std::string& filename, int bitmapIndex);
    const sf::Texture& getTexture(int bitmapIndex); 
};

#endif // BITMAPHANDLER_H