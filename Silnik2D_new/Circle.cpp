
#include "Circle.h"

// Konstruktor
Circle::Circle(Point2D center, float radius) : center(center), radius(radius) {}

// Metoda rysuj¹ca okr¹g na oknie
void Circle::draw(sf::RenderWindow& window) {
    sf::CircleShape circleShape(radius);
    // Ustawienie pozycji okrêgu w odniesieniu do jego œrodka
    circleShape.setPosition(center.getX() - radius, center.getY() - radius);
    circleShape.setFillColor(sf::Color::Green); // Kolor wype³nienia
    circleShape.setOutlineColor(sf::Color::Black); // Kolor obramowania
    circleShape.setOutlineThickness(2); // Gruboœæ obramowania
    window.draw(circleShape);
}

// Metoda przesuwaj¹ca okr¹g o wektor (dx, dy)
void Circle::translate(float dx, float dy) {
    center.setX(center.getX() + dx);
    center.setY(center.getY() + dy);
}

// Metoda do obrotu, pozostaje pusta, poniewa¿ okr¹g nie zmienia kszta³tu po obrocie
void Circle::rotate(float angle) {
    // Okr¹g nie ma zmiany kszta³tu podczas obrotu, wiêc ta metoda mo¿e pozostaæ pusta
}

// Metoda skali zmieniaj¹ca promieñ okrêgu
void Circle::scale(float factor) {
    radius *= factor;
}
