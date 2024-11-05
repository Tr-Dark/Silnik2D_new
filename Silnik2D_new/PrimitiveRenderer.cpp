
#include "PrimitiveRenderer.h"

void PrimitiveRenderer::drawLine(sf::RenderWindow& window, const Point2D& p1, const Point2D& p2, sf::Color color) {
    sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(p1.getX(), p1.getY()), color),
        sf::Vertex(sf::Vector2f(p2.getX(), p2.getY()), color)
    };
    window.draw(line, 2, sf::Lines);
}

void PrimitiveRenderer::drawCircle(sf::RenderWindow& window, const Point2D& center, float radius, sf::Color color) {
    sf::CircleShape circle(radius);
    circle.setPosition(center.getX() - radius, center.getY() - radius);
    circle.setFillColor(sf::Color::Transparent);
    circle.setOutlineThickness(1);
    circle.setOutlineColor(color);
    window.draw(circle);
}

void PrimitiveRenderer::drawLineIncremental(sf::RenderWindow& window, const Point2D& p1, const Point2D& p2, sf::Color color) {
    // Implementacja rysowania przyrostowego, np. algorytmem Bresenhama lub prostym przyrostowym.
}
