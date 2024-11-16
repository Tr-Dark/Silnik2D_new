#include "Point2D.h"
#include <cmath>
#include <iostream>

/**
 * @brief Konstruktor klasy Point2D.
 *
 * Inicjalizuje punkt 2D z określonymi współrzędnymi x i y.
 *
 * @param x Współrzędna x punktu.
 * @param y Współrzędna y punktu.
 */
Point2D::Point2D(float x, float y) : x(x), y(y) {
}

/**
 * @brief Zwraca współrzędną x punktu.
 *
 * @return Współrzędna x punktu.
 */
float Point2D::getX() const {
    return x;
}

/**
 * @brief Zwraca współrzędną y punktu.
 *
 * @return Współrzędna y punktu.
 */
float Point2D::getY() const {
    return y;
}

/**
 * @brief Ustawia współrzędną x punktu.
 *
 * @param x Nowa wartość współrzędnej x.
 */
void Point2D::setX(float x) {
    this->x = x;
}

/**
 * @brief Ustawia współrzędną y punktu.
 *
 * @param y Nowa wartość współrzędnej y.
 */
void Point2D::setY(float y) {
    this->y = y;
}

/**
 * @brief Przesuwa punkt o określoną wartość w poziomie i pionie.
 *
 * @param dx Przemieszczenie w osi X.
 * @param dy Przemieszczenie w osi Y.
 */
void Point2D::translate(float dx, float dy) {
    x += dx;
    y += dy;
}

/**
 * @brief Obraca punkt o określony kąt (niezrealizowane).
 *
 * Funkcja nie jest zaimplementowana w tej wersji.
 *
 * @param angle Kąt rotacji w stopniach.
 */
void Point2D::rotate(float angle) {
    // Funkcja nie została zaimplementowana
}

/**
 * @brief Skaluje punkt względem początku układu współrzędnych.
 *
 * @param factorX Skala w osi X.
 * @param factorY Skala w osi Y.
 */
void Point2D::scale(float factorX, float factorY) {
    x *= factorX;
    y *= factorY;
}

/**
 * @brief Aktualizuje stan punktu.
 *
 * Funkcja jest pusta, ale może być rozszerzona w przyszłości.
 */
void Point2D::update() {
    // Funkcja nie została zaimplementowana
}

/**
 * @brief Rysuje punkt na oknie renderowania.
 *
 * @param window Okno renderowania, w którym punkt będzie narysowany.
 * @param renderer Renderer prymitywów (nieużywany w tej funkcji).
 * @param color Kolor punktu.
 */
void Point2D::draw(sf::RenderWindow& window, PrimitiveRenderer& renderer, sf::Color color) {
    sf::Vertex point(sf::Vector2f(x, y), color);
    window.draw(&point, 1, sf::Points);  // Rysowanie punktu na ekranie
}

/**
 * @brief Sprawdza, czy punkt z przesunięciem mieści się w granicach okna.
 *
 * @param dx Przemieszczenie w osi X.
 * @param dy Przemieszczenie w osi Y.
 * @param windowWidth Szerokość okna.
 * @param windowHeight Wysokość okna.
 *
 * @return True, jeśli punkt mieści się w granicach, false w przeciwnym razie.
 */
bool Point2D::isWithinBounds(float dx, float dy, float windowWidth, float windowHeight) const {
    // Obliczamy nowe współrzędne punktu
    float newX = x + dx;
    float newY = y + dy;

    // Sprawdzamy, czy nowe współrzędne są w granicach okna
    return (newX >= 0 && newX <= windowWidth && newY >= 0 && newY <= windowHeight);
}
