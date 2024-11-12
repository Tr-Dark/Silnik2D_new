#define _USE_MATH_DEFINES // Додаємо для доступу до M_PI, якщо компілятор це підтримує
#include "Rectangle.h"
#include <cmath>
#include <fstream>


Rectangle::Rectangle() : position(0, 0), width(1), height(1), color(sf::Color::White) {
    updateVertices();
}

Rectangle::Rectangle(const Point2D& position, float width, float height, sf::Color color)
    : position(position), width(width), height(height), color(color) {
    updateVertices();
}

void Rectangle::updateVertices() {
    vertices.clear();
    vertices.push_back(position); // Верхній лівий кут
    vertices.push_back(Point2D(position.getX() + width, position.getY())); // Верхній правий кут
    vertices.push_back(Point2D(position.getX() + width, position.getY() + height)); // Нижній правий кут
    vertices.push_back(Point2D(position.getX(), position.getY() + height)); // Нижній лівий кут
}

void Rectangle::draw(sf::RenderWindow& window, PrimitiveRenderer& renderer) {
    for (size_t i = 0; i < vertices.size(); ++i) {
        Point2D start = vertices[i];
        Point2D end = vertices[(i + 1) % vertices.size()]; // З'єднує останню вершину з першою
        renderer.drawLineIncremental(window, start, end, color);
    }
}

void Rectangle::translate(float dx, float dy) {
    position.setX(position.getX() + dx);
    position.setY(position.getY() + dy);
    updateVertices();
}

void Rectangle::update() {
    // Логіка для автоматичного оновлення (якщо потрібна)
}

void Rectangle::rotate(float angle) {
    float centerX = position.getX() + width / 2;
    float centerY = position.getY() + height / 2;
    float radians = angle * M_PI / 180.0f;

    for (auto& vertex : vertices) {
        float x = vertex.getX() - centerX;
        float y = vertex.getY() - centerY;
        float rotatedX = x * cos(radians) - y * sin(radians);
        float rotatedY = x * sin(radians) + y * cos(radians);
        vertex.setX(rotatedX + centerX);
        vertex.setY(rotatedY + centerY);
    }
}

void Rectangle::scale(float factorX, float factorY) {
    float centerX = position.getX() + width / 2;
    float centerY = position.getY() + height / 2;

    for (auto& vertex : vertices) {
        float scaledX = centerX + (vertex.getX() - centerX) * factorX;
        float scaledY = centerY + (vertex.getY() - centerY) * factorY;
        vertex.setX(scaledX);
        vertex.setY(scaledY);
    }
    width *= factorX;
    height *= factorY;
}

void Rectangle::setPosition(const Point2D& newPosition) {
    position = newPosition;
    updateVertices();
}
