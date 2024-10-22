#ifndef PRIMITIVERENDERER_H
#define PRIMITIVERENDERER_H

#include <SFML/Graphics.hpp>
#include "Point2D.h"
#include <vector>

class PrimitiveRenderer {
public:
    void drawLine(sf::RenderWindow& window, const Point2D& p1, const Point2D& p2, sf::Color color = sf::Color::White);
    void drawLineIncremental(sf::RenderWindow& window, const Point2D& p1, const Point2D& p2, sf::Color color = sf::Color::Red);
    void drawOpenPolyline(sf::RenderWindow& window, const std::vector<Point2D>& points, sf::Color color = sf::Color::White);
    void drawClosedPolyline(sf::RenderWindow& window, const std::vector<Point2D>& points, sf::Color color = sf::Color::White);
    void drawCircle(sf::RenderWindow& window, const Point2D& center, float radius, sf::Color color = sf::Color::White);
    void drawTriangle(sf::RenderWindow& window, const Point2D& p1, const Point2D& p2, const Point2D& p3, sf::Color color = sf::Color::White);
    void drawRectangle(sf::RenderWindow& window, const Point2D& topLeft, float width, float height, sf::Color color = sf::Color::White);
    void drawPolygon(sf::RenderWindow& window, const std::vector<Point2D>& points, sf::Color color = sf::Color::White);
};

#endif
