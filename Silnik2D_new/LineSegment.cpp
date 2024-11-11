#include "LineSegment.h"

LineSegment::LineSegment(const Point2D& start, const Point2D& end) : start(start), end(end) {}

Point2D LineSegment::getStart() const {
    return start;
}

Point2D LineSegment::getEnd() const {
    return end;
}

void LineSegment::setStart(const Point2D& point) {
    start = point;
}

void LineSegment::setEnd(const Point2D& point) {
    end = point;
}

void LineSegment::draw(sf::RenderWindow& window, PrimitiveRenderer& renderer, sf::Color color, bool incremental) const {
    if (incremental) {
        renderer.drawLineIncremental(window, start, end, color);
    }
    else {
        renderer.drawLineBasic(window, start, end, color);
    }
}
