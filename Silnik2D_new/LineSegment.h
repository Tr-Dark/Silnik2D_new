#ifndef LINESEGMENT_H
#define LINESEGMENT_H


#include "Point2D.h"
//#include "DrawableObject.h"
//#include "TransformableObject.h"
#include "ShapeObject.h"
#define M_PI 3.14159265358979323846

class LineSegment : public ShapeObject {
private:
    Point2D startPoint;
    Point2D endPoint;

public:
    LineSegment(const Point2D& start, const Point2D& end);

    // Override methods
    void draw(sf::RenderWindow& window, PrimitiveRenderer& renderer, sf::Color color = sf::Color::White) override;
    void translate(float dx, float dy) override;
    void rotate(float angle) override;
    void scale(float factorX, float factorY) override;
    void update() override;

    // Additional methods
    Point2D getStartPoint() const;
    Point2D getEndPoint() const;
    void setStartPoint(const Point2D& point);
    void setEndPoint(const Point2D& point);
};

#endif // LINESEGMENT_H
