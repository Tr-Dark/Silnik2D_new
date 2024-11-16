#define _USE_MATH_DEFINES 
#include "Rectangle.h"
#include <cmath>
#include <iostream>

/**
 * @brief Konstruktor domyślny klasy Rectangle.
 * Inicjalizuje prostokąt w pozycji (0, 0) o szerokości 1, wysokości 1 i kolorze białym.
 */
Rectangle::Rectangle() : position(0, 0), width(1), height(1), color(sf::Color::White) {
    updateVertices();
    std::cout << "Konstruktor prostokąta\n";
}

/**
 * @brief Konstruktor parametryczny klasy Rectangle.
 * @param position Pozycja lewego górnego rogu prostokąta.
 * @param width Szerokość prostokąta.
 * @param height Wysokość prostokąta.
 * @param color Kolor prostokąta.
 */
Rectangle::Rectangle(const Point2D& position, float width, float height, sf::Color color)
    : position(position), width(width), height(height), color(color) {
    updateVertices();
}

/**
 * @brief Aktualizuje wierzchołki prostokąta na podstawie jego pozycji, szerokości i wysokości.
 * Ta metoda jest wywoływana, gdy zmieniają się pozycja, szerokość lub wysokość prostokąta.
 */
void Rectangle::updateVertices() {
    vertices.clear();
    // Definicja wierzchołków prostokąta
    vertices.push_back(position);
    vertices.push_back(Point2D(position.getX() + width, position.getY()));
    vertices.push_back(Point2D(position.getX() + width, position.getY() + height));
    vertices.push_back(Point2D(position.getX(), position.getY() + height));
}

/**
 * @brief Rysuje prostokąt przy użyciu podanego renderera i okna.
 * @param window Okno renderujące, w którym będzie rysowany prostokąt.
 * @param renderer Renderer, który będzie używany do rysowania linii.
 * @param color Kolor, którym prostokąt zostanie narysowany.
 */
void Rectangle::draw(sf::RenderWindow& window, PrimitiveRenderer& renderer, sf::Color color) {
    for (size_t i = 0; i < vertices.size(); ++i) {
        Point2D start = vertices[i];
        Point2D end = vertices[(i + 1) % vertices.size()];
        renderer.drawLineIncremental(window, start, end, color);
    }
}

/**
 * @brief Przesuwa prostokąt o podaną odległość.
 * @param dx Odległość, o którą prostokąt zostanie przesunięty wzdłuż osi X.
 * @param dy Odległość, o którą prostokąt zostanie przesunięty wzdłuż osi Y.
 */
void Rectangle::translate(float dx, float dy) {
    position.setX(position.getX() + dx);
    position.setY(position.getY() + dy);
    updateVertices();
}

/**
 * @brief Aktualizuje prostokąt. Obecnie niezaimplementowane.
 * Ta funkcja może zostać rozszerzona, aby aktualizować inne właściwości prostokąta w przyszłości.
 */
void Rectangle::update() {
    // Przyszłe aktualizacje mogą być obsługiwane tutaj.
}

/**
 * @brief Rotuje prostokąt wokół jego środka o podany kąt.
 * @param angle Kąt, o który ma zostać obrócony prostokąt, w stopniach.
 */
void Rectangle::rotate(float angle) {
    float centerX = position.getX() + width / 2;
    float centerY = position.getY() + height / 2;
    float radians = angle * M_PI / 180.0f;

    // Obrót każdego wierzchołka wokół środka prostokąta
    for (auto& vertex : vertices) {
        float x = vertex.getX() - centerX;
        float y = vertex.getY() - centerY;
        float rotatedX = x * cos(radians) - y * sin(radians);
        float rotatedY = x * sin(radians) + y * cos(radians);
        vertex.setX(rotatedX + centerX);
        vertex.setY(rotatedY + centerY);
    }
}

/**
 * @brief Skaluje prostokąt o podane czynniki wzdłuż osi X i Y.
 * @param factorX Czynnik skalowania wzdłuż osi X.
 * @param factorY Czynnik skalowania wzdłuż osi Y.
 */
void Rectangle::scale(float factorX, float factorY) {
    float centerX = position.getX() + width / 2.0f;
    float centerY = position.getY() + height / 2.0f;

    // Skalowanie każdego wierzchołka względem środka prostokąta
    for (auto& vertex : vertices) {
        float scaledX = centerX + (vertex.getX() - centerX) * factorX;
        float scaledY = centerY + (vertex.getY() - centerY) * factorY;
        vertex.setX(scaledX);
        vertex.setY(scaledY);
    }

    // Aktualizacja szerokości i wysokości na podstawie czynników skalowania
    width *= factorX;
    height *= factorY;

    // Przemieszczenie prostokąta w celu zachowania jego środka
    position.setX(centerX - width / 2.0f);
    position.setY(centerY - height / 2.0f);
}

/**
 * @brief Ustala nową pozycję prostokąta.
 * @param newPosition Nowa pozycja lewego górnego rogu prostokąta.
 */
void Rectangle::setPosition(const Point2D& newPosition) {
    position = newPosition;
    updateVertices();
}
