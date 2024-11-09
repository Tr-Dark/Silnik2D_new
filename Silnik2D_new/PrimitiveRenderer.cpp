/*
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
    // Implementacja rysowania przyrostowego
}
*/
#include "PrimitiveRenderer.h"

void PrimitiveRenderer::drawLineBresenham(sf::RenderWindow& window, const Point2D& p1, const Point2D& p2, sf::Color color) const {
    int x = p1.getX();
    int y = p1.getY();
    int dx = abs(p2.getX() - p1.getX());
    int dy = abs(p2.getY() - p1.getY());
    int sx = (p1.getX() < p2.getX()) ? 1 : -1;
    int sy = (p1.getY() < p2.getY()) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        sf::RectangleShape pixel(sf::Vector2f(1, 1));
        pixel.setPosition(x, y);
        pixel.setFillColor(color);
        window.draw(pixel);

        if (x == p2.getX() && y == p2.getY()) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x += sx; }
        if (e2 < dx) { err += dx; y += sy; }
    }
}

// Metoda przyrostowa
void PrimitiveRenderer::drawLineIncremental(sf::RenderWindow& window, const Point2D& p1, const Point2D& p2, sf::Color color) const {
    float x = p1.getX();
    float y = p1.getY();
    float dx = p2.getX() - p1.getX();
    float dy = p2.getY() - p1.getY();
    int steps = std::max(abs(dx), abs(dy));
    dx /= steps;
    dy /= steps;

    for (int i = 0; i <= steps; ++i) {
        sf::RectangleShape pixel(sf::Vector2f(1, 1));
        pixel.setPosition(x, y);
        pixel.setFillColor(color);
        window.draw(pixel);

        x += dx;
        y += dy;
    }
}

// Metoda rysowania okręgu (bez zmian)
void PrimitiveRenderer::drawCircle(sf::RenderWindow& window, const Point2D& center, float radius, sf::Color color) const {
    sf::CircleShape circle(radius);
    circle.setPosition(center.getX() - radius, center.getY() - radius);
    circle.setFillColor(sf::Color::Transparent);
    circle.setOutlineThickness(1);
    circle.setOutlineColor(color);
    window.draw(circle);
}
