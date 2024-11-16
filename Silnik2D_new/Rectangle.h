#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "ShapeObject.h"
#include "Point2D.h"
#include "PrimitiveRenderer.h"
#include <vector>
#include <SFML/Graphics.hpp>

/**
 * @class Rectangle
 * @brief Klasa reprezentująca prostokąt.
 *
 * Klasa pozwala na tworzenie prostokątów, ich rysowanie, transformacje (przesunięcie, obrót, skalowanie),
 * oraz zarządzanie pozycją i wymiarami prostokąta.
 */
class Rectangle : public ShapeObject {
public:
    /**
     * @brief Konstruktor domyślny prostokąta.
     */
    Rectangle();

    /**
     * @brief Konstruktor prostokąta o określonej pozycji, szerokości, wysokości i kolorze.
     *
     * @param position Pozycja początkowa prostokąta (lewy górny róg).
     * @param width Szerokość prostokąta.
     * @param height Wysokość prostokąta.
     * @param color Kolor prostokąta (domyślnie biały).
     */
    Rectangle(const Point2D& position, float width, float height, sf::Color color = sf::Color::White);

    /**
     * @brief Rysuje prostokąt na ekranie.
     *
     * @param window Okno, na którym rysowany jest prostokąt.
     * @param renderer Renderer do rysowania prymitywów.
     * @param color Kolor prostokąta (domyślnie biały).
     */
    void draw(sf::RenderWindow& window, PrimitiveRenderer& renderer, sf::Color color = sf::Color::White) override;

    /**
     * @brief Przesuwa prostokąt o zadane wartości w osiach X i Y.
     *
     * @param dx Przemieszczenie w osi X.
     * @param dy Przemieszczenie w osi Y.
     */
    void translate(float dx, float dy) override;

    /**
     * @brief Obraca prostokąt o zadany kąt.
     *
     * @param angle Kąt obrotu w stopniach.
     */
    void rotate(float angle) override;

    /**
     * @brief Skaluje prostokąt o zadane współczynniki w osiach X i Y.
     *
     * @param factorX Współczynnik skalowania w osi X.
     * @param factorY Współczynnik skalowania w osi Y.
     */
    void scale(float factorX, float factorY) override;

    /**
     * @brief Aktualizuje stan prostokąta (np. jego pozycję po transformacjach).
     */
    void update() override;

    /**
     * @brief Zwraca szerokość prostokąta.
     *
     * @return Szerokość prostokąta.
     */
    float getWidth() const { return width; }

    /**
     * @brief Zwraca wysokość prostokąta.
     *
     * @return Wysokość prostokąta.
     */
    float getHeight() const { return height; }

    /**
     * @brief Zwraca pozycję prostokąta (lewy górny róg).
     *
     * @return Pozycja prostokąta.
     */
    Point2D getPosition() const { return position; }

    /**
     * @brief Ustawia nową pozycję prostokąta.
     *
     * @param newPosition Nowa pozycja prostokąta.
     */
    void setPosition(const Point2D& newPosition);

private:
    Point2D position; ///< Pozycja prostokąta (lewy górny róg).
    float width;      ///< Szerokość prostokąta.
    float height;     ///< Wysokość prostokąta.
    sf::Color color;  ///< Kolor prostokąta.

    std::vector<Point2D> vertices; ///< Wektory punktów definiujących wierzchołki prostokąta.

    /**
     * @brief Aktualizuje wierzchołki prostokąta po zastosowanych transformacjach.
     */
    void updateVertices();
};

#endif // RECTANGLE_H
