#ifndef DRAWABLE_OBJECT_H
#define DRAWABLE_OBJECT_H

#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include "PrimitiveRenderer.h"

/**
 * @class DrawableObject
 * @brief Abstrakcyjna klasa bazowa dla obiektów, które mo¿na rysowaæ.
 *
 * Klasa dziedziczy wirtualnie po GameObject i definiuje interfejs do rysowania obiektów
 * na ekranie z wykorzystaniem SFML. Obejmuje mo¿liwoœæ rysowania zarówno z u¿yciem
 * sf::RenderWindow, jak i niestandardowego renderera prymitywów.
 */

class DrawableObject : public virtual GameObject {
public:

    /**
     * @brief Rysuje obiekt na oknie renderowania.
     *
     * Funkcja czysto wirtualna, która musi byæ zaimplementowana w klasach pochodnych.
     * Pozwala na renderowanie obiektu z u¿yciem podanego okna SFML oraz niestandardowego
     * renderera prymitywów.
     *
     * @param window Referencja do obiektu sf::RenderWindow, w którym obiekt zostanie narysowany.
     * @param renderer Referencja do obiektu PrimitiveRenderer, umo¿liwiaj¹cego renderowanie prymitywów.
     * @param color Opcjonalny kolor rysowania. Domyœlnie bia³y (sf::Color::White).
     */

    virtual void draw(sf::RenderWindow& window, PrimitiveRenderer& renderer, sf::Color color = sf::Color::White) override = 0;
};

#endif // DRAWABLE_OBJECT_H
