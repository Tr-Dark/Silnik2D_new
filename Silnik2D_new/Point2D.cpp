
#include "Point2D.h"

Point2D::Point2D(float x, float y) : x(x), y(y) {}

float Point2D::getX() const { return x; }
float Point2D::getY() const { return y; }

void Point2D::setX(float newX) { x = newX; }
void Point2D::setY(float newY) { y = newY; }

void Point2D::draw(sf::RenderWindow& window, sf::Color color) const {
    sf::CircleShape point(2);
    point.setPosition(x, y);
    point.setFillColor(color);
    window.draw(point);
}

