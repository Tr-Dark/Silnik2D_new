#ifndef BITMAPOBJECT_H
#define BITMAPOBJECT_H

#include <SFML/Graphics.hpp>
#include "DrawableObject.h"
#include "TransformableObject.h"

/**
 * @class BitmapObject
 * @brief Klasa bazowa reprezentująca obiekt graficzny z teksturą.
 *
 * Klasa dziedziczy po TransformableObject i DrawableObject, zapewniając
 * obsługę transformacji oraz możliwość rysowania obiektów z użyciem SFML.
 */

class BitmapObject : public TransformableObject, public DrawableObject {
protected:

    /**
     * @brief Obiekt sf::Sprite przechowujący dane o wyglądzie bitmapy.
     *
     * Obiekt sprite używany jest do renderowania bitmapy z nałożoną teksturą.
     */

    sf::Sprite sprite;

public:

    /**
     * @brief Konstruktor klasy BitmapObject.
     *
     * Inicjalizuje obiekt klasy BitmapObject bez przypisanej tekstury.
     */

    BitmapObject();

    /**
     * @brief Ustawia teksturę dla sprite'a.
     *
     * Metoda przypisuje podaną teksturę do obiektu sf::Sprite.
     *
     * @param texture Stała referencja do obiektu sf::Texture.
     */

    virtual void setTexture(const sf::Texture& texture); 

    /**
     * @brief Ustawia wycinek tekstury, który ma być używany przez sprite.
     *
     * Metoda pozwala określić prostokątny obszar tekstury, który będzie
     * wyświetlany przez sprite'a.
     *
     * @param rect Prostokątny obszar tekstury (sf::IntRect).
     */

    virtual void setTextureRect(const sf::IntRect& rect);

    /**
     * @brief Przesuwa obiekt o określone wektory w osi X i Y.
     *
     * Funkcja czysto wirtualna, która musi zostać zaimplementowana
     * w klasach pochodnych. Odpowiada za przesunięcie obiektu w przestrzeni.
     *
     * @param dx Przesunięcie w osi X.
     * @param dy Przesunięcie w osi Y.
     */

    virtual void translate(float dx, float dy) = 0;

    /**
     * @brief Obraca obiekt o zadany kąt.
     *
     * Funkcja czysto wirtualna, która musi zostać zaimplementowana
     * w klasach pochodnych. Odpowiada za obrót obiektu.
     *
     * @param angle Kąt obrotu w stopniach.
     */

    virtual void rotate(float angle) = 0;

    /**
     * @brief Skaluje obiekt według zadanych współczynników.
     *
     * Funkcja czysto wirtualna, która musi zostać zaimplementowana
     * w klasach pochodnych. Odpowiada za zmianę rozmiaru obiektu.
     *
     * @param factorX Współczynnik skali w osi X.
     * @param factorY Współczynnik skali w osi Y.
     */

    virtual void scale(float factorX, float factorY) = 0;
};

#endif // BITMAPOBJECT_H
