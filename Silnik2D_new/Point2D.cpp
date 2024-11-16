#include "Point2D.h"
#include <cmath>
#include <iostream>
#define M_PI 3.14159265358979323846

Point2D::Point2D(float x, float y) : x(x), y(y) {
    //std::cout << "Point2D constructor\n";
}

float Point2D::getX() const {
    return x;
}

float Point2D::getY() const {
    return y;
}

void Point2D::setX(float x) {
    this->x = x;
}

void Point2D::setY(float y) {
    this->y = y;
}

void Point2D::translate(float dx, float dy) {
    x += dx;
    y += dy;
}

void Point2D::rotate(float angle) {
    /*float radians = angle * M_PI / 180.0f;
    float translatedX = x - origin.x;
    float translatedY = y - origin.y;

    float rotatedX = translatedX * cos(radians) - translatedY * sin(radians);
    float rotatedY = translatedX * sin(radians) + translatedY * cos(radians);

    x = rotatedX + origin.x;
    y = rotatedY + origin.y;*/
}

void Point2D::scale(float factorX, float factorY) {
    x *= factorX;
    y *= factorY;
}

void Point2D::update() {
    // Поки що пустий метод, але він може містити оновлення анімації або фізичних властивостей
}

void Point2D::draw(sf::RenderWindow& window, PrimitiveRenderer& renderer, sf::Color color) {
    sf::Vertex point(sf::Vector2f(x, y), color);
    window.draw(&point, 1, sf::Points);
}

bool Point2D::isWithinBounds(float dx, float dy, float windowWidth, float windowHeight) const {
    // Обчислюємо нові координати точки
    float newX = x + dx;
    float newY = y + dy;

    // Перевіряємо, чи залишаються координати в межах екрану
    return (newX >= 0 && newX <= windowWidth && newY >= 0 && newY <= windowHeight);
}