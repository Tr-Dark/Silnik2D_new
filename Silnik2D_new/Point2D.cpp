
#include "Point2D.h"

Point2D::Point2D(float x, float y) : x(x), y(y) {}

float Point2D::getX() const {
    return x;
}

float Point2D::getY() const {
    return y;
}

void Point2D::setX(float x) {
    this->x = x;
}

void Point2D::setY(float y) {
    this->y = y;
}

void Point2D::draw(sf::RenderWindow& window, sf::Color color) const {
    sf::Vertex point(sf::Vector2f(x, y), color); 
    window.draw(&point, 1, sf::Points);           
}
