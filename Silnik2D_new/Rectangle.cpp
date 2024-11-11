
#include "Rectangle.h"
#include <SFML/Graphics.hpp>
#include "BitmapHandler.h"

Rectangle::Rectangle(Point2D topLeft, float width, float height)
    : topLeft(topLeft), width(width), height(height), rectShape(sf::Vector2f(width, height)) {
    rectShape.setPosition(topLeft.getX(), topLeft.getY());
    rectShape.setFillColor(sf::Color(255, 255, 255, 0));
}


void Rectangle::setTexture(const sf::Texture& texture) {
    rectShape.setTexture(&texture);
}

void Rectangle::draw(sf::RenderWindow& window) {
    window.draw(rectShape);
}

void Rectangle::translate(float dx, float dy) {
    topLeft.setX(topLeft.getX() + dx);
    topLeft.setY(topLeft.getY() + dy);
    rectShape.setPosition(topLeft.getX(), topLeft.getY());
}

void Rectangle::rotate(float angle) {
    rectShape.rotate(angle);
}

void Rectangle::scale(float factor) {
    rectShape.setScale(factor, factor);
}

void Rectangle::updateSize(float newWidth, float newHeight) {
    width = newWidth;
    height = newHeight;
    rectShape.setSize(sf::Vector2f(width, height));
}
