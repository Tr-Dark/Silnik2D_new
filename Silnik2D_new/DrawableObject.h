#ifndef DRAWABLE_OBJECT_H
#define DRAWABLE_OBJECT_H

#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include "PrimitiveRenderer.h"
#include "LineSegment.h"

class DrawableObject : public virtual GameObject {
public:
    virtual void draw(sf::RenderWindow& window, PrimitiveRenderer& renderer, sf::Color color = sf::Color::White) = 0;
};

#endif // DRAWABLE_OBJECT_H
