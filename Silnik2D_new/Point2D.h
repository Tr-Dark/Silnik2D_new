#ifndef POINT2D_H
#define POINT2D_H

#include <SFML/Graphics.hpp>
#include "TransformableObject.h"
#include "PrimitiveRenderer.h"
#define M_PI 3.14159265358979323846

/**
 * @class Point2D
 * @brief Reprezentuje punkt w przestrzeni 2D z możliwością transformacji.
 *
 * Klasa implementuje podstawowe operacje na punktach, takie jak translacja,
 * rotacja, skalowanie oraz rysowanie.
 */
class Point2D : public TransformableObject {
private:
    float x; ///< Współrzędna X punktu.
    float y; ///< Współrzędna Y punktu.

public:
    /**
     * @brief Konstruktor klasy Point2D.
     *
     * Inicjalizuje punkt na podstawie współrzędnych. Domyślnie punkt ma współrzędne (0, 0).
     *
     * @param x Współrzędna X (domyślnie 0).
     * @param y Współrzędna Y (domyślnie 0).
     */
    Point2D(float x = 0, float y = 0);

    /**
     * @brief Pobiera współrzędną X punktu.
     *
     * @return Wartość współrzędnej X.
     */
    float getX() const;

    /**
     * @brief Pobiera współrzędną Y punktu.
     *
     * @return Wartość współrzędnej Y.
     */
    float getY() const;

    /**
     * @brief Ustawia współrzędną X punktu.
     *
     * @param x Nowa wartość współrzędnej X.
     */
    void setX(float x);

    /**
     * @brief Ustawia współrzędną Y punktu.
     *
     * @param y Nowa wartość współrzędnej Y.
     */
    void setY(float y);

    /**
     * @brief Translacja punktu.
     *
     * Przesuwa punkt o podane wartości w osiach X i Y.
     *
     * @param dx Przesunięcie w osi X.
     * @param dy Przesunięcie w osi Y.
     */
    void translate(float dx, float dy) override;

    /**
     * @brief Obrót punktu.
     *
     * Obraca punkt wokół środka układu współrzędnych o podany kąt w stopniach.
     *
     * @param angle Kąt obrotu w stopniach.
     */
    void rotate(float angle) override;

    /**
     * @brief Skalowanie punktu.
     *
     * Skaluje współrzędne punktu względem osi X i Y.
     *
     * @param factorX Współczynnik skalowania w osi X.
     * @param factorY Współczynnik skalowania w osi Y.
     */
    void scale(float factorX, float factorY) override;

    /**
     * @brief Aktualizuje stan punktu.
     *
     * Metoda używana do logiki związanej z punktem. W tej implementacji pusta.
     */
    void update();

    /**
     * @brief Rysuje punkt na ekranie.
     *
     * Używa niestandardowego renderera prymitywów do rysowania punktu na ekranie.
     *
     * @param window Referencja do okna SFML do rysowania.
     * @param renderer Referencja do obiektu PrimitiveRenderer.
     * @param color Kolor punktu (domyślnie sf::Color::White).
     */
    void draw(sf::RenderWindow& window, PrimitiveRenderer& renderer, sf::Color color = sf::Color::White);

    /**
     * @brief Sprawdza, czy punkt znajduje się w granicach okna.
     *
     * @param dx Przesunięcie w osi X.
     * @param dy Przesunięcie w osi Y.
     * @param windowWidth Szerokość okna.
     * @param windowHeight Wysokość okna.
     * @return true, jeśli punkt znajduje się w granicach okna; false w przeciwnym razie.
     */
    bool isWithinBounds(float dx, float dy, float windowWidth, float windowHeight) const;
};

#endif // POINT2D_H
