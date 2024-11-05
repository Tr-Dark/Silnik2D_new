#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <SFML/Graphics.hpp>
#include "ShapeObject.h"
#include "Point2D.h"

class Rectangle : public ShapeObject {
private:
    Point2D topLeft;
    float width, height;
    sf::RectangleShape rectShape; 

public:
    Rectangle(Point2D topLeft, float width, float height);
    void setTexture(const sf::Texture& texture); 
    virtual void draw(sf::RenderWindow& window) override;
    void translate(float dx, float dy) override;
    void rotate(float angle) override;
    void scale(float factor) override;
    void updateSize(float newWidth, float newHeight); 
};

#endif // RECTANGLE_H




