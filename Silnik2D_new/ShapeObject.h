#ifndef SHAPE_OBJECT_H
#define SHAPE_OBJECT_H

#include "DrawableObject.h"
#include "TransformableObject.h"
#include "PrimitiveRenderer.h"

/**
 * @class ShapeObject
 * @brief Abstrakcyjna klasa bazowa dla obiektów graficznych, które mog¹ byæ rysowane i transformowane.
 *
 * Klasa ta ³¹czy interfejsy `DrawableObject` i `TransformableObject`, zapewniaj¹c metody do rysowania
 * obiektów na ekranie oraz stosowania transformacji takich jak przesuniêcie, obrót i skalowanie.
 */
class ShapeObject : public DrawableObject, public TransformableObject {
public:
    /**
     * @brief Wirtualna metoda rysowania obiektu.
     *
     * Klasa pochodna powinna implementowaæ tê metodê w celu rysowania obiektu na ekranie.
     *
     * @param window Okno, w którym obiekt ma byæ narysowany.
     * @param renderer Renderer do rysowania prymitywów.
     * @param color Kolor obiektu (domyœlnie bia³y).
     */
    virtual void draw(sf::RenderWindow& window, PrimitiveRenderer& renderer, sf::Color color = sf::Color::White) override = 0;

    /**
     * @brief Wirtualna metoda do przesuniêcia obiektu.
     *
     * Klasa pochodna powinna zaimplementowaæ tê metodê w celu przesuniêcia obiektu o zadane wartoœci.
     *
     * @param dx Przemieszczenie w osi X.
     * @param dy Przemieszczenie w osi Y.
     */
    virtual void translate(float dx, float dy) override = 0;

    /**
     * @brief Wirtualna metoda do obrócenia obiektu.
     *
     * Klasa pochodna powinna zaimplementowaæ tê metodê w celu obrócenia obiektu o zadany k¹t.
     *
     * @param angle K¹t obrotu w stopniach.
     */
    virtual void rotate(float angle) override = 0;

    /**
     * @brief Wirtualna metoda do skalowania obiektu.
     *
     * Klasa pochodna powinna zaimplementowaæ tê metodê w celu skalowania obiektu o zadane wspó³czynniki.
     *
     * @param factorX Wspó³czynnik skalowania w osi X.
     * @param factorY Wspó³czynnik skalowania w osi Y.
     */
    virtual void scale(float factorX, float factorY) override = 0;
};

#endif // SHAPE_OBJECT_H
