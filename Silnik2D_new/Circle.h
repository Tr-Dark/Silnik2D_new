
#ifndef CIRCLE_H
#define CIRCLE_H

#include <SFML/Graphics.hpp>
#include "ShapeObject.h"
#include "Point2D.h"

class Circle : public ShapeObject {
private:
    Point2D center;
    float radius;

public:
    Circle(Point2D center, float radius); // Konstruktor

    void draw(sf::RenderWindow& window) override; // Implementacja metody draw
    void translate(float dx, float dy) override;   // Implementacja metody translate
    void rotate(float angle) override;              // Implementacja metody rotate
    void scale(float factor) override;              // Implementacja metody scale
};

#endif // CIRCLE_H

