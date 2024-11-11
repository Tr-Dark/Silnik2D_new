#ifndef PRIMITIVE_RENDERER_H
#define PRIMITIVE_RENDERER_H

#include <SFML/Graphics.hpp>
#include "Point2D.h"

class PrimitiveRenderer {
public:
    void drawLineIncremental(sf::RenderWindow& window, const Point2D& p1, const Point2D& p2, sf::Color color);
    void drawPolyline(sf::RenderWindow& window, const std::vector<Point2D>& points, sf::Color color, bool closed = false);
    void drawLineBasic(sf::RenderWindow& window, const Point2D& p1, const Point2D& p2, sf::Color color);
};

#endif // PRIMITIVE_RENDERER_H
