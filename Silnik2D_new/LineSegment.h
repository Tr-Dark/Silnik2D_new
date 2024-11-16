#ifndef LINESEGMENT_H
#define LINESEGMENT_H

#include "Point2D.h"
#include "ShapeObject.h"
#define M_PI 3.14159265358979323846

/**
 * @class LineSegment
 * @brief Reprezentuje odcinek w przestrzeni 2D.
 *
 * Klasa dziedziczy po ShapeObject i implementuje metody do rysowania,
 * transformacji oraz aktualizacji odcinka. Odcinek jest zdefiniowany przez dwa punkty:
 * pocz¹tkowy i koñcowy.
 */
class LineSegment : public ShapeObject {
private:
    Point2D startPoint; ///< Punkt pocz¹tkowy odcinka.
    Point2D endPoint;   ///< Punkt koñcowy odcinka.

public:
    /**
     * @brief Konstruktor odcinka.
     *
     * Inicjalizuje odcinek na podstawie podanych punktów pocz¹tkowego i koñcowego.
     *
     * @param start Punkt pocz¹tkowy odcinka.
     * @param end Punkt koñcowy odcinka.
     */
    LineSegment(const Point2D& start, const Point2D& end);

    /**
     * @brief Rysuje odcinek.
     *
     * Implementacja metody draw dziedziczonej z ShapeObject. Rysuje odcinek z u¿yciem
     * niestandardowego renderera prymitywów i SFML.
     *
     * @param window Referencja do obiektu sf::RenderWindow do rysowania.
     * @param renderer Referencja do PrimitiveRenderer do renderowania prymitywów.
     * @param color Kolor odcinka (domyœlnie sf::Color::White).
     */
    void draw(sf::RenderWindow& window, PrimitiveRenderer& renderer, sf::Color color = sf::Color::White) override;

    /**
     * @brief Translacja odcinka.
     *
     * Przesuwa odcinek o podane wartoœci w osiach X i Y.
     *
     * @param dx Przesuniêcie w osi X.
     * @param dy Przesuniêcie w osi Y.
     */
    void translate(float dx, float dy) override;

    /**
     * @brief Obrót odcinka.
     *
     * Obraca odcinek wokó³ jego œrodka o podany k¹t w stopniach.
     *
     * @param angle K¹t obrotu w stopniach.
     */
    void rotate(float angle) override;

    /**
     * @brief Skalowanie odcinka.
     *
     * Skalowanie odcinka wzd³u¿ osi X i Y. Skalowanie dotyczy d³ugoœci odcinka.
     *
     * @param factorX Wspó³czynnik skalowania w osi X.
     * @param factorY Wspó³czynnik skalowania w osi Y.
     */
    void scale(float factorX, float factorY) override;

    /**
     * @brief Aktualizacja logiki odcinka.
     *
     * Metoda do implementacji logiki zwi¹zanej z odcinkiem. W tej klasie mo¿e byæ u¿ywana do animacji lub interakcji.
     */
    void update() override;

    /**
     * @brief Pobiera punkt pocz¹tkowy odcinka.
     *
     * @return Punkt pocz¹tkowy odcinka.
     */
    Point2D getStartPoint() const;

    /**
     * @brief Pobiera punkt koñcowy odcinka.
     *
     * @return Punkt koñcowy odcinka.
     */
    Point2D getEndPoint() const;

    /**
     * @brief Ustawia punkt pocz¹tkowy odcinka.
     *
     * @param point Nowy punkt pocz¹tkowy.
     */
    void setStartPoint(const Point2D& point);

    /**
     * @brief Ustawia punkt koñcowy odcinka.
     *
     * @param point Nowy punkt koñcowy.
     */
    void setEndPoint(const Point2D& point);
};

#endif // LINESEGMENT_H
