#ifndef UPDATABLE_OBJECT_H
#define UPDATABLE_OBJECT_H

#include "GameObject.h"

/**
 * @class UpdatableObject
 * @brief Klasa bazowa dla obiektów, które mog¹ byæ aktualizowane.
 *
 * Klasa ta rozszerza klasê `GameObject` i definiuje interfejs dla obiektów, które mog¹ byæ aktualizowane w ka¿dej
 * klatce gry lub w cyklu aktualizacji. Klasa ta jest abstrakcyjna i musi byæ dziedziczona przez inne klasy,
 * które implementuj¹ metodê `update()`.
 */
class UpdatableObject : public virtual GameObject {
public:
    /**
     * @brief Aktualizuje stan obiektu.
     *
     * Metoda ta jest u¿ywana do aktualizacji stanu obiektu w ka¿dej klatce gry. Mo¿e obejmowaæ zmiany pozycji,
     * stanu, animacji, itp. Konkretna implementacja zale¿y od klasy pochodnej.
     */
    virtual void update() = 0;
};

#endif // UPDATABLE_OBJECT_H
