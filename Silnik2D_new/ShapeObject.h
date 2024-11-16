#ifndef SHAPE_OBJECT_H
#define SHAPE_OBJECT_H

#include "DrawableObject.h"
#include "TransformableObject.h"
#include "PrimitiveRenderer.h"

class ShapeObject : public DrawableObject, public TransformableObject {
public:
    virtual void draw(sf::RenderWindow& window, PrimitiveRenderer& renderer, sf::Color color = sf::Color::White) override = 0;
    virtual void translate(float dx, float dy) override = 0;
    virtual void rotate(float angle) override = 0;
    virtual void scale(float factorX, float factorY) override = 0;
};

#endif // SHAPE_OBJECT_H
