/*
#include "Rectangle.h"

// Konstruktor
Rectangle::Rectangle(Point2D topLeft, float width, float height)
    : topLeft(topLeft), width(width), height(height) {}

// Metoda rysuj�ca prostok�t
void Rectangle::draw(sf::RenderWindow& window) {
    sf::RectangleShape rectangleShape(sf::Vector2f(width, height));
    rectangleShape.setPosition(topLeft.getX(), topLeft.getY());
    rectangleShape.setFillColor(sf::Color::Blue); // Ustaw kolor wype�nienia
    rectangleShape.setOutlineColor(sf::Color::Black); // Ustaw kolor obramowania
    rectangleShape.setOutlineThickness(2); // Ustaw grubo�� obramowania
    window.draw(rectangleShape); // Rysowanie prostok�ta
}

// Metoda przesuwaj�ca prostok�t
void Rectangle::translate(float dx, float dy) {
    topLeft.setX(topLeft.getX() + dx);
    topLeft.setY(topLeft.getY() + dy);
}

// Metoda do obrotu (mo�na pozostawi� pust�, je�li nie jest u�ywana)
void Rectangle::rotate(float angle) {
    // Obr�t prostok�ta nie zmienia jego kszta�tu, wi�c ta metoda mo�e pozosta� pusta
}

// Metoda do skalowania prostok�ta
void Rectangle::scale(float factor) {
    width *= factor;
    height *= factor;
}
*/

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
    //window.draw(rectShape);
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
