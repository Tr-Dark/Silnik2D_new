#ifndef PRIMITIVE_RENDERER_H
#define PRIMITIVE_RENDERER_H

#include <SFML/Graphics.hpp>
//#include "Point2D.h"
//#include "LineSegment.h"
#include <vector>

class LineSegment;
class Point2D;

class PrimitiveRenderer {
public:
    PrimitiveRenderer();
    void drawLineIncremental(sf::RenderTarget& window, const Point2D& p1, const Point2D& p2, sf::Color color);
    void drawPolyline(sf::RenderWindow& window, const std::vector<Point2D>& points, sf::Color color, bool closed = false);
    void drawLineBasic(sf::RenderWindow& window, const Point2D& p1, const Point2D& p2, sf::Color color);
    void drawCircle(sf::RenderWindow& window, const Point2D& center, int radius, sf::Color color);
    void drawEllipse(sf::RenderWindow& window, const Point2D& center, int radiusX, int radiusY, sf::Color color);
    bool drawPolygon(sf::RenderWindow& window, const std::vector<Point2D>& points, sf::Color color, bool closed = true);
    void drawFilledCircle(sf::RenderWindow& window, const Point2D& center, int radius, sf::Color color);
    void borderFill(sf::RenderTexture& renderTexture, int startX, int startY, sf::Color fillColor, sf::Color boundaryColor);
    void floodFill(sf::RenderWindow& window, int x, int y, sf::Color fillColor, sf::Color oldColor);
    void drawFilledPolygon(sf::RenderWindow& window, const std::vector<Point2D>& points, sf::Color fillColor);
    void drawFilledPolygonWithBorderFill(sf::RenderWindow& window, const std::vector<Point2D>& points, sf::Color fillColor);
    static void scalePolygon(std::vector<Point2D>& polygon, float scaleX, float scaleY);
private:
    bool checkForIntersections(const std::vector<LineSegment>& segments);
    bool doIntersect(const Point2D& p1, const Point2D& q1, const Point2D& p2, const Point2D& q2);

};

#endif // PRIMITIVE_RENDERER_H
