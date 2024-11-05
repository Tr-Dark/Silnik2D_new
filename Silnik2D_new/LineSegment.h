
#ifndef LINESEGMENT_H
#define LINESEGMENT_H

#include "Point2D.h"
#include "PrimitiveRenderer.h"

class LineSegment {
public:
    LineSegment(const Point2D& p1, const Point2D& p2);
    Point2D getP1() const;
    Point2D getP2() const;
    void setP1(const Point2D& newP1);
    void setP2(const Point2D& newP2);
    void draw(sf::RenderWindow& window, PrimitiveRenderer& renderer, bool useIncremental = false) const;

private:
    Point2D p1, p2;
};

#endif
