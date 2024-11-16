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
 * pocz�tkowy i ko�cowy.
 */
class LineSegment : public ShapeObject {
private:
    Point2D startPoint; ///< Punkt pocz�tkowy odcinka.
    Point2D endPoint;   ///< Punkt ko�cowy odcinka.

public:
    /**
     * @brief Konstruktor odcinka.
     *
     * Inicjalizuje odcinek na podstawie podanych punkt�w pocz�tkowego i ko�cowego.
     *
     * @param start Punkt pocz�tkowy odcinka.
     * @param end Punkt ko�cowy odcinka.
     */
    LineSegment(const Point2D& start, const Point2D& end);

    /**
     * @brief Rysuje odcinek.
     *
     * Implementacja metody draw dziedziczonej z ShapeObject. Rysuje odcinek z u�yciem
     * niestandardowego renderera prymityw�w i SFML.
     *
     * @param window Referencja do obiektu sf::RenderWindow do rysowania.
     * @param renderer Referencja do PrimitiveRenderer do renderowania prymityw�w.
     * @param color Kolor odcinka (domy�lnie sf::Color::White).
     */
    void draw(sf::RenderWindow& window, PrimitiveRenderer& renderer, sf::Color color = sf::Color::White) override;

    /**
     * @brief Translacja odcinka.
     *
     * Przesuwa odcinek o podane warto�ci w osiach X i Y.
     *
     * @param dx Przesuni�cie w osi X.
     * @param dy Przesuni�cie w osi Y.
     */
    void translate(float dx, float dy) override;

    /**
     * @brief Obr�t odcinka.
     *
     * Obraca odcinek wok� jego �rodka o podany k�t w stopniach.
     *
     * @param angle K�t obrotu w stopniach.
     */
    void rotate(float angle) override;

    /**
     * @brief Skalowanie odcinka.
     *
     * Skalowanie odcinka wzd�u� osi X i Y. Skalowanie dotyczy d�ugo�ci odcinka.
     *
     * @param factorX Wsp�czynnik skalowania w osi X.
     * @param factorY Wsp�czynnik skalowania w osi Y.
     */
    void scale(float factorX, float factorY) override;

    /**
     * @brief Aktualizacja logiki odcinka.
     *
     * Metoda do implementacji logiki zwi�zanej z odcinkiem. W tej klasie mo�e by� u�ywana do animacji lub interakcji.
     */
    void update() override;

    /**
     * @brief Pobiera punkt pocz�tkowy odcinka.
     *
     * @return Punkt pocz�tkowy odcinka.
     */
    Point2D getStartPoint() const;

    /**
     * @brief Pobiera punkt ko�cowy odcinka.
     *
     * @return Punkt ko�cowy odcinka.
     */
    Point2D getEndPoint() const;

    /**
     * @brief Ustawia punkt pocz�tkowy odcinka.
     *
     * @param point Nowy punkt pocz�tkowy.
     */
    void setStartPoint(const Point2D& point);

    /**
     * @brief Ustawia punkt ko�cowy odcinka.
     *
     * @param point Nowy punkt ko�cowy.
     */
    void setEndPoint(const Point2D& point);
};

#endif // LINESEGMENT_H
