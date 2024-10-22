#include "LineSegment.h"

LineSegment::LineSegment(const Point2D& p1, const Point2D& p2) : p1(p1), p2(p2) {}

Point2D LineSegment::getP1() const {
    return p1;
}

Point2D LineSegment::getP2() const {
    return p2;
}

void LineSegment::setP1(const Point2D& newP1) {
    p1 = newP1;
}

void LineSegment::setP2(const Point2D& newP2) {
    p2 = newP2;
}

void LineSegment::draw(sf::RenderWindow& window, PrimitiveRenderer& renderer, bool useIncremental) const {
    if (useIncremental) {
        renderer.drawLineIncremental(window, p1, p2);
    }
    else {
        renderer.drawLine(window, p1, p2);
    }
}
