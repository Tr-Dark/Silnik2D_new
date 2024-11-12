//#ifndef POINT2D_H
//#define POINT2D_H
//
//#include <SFML/Graphics.hpp>
//
//class Point2D {
//private:
//    float x;
//    float y;
//
//public:
//    Point2D(float x = 0, float y = 0);
//
//    float getX() const;
//    float getY() const;
//
//    void setX(float x);
//    void setY(float y);
//
//    void draw(sf::RenderWindow& window, sf::Color color = sf::Color::White) const;
//};
//
//#endif 

#ifndef POINT2D_H
#define POINT2D_H

#include <SFML/Graphics.hpp>
#include "TransformableObject.h"

class Point2D : public TransformableObject {
private:
    float x;
    float y;
    sf::Vector2f origin;

public:
    Point2D(float x = 0, float y = 0);

    float getX() const;
    float getY() const;

    void setX(float x);
    void setY(float y);

    // Реалізація методів TransformableObject
    void translate(float dx, float dy) override;
    void rotate(float angle) override;
    void scale(float factorX, float factorY) override;
    void update() override;

    void draw(sf::RenderWindow& window, sf::Color color = sf::Color::White) const;
};

#endif // POINT2D_H
