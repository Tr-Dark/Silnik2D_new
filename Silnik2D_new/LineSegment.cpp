#include "LineSegment.h"
#include <iostream>
#include <cmath>
#include <iostream>

/**
 * @brief Konstruktor klasy LineSegment, inicjalizuje początkowy i końcowy punkt odcinka.
 *
 * @param start Punkt początkowy odcinka.
 * @param end Punkt końcowy odcinka.
 */
LineSegment::LineSegment(const Point2D& start, const Point2D& end)
    : startPoint(start), endPoint(end) {}

/**
 * @brief Rysuje linię na oknie.
 *
 * @param window Okno renderowania.
 * @param renderer Obiekt do rysowania prymitywów.
 * @param color Kolor linii.
 */
void LineSegment::draw(sf::RenderWindow& window, PrimitiveRenderer& renderer, sf::Color color) {
    renderer.drawLineIncremental(window, startPoint, endPoint, color);
}

/**
 * @brief Przemieszcza linię o zadane wartości w osi X i Y.
 *
 * @param dx Przemieszczenie w osi X.
 * @param dy Przemieszczenie w osi Y.
 */
void LineSegment::translate(float dx, float dy) {
    startPoint.translate(dx, dy);
    endPoint.translate(dx, dy);
}

/**
 * @brief Obraca linię o zadany kąt.
 *
 * @param angle Kąt obrotu w stopniach.
 */
void LineSegment::rotate(float angle) {
    // Obliczanie środka linii
    float centerX = (startPoint.getX() + endPoint.getX()) / 2.0f;
    float centerY = (startPoint.getY() + endPoint.getY()) / 2.0f;

    float radians = angle * M_PI / 180.0f;

    // Obrót punktów wokół środka
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

/**
 * @brief Skaluje linię względem jej środka.
 *
 * @param factorX Skalowanie w osi X.
 * @param factorY Skalowanie w osi Y.
 */
void LineSegment::scale(float factorX, float factorY) {
    // Obliczanie środka linii
    float centerX = (startPoint.getX() + endPoint.getX()) / 2.0f;
    float centerY = (startPoint.getY() + endPoint.getY()) / 2.0f;

    // Skalowanie punktów względem środka
    auto scalePoint = [centerX, centerY, factorX, factorY](Point2D& point) {
        float scaledX = centerX + (point.getX() - centerX) * factorX;
        float scaledY = centerY + (point.getY() - centerY) * factorY;
        point.setX(scaledX);
        point.setY(scaledY);
        };

    scalePoint(startPoint);
    scalePoint(endPoint);
}

/**
 * @brief Aktualizuje stan odcinka. (Obecnie nie jest używane).
 */
void LineSegment::update() {}

/**
 * @brief Zwraca punkt początkowy odcinka.
 *
 * @return Punkt początkowy.
 */
Point2D LineSegment::getStartPoint() const {
    return startPoint;
}

/**
 * @brief Zwraca punkt końcowy odcinka.
 *
 * @return Punkt końcowy.
 */
Point2D LineSegment::getEndPoint() const {
    return endPoint;
}

/**
 * @brief Ustawia punkt początkowy odcinka.
 *
 * @param point Nowy punkt początkowy.
 */
void LineSegment::setStartPoint(const Point2D& point) {
    startPoint = point;
}

/**
 * @brief Ustawia punkt końcowy odcinka.
 *
 * @param point Nowy punkt końcowy.
 */
void LineSegment::setEndPoint(const Point2D& point) {
    endPoint = point;
}
