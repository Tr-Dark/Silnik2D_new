#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SFML/Graphics.hpp>
#include "PrimitiveRenderer.h"
#include "LineSegment.h"


class GameObject {
public:
    virtual void update() = 0;             
    virtual void draw(sf::RenderWindow& window, PrimitiveRenderer& renderer) = 0;
    virtual ~GameObject() {}               
};

#endif // GAME_OBJECT_H
