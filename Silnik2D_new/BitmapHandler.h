#ifndef BITMAPHANDLER_H
#define BITMAPHANDLER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>

class BitmapHandler {
public:
    BitmapHandler();
    ~BitmapHandler();

    bool loadFromFile(const std::string& filename, int bitmapIndex);
    const sf::Texture& getTexture(int bitmapIndex) const;

private:
    std::vector<sf::Texture> textures; // Вектор для текстур
};

#endif // BITMAPHANDLER_H