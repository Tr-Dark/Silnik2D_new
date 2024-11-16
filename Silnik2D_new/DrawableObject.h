#ifndef DRAWABLE_OBJECT_H
#define DRAWABLE_OBJECT_H

#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include "PrimitiveRenderer.h"

/**
 * @class DrawableObject
 * @brief Abstrakcyjna klasa bazowa dla obiekt�w, kt�re mo�na rysowa�.
 *
 * Klasa dziedziczy wirtualnie po GameObject i definiuje interfejs do rysowania obiekt�w
 * na ekranie z wykorzystaniem SFML. Obejmuje mo�liwo�� rysowania zar�wno z u�yciem
 * sf::RenderWindow, jak i niestandardowego renderera prymityw�w.
 */

class DrawableObject : public virtual GameObject {
public:

    /**
     * @brief Rysuje obiekt na oknie renderowania.
     *
     * Funkcja czysto wirtualna, kt�ra musi by� zaimplementowana w klasach pochodnych.
     * Pozwala na renderowanie obiektu z u�yciem podanego okna SFML oraz niestandardowego
     * renderera prymityw�w.
     *
     * @param window Referencja do obiektu sf::RenderWindow, w kt�rym obiekt zostanie narysowany.
     * @param renderer Referencja do obiektu PrimitiveRenderer, umo�liwiaj�cego renderowanie prymityw�w.
     * @param color Opcjonalny kolor rysowania. Domy�lnie bia�y (sf::Color::White).
     */

    virtual void draw(sf::RenderWindow& window, PrimitiveRenderer& renderer, sf::Color color = sf::Color::White) override = 0;
};

#endif // DRAWABLE_OBJECT_H
