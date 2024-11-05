
#include "Circle.h"

// Konstruktor
Circle::Circle(Point2D center, float radius) : center(center), radius(radius) {}

// Metoda rysuj�ca okr�g na oknie
void Circle::draw(sf::RenderWindow& window) {
    sf::CircleShape circleShape(radius);
    // Ustawienie pozycji okr�gu w odniesieniu do jego �rodka
    circleShape.setPosition(center.getX() - radius, center.getY() - radius);
    circleShape.setFillColor(sf::Color::Green); // Kolor wype�nienia
    circleShape.setOutlineColor(sf::Color::Black); // Kolor obramowania
    circleShape.setOutlineThickness(2); // Grubo�� obramowania
    window.draw(circleShape);
}

// Metoda przesuwaj�ca okr�g o wektor (dx, dy)
void Circle::translate(float dx, float dy) {
    center.setX(center.getX() + dx);
    center.setY(center.getY() + dy);
}

// Metoda do obrotu, pozostaje pusta, poniewa� okr�g nie zmienia kszta�tu po obrocie
void Circle::rotate(float angle) {
    // Okr�g nie ma zmiany kszta�tu podczas obrotu, wi�c ta metoda mo�e pozosta� pusta
}

// Metoda skali zmieniaj�ca promie� okr�gu
void Circle::scale(float factor) {
    radius *= factor;
}
