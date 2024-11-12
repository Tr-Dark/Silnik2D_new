#ifndef DRAWABLE_OBJECT_H
#define DRAWABLE_OBJECT_H

#include "GameObject.h"
#include <SFML/Graphics.hpp>

class DrawableObject : public virtual GameObject {
public:
    virtual void draw(sf::RenderWindow& window, PrimitiveRenderer& renderer) = 0;
};

#endif // DRAWABLE_OBJECT_H
