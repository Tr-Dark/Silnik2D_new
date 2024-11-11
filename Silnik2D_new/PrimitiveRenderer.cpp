#include "PrimitiveRenderer.h"
#include <cmath> 

void PrimitiveRenderer::drawLineIncremental(sf::RenderWindow& window, const Point2D& p1, const Point2D& p2, sf::Color color) {
    int x0 = static_cast<int>(p1.getX());
    int y0 = static_cast<int>(p1.getY());
    int x1 = static_cast<int>(p2.getX());
    int y1 = static_cast<int>(p2.getY());

    int dx = x1 - x0;
    int dy = y1 - y0;

    // Sprawdzenie nachylenia odcinka
    bool steep = std::abs(dy) > std::abs(dx);

    if (steep) {
        // Jeśli nachylenie jest strome, zamieniamy x i y miejscami
        std::swap(x0, y0);
        std::swap(x1, y1);
        std::swap(dx, dy);
    }

    // Zapewnienie rysowania od lewej do prawej strony
    if (x0 > x1) {
        std::swap(x0, x1);
        std::swap(y0, y1);
        dx = x1 - x0;
        dy = y1 - y0;
    }

    // Obliczenie nachylenia
    float m = static_cast<float>(dy) / dx;
    float y = y0;

    // Główna pętla rysowania odcinka
    for (int x = x0; x <= x1; ++x) {
        if (steep) {
            // Jeśli nachylenie jest strome, rysujemy punkt z zamienionymi współrzędnymi
            sf::Vertex point(sf::Vector2f(y, x), color);
            window.draw(&point, 1, sf::Points);
        }
        else {
            // Jeśli nachylenie nie jest strome, rysujemy normalnie
            sf::Vertex point(sf::Vector2f(x, y), color);
            window.draw(&point, 1, sf::Points);
        }
        y += m;  // Przyrost y na podstawie nachylenia
    }
}

void PrimitiveRenderer::drawPolyline(sf::RenderWindow& window, const std::vector<Point2D>& points, sf::Color color, bool closed) {
    if (points.size() < 2) return;

    for (size_t i = 0; i < points.size() - 1; ++i) {
        drawLineIncremental(window, points[i], points[i + 1], color);
    }

    if (closed) {
        drawLineIncremental(window, points.back(), points.front(), color);
    }
}

void PrimitiveRenderer::drawLineBasic(sf::RenderWindow& window, const Point2D& p1, const Point2D& p2, sf::Color color) {
    sf::VertexArray line(sf::Lines, 2);

    line[0].position = sf::Vector2f(p1.getX(), p1.getY());
    line[0].color = color;

    line[1].position = sf::Vector2f(p2.getX(), p2.getY());
    line[1].color = color;

    window.draw(line);
}