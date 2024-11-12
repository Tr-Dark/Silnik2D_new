#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "ShapeObject.h"
#include "Point2D.h"
#include "PrimitiveRenderer.h"
#include <vector>
#include <SFML/Graphics.hpp>

class Rectangle : public ShapeObject {
public:
    // Додаємо конструктор за замовчуванням
    Rectangle();
    Rectangle(const Point2D& position, float width, float height, sf::Color color = sf::Color::White);

    // Перевизначення методів
    void draw(sf::RenderWindow& window, PrimitiveRenderer& renderer) override;
    void translate(float dx, float dy) override;
    void rotate(float angle) override;
    void scale(float factorX, float factorY) override;
    void update() override;

    // Геттери та сеттери
    float getWidth() const { return width; }
    float getHeight() const { return height; }
    Point2D getPosition() const { return position; }
    void setPosition(const Point2D& newPosition);

private:
    Point2D position;
    float width;
    float height;
    sf::Color color;

    std::vector<Point2D> vertices; // Вершини прямокутника для малювання
    void updateVertices(); // Метод для оновлення координат вершин після трансформацій
};

#endif // RECTANGLE_H
