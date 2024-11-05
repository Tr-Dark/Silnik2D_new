#include "Circle.h"


Circle::Circle(Point2D center, float radius) : center(center), radius(radius) {}


void Circle::draw(sf::RenderWindow& window) {
    sf::CircleShape circleShape(radius);

    circleShape.setPosition(center.getX() - radius, center.getY() - radius);
    circleShape.setFillColor(sf::Color::Green); 
    circleShape.setOutlineColor(sf::Color::Black); 
    circleShape.setOutlineThickness(2); 
    window.draw(circleShape);
}


void Circle::translate(float dx, float dy) {
    center.setX(center.getX() + dx);
    center.setY(center.getY() + dy);
}


void Circle::rotate(float angle) {
      //pusta 
}


void Circle::scale(float factor) {
    radius *= factor;
}
