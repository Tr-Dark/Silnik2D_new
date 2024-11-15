#ifndef BITMAPOBJECT_H
#define BITMAPOBJECT_H

#include <SFML/Graphics.hpp>

class BitmapObject {
protected:
    sf::Sprite sprite;

public:
    BitmapObject();
    virtual void setTexture(const sf::Texture& texture); // Оновлено для прийому текстури
    virtual void setTextureRect(const sf::IntRect& rect);
};

#endif // BITMAPOBJECT_H
