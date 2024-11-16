#ifndef UPDATABLE_OBJECT_H
#define UPDATABLE_OBJECT_H

#include "GameObject.h"

/**
 * @class UpdatableObject
 * @brief Klasa bazowa dla obiekt�w, kt�re mog� by� aktualizowane.
 *
 * Klasa ta rozszerza klas� `GameObject` i definiuje interfejs dla obiekt�w, kt�re mog� by� aktualizowane w ka�dej
 * klatce gry lub w cyklu aktualizacji. Klasa ta jest abstrakcyjna i musi by� dziedziczona przez inne klasy,
 * kt�re implementuj� metod� `update()`.
 */
class UpdatableObject : public virtual GameObject {
public:
    /**
     * @brief Aktualizuje stan obiektu.
     *
     * Metoda ta jest u�ywana do aktualizacji stanu obiektu w ka�dej klatce gry. Mo�e obejmowa� zmiany pozycji,
     * stanu, animacji, itp. Konkretna implementacja zale�y od klasy pochodnej.
     */
    virtual void update() = 0;
};

#endif // UPDATABLE_OBJECT_H
