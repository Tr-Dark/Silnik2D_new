#ifndef TRANSFORMABLE_OBJECT_H
#define TRANSFORMABLE_OBJECT_H

#include "GameObject.h"

/**
 * @class TransformableObject
 * @brief Klasa bazowa dla obiektów, które mog¹ byæ transformowane.
 *
 * Klasa ta rozszerza klasê `GameObject` i definiuje interfejs dla obiektów, które wspieraj¹ operacje transformacji,
 * takie jak translacja, rotacja i skalowanie. Klasa jest abstrakcyjna, co oznacza, ¿e musi byæ dziedziczona przez
 * inne klasy, które implementuj¹ te operacje.
 */
class TransformableObject : public virtual GameObject {
public:
    /**
     * @brief Przemieszcza obiekt o okreœlon¹ wartoœæ w osi X i Y.
     *
     * Metoda ta wykonuje translacjê obiektu, przesuwaj¹c go o zadane wartoœci w obu osiach.
     *
     * @param dx Przemieszczenie obiektu w osi X.
     * @param dy Przemieszczenie obiektu w osi Y.
     */
    virtual void translate(float dx, float dy) = 0;

    /**
     * @brief Obraca obiekt o okreœlony k¹t.
     *
     * Metoda ta wykonuje rotacjê obiektu o zadany k¹t w stopniach.
     *
     * @param angle K¹t rotacji w stopniach.
     */
    virtual void rotate(float angle) = 0;

    /**
     * @brief Skaluje obiekt o okreœlone wspó³czynniki w obu osiach.
     *
     * Metoda ta zmienia rozmiar obiektu, skaluj¹c go w kierunkach X i Y.
     *
     * @param factorX Wspó³czynnik skali w osi X.
     * @param factorY Wspó³czynnik skali w osi Y.
     */
    virtual void scale(float factorX, float factorY) = 0;

    /**
     * @brief Wirtualny destruktor.
     *
     * Destruktor tej klasy jest wirtualny, co pozwala na prawid³owe zwalnianie zasobów przez klasy pochodne.
     */
    virtual ~TransformableObject() {}
};

#endif // TRANSFORMABLE_OBJECT_H
