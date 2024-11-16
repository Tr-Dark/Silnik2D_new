#ifndef SHAPE_OBJECT_H
#define SHAPE_OBJECT_H

#include "DrawableObject.h"
#include "TransformableObject.h"
#include "PrimitiveRenderer.h"

/**
 * @class ShapeObject
 * @brief Abstrakcyjna klasa bazowa dla obiekt�w graficznych, kt�re mog� by� rysowane i transformowane.
 *
 * Klasa ta ��czy interfejsy `DrawableObject` i `TransformableObject`, zapewniaj�c metody do rysowania
 * obiekt�w na ekranie oraz stosowania transformacji takich jak przesuni�cie, obr�t i skalowanie.
 */
class ShapeObject : public DrawableObject, public TransformableObject {
public:
    /**
     * @brief Wirtualna metoda rysowania obiektu.
     *
     * Klasa pochodna powinna implementowa� t� metod� w celu rysowania obiektu na ekranie.
     *
     * @param window Okno, w kt�rym obiekt ma by� narysowany.
     * @param renderer Renderer do rysowania prymityw�w.
     * @param color Kolor obiektu (domy�lnie bia�y).
     */
    virtual void draw(sf::RenderWindow& window, PrimitiveRenderer& renderer, sf::Color color = sf::Color::White) override = 0;

    /**
     * @brief Wirtualna metoda do przesuni�cia obiektu.
     *
     * Klasa pochodna powinna zaimplementowa� t� metod� w celu przesuni�cia obiektu o zadane warto�ci.
     *
     * @param dx Przemieszczenie w osi X.
     * @param dy Przemieszczenie w osi Y.
     */
    virtual void translate(float dx, float dy) override = 0;

    /**
     * @brief Wirtualna metoda do obr�cenia obiektu.
     *
     * Klasa pochodna powinna zaimplementowa� t� metod� w celu obr�cenia obiektu o zadany k�t.
     *
     * @param angle K�t obrotu w stopniach.
     */
    virtual void rotate(float angle) override = 0;

    /**
     * @brief Wirtualna metoda do skalowania obiektu.
     *
     * Klasa pochodna powinna zaimplementowa� t� metod� w celu skalowania obiektu o zadane wsp�czynniki.
     *
     * @param factorX Wsp�czynnik skalowania w osi X.
     * @param factorY Wsp�czynnik skalowania w osi Y.
     */
    virtual void scale(float factorX, float factorY) override = 0;
};

#endif // SHAPE_OBJECT_H
