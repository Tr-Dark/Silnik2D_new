#include "PrimitiveRenderer.h"

void PrimitiveRenderer::drawLine(sf::RenderWindow& window, const Point2D& p1, const Point2D& p2, sf::Color color) {
    sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(p1.getX(), p1.getY()), color),
        sf::Vertex(sf::Vector2f(p2.getX(), p2.getY()), color)
    };
    window.draw(line, 2, sf::Lines);
}

void PrimitiveRenderer::drawLineIncremental(sf::RenderWindow& window, const Point2D& p1, const Point2D& p2, sf::Color color) {
    int x1 = static_cast<int>(p1.getX());
    int y1 = static_cast<int>(p1.getY());
    int x2 = static_cast<int>(p2.getX());
    int y2 = static_cast<int>(p2.getY());

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        sf::RectangleShape point(sf::Vector2f(1, 1));
        point.setPosition(static_cast<float>(x1), static_cast<float>(y1));
        point.setFillColor(color);
        window.draw(point);

        if (x1 == x2 && y1 == y2) break;

        int e2 = err * 2;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

void PrimitiveRenderer::drawOpenPolyline(sf::RenderWindow& window, const std::vector<Point2D>& points, sf::Color color) {
    for (size_t i = 0; i < points.size() - 1; ++i) {
        drawLine(window, points[i], points[i + 1], color);
    }
}

void PrimitiveRenderer::drawClosedPolyline(sf::RenderWindow& window, const std::vector<Point2D>& points, sf::Color color) {
    drawOpenPolyline(window, points, color);
    if (!points.empty()) {
        drawLine(window, points.back(), points.front(), color);
    }
}

void PrimitiveRenderer::drawCircle(sf::RenderWindow& window, const Point2D& center, float radius, sf::Color color) {
    sf::CircleShape circle(radius);
    circle.setPosition(center.getX() - radius, center.getY() - radius);  
    circle.setFillColor(sf::Color::Transparent);  
    circle.setOutlineThickness(1);
    circle.setOutlineColor(color);
    window.draw(circle);
}

void PrimitiveRenderer::drawTriangle(sf::RenderWindow& window, const Point2D& p1, const Point2D& p2, const Point2D& p3, sf::Color color) {
    sf::Vertex triangle[] = {
        sf::Vertex(sf::Vector2f(p1.getX(), p1.getY()), color),
        sf::Vertex(sf::Vector2f(p2.getX(), p2.getY()), color),
        sf::Vertex(sf::Vector2f(p3.getX(), p3.getY()), color)
    };
    window.draw(triangle, 3, sf::Triangles);
}

void PrimitiveRenderer::drawRectangle(sf::RenderWindow& window, const Point2D& topLeft, float width, float height, sf::Color color) {
    sf::RectangleShape rectangle(sf::Vector2f(width, height));
    rectangle.setPosition(topLeft.getX(), topLeft.getY());
    rectangle.setFillColor(sf::Color::Transparent);  
    rectangle.setOutlineThickness(1);
    rectangle.setOutlineColor(color);
    window.draw(rectangle);
}

void PrimitiveRenderer::drawPolygon(sf::RenderWindow& window, const std::vector<Point2D>& points, sf::Color color) {
    if (points.size() < 3) return;  

    sf::ConvexShape polygon;
    polygon.setPointCount(points.size());
    for (size_t i = 0; i < points.size(); ++i) {
        polygon.setPoint(i, sf::Vector2f(points[i].getX(), points[i].getY()));
    }
    polygon.setFillColor(sf::Color::Transparent);  
    polygon.setOutlineThickness(1);
    polygon.setOutlineColor(color);
    window.draw(polygon);
}
