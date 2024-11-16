#include "LineSegment.h"
#include <iostream>
#include "LineSegment.h"
#include <cmath>
#include <iostream>

// Конструктор з параметрами
LineSegment::LineSegment(const Point2D& start, const Point2D& end)
    : startPoint(start), endPoint(end) {}

// Малювання лінії
void LineSegment::draw(sf::RenderWindow& window, PrimitiveRenderer& renderer, sf::Color color) {
    renderer.drawLineIncremental(window, startPoint, endPoint, color);
}

// Переміщення лінії
void LineSegment::translate(float dx, float dy) {
    startPoint.translate(dx, dy);
    endPoint.translate(dx, dy);
}

// Обертання лінії
void LineSegment::rotate(float angle) {
    // Знаходимо центр лінії
    float centerX = (startPoint.getX() + endPoint.getX()) / 2.0f;
    float centerY = (startPoint.getY() + endPoint.getY()) / 2.0f;

    float radians = angle * M_PI / 180.0f;

    // Обчислення нових координат
    auto rotatePoint = [centerX, centerY, radians](Point2D& point) {
        float x = point.getX() - centerX;
        float y = point.getY() - centerY;

        float rotatedX = x * cos(radians) - y * sin(radians) + centerX;
        float rotatedY = x * sin(radians) + y * cos(radians) + centerY;

        point.setX(rotatedX);
        point.setY(rotatedY);
        };

    rotatePoint(startPoint);
    rotatePoint(endPoint);
}

// Масштабування лінії
void LineSegment::scale(float factorX, float factorY) {
    // Знаходимо центр лінії
    float centerX = (startPoint.getX() + endPoint.getX()) / 2.0f;
    float centerY = (startPoint.getY() + endPoint.getY()) / 2.0f;

    // Масштабування відносно центру
    auto scalePoint = [centerX, centerY, factorX, factorY](Point2D& point) {
        float scaledX = centerX + (point.getX() - centerX) * factorX;
        float scaledY = centerY + (point.getY() - centerY) * factorY;
        point.setX(scaledX);
        point.setY(scaledY);
        };

    scalePoint(startPoint);
    scalePoint(endPoint);
}

void LineSegment::update()
{
}

// Отримання початкової точки
Point2D LineSegment::getStartPoint() const {
    return startPoint;
}

// Отримання кінцевої точки
Point2D LineSegment::getEndPoint() const {
    return endPoint;
}

// Встановлення початкової точки
void LineSegment::setStartPoint(const Point2D& point) {
    startPoint = point;
}

// Встановлення кінцевої точки
void LineSegment::setEndPoint(const Point2D& point) {
    endPoint = point;
}