#ifndef TRANSFORMABLE_OBJECT_H
#define TRANSFORMABLE_OBJECT_H

#include "GameObject.h"

/**
 * @class TransformableObject
 * @brief Klasa bazowa dla obiekt�w, kt�re mog� by� transformowane.
 *
 * Klasa ta rozszerza klas� `GameObject` i definiuje interfejs dla obiekt�w, kt�re wspieraj� operacje transformacji,
 * takie jak translacja, rotacja i skalowanie. Klasa jest abstrakcyjna, co oznacza, �e musi by� dziedziczona przez
 * inne klasy, kt�re implementuj� te operacje.
 */
class TransformableObject : public virtual GameObject {
public:
    /**
     * @brief Przemieszcza obiekt o okre�lon� warto�� w osi X i Y.
     *
     * Metoda ta wykonuje translacj� obiektu, przesuwaj�c go o zadane warto�ci w obu osiach.
     *
     * @param dx Przemieszczenie obiektu w osi X.
     * @param dy Przemieszczenie obiektu w osi Y.
     */
    virtual void translate(float dx, float dy) = 0;

    /**
     * @brief Obraca obiekt o okre�lony k�t.
     *
     * Metoda ta wykonuje rotacj� obiektu o zadany k�t w stopniach.
     *
     * @param angle K�t rotacji w stopniach.
     */
    virtual void rotate(float angle) = 0;

    /**
     * @brief Skaluje obiekt o okre�lone wsp�czynniki w obu osiach.
     *
     * Metoda ta zmienia rozmiar obiektu, skaluj�c go w kierunkach X i Y.
     *
     * @param factorX Wsp�czynnik skali w osi X.
     * @param factorY Wsp�czynnik skali w osi Y.
     */
    virtual void scale(float factorX, float factorY) = 0;

    /**
     * @brief Wirtualny destruktor.
     *
     * Destruktor tej klasy jest wirtualny, co pozwala na prawid�owe zwalnianie zasob�w przez klasy pochodne.
     */
    virtual ~TransformableObject() {}
};

#endif // TRANSFORMABLE_OBJECT_H
