#ifndef BITMAPOBJECT_H
#define BITMAPOBJECT_H

#include <SFML/Graphics.hpp>
#include "DrawableObject.h"
#include "TransformableObject.h"

class BitmapObject : public TransformableObject, public DrawableObject {
protected:
    sf::Sprite sprite;

public:
    BitmapObject();
    virtual void setTexture(const sf::Texture& texture); // Оновлено для прийому текстури
    virtual void setTextureRect(const sf::IntRect& rect);
    virtual void translate(float dx, float dy) = 0;
    virtual void rotate(float angle) = 0;
    virtual void scale(float factorX, float factorY) = 0;
};

#endif // BITMAPOBJECT_H
