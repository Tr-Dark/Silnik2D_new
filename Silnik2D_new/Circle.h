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
    Circle(Point2D center, float radius); 

    void draw(sf::RenderWindow& window) override; 
    void translate(float dx, float dy) override;   
    void rotate(float angle) override;              
    void scale(float factor) override;             
};

#endif // CIRCLE_H

