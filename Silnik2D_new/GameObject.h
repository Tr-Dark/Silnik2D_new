#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SFML/Graphics.hpp>
#include "PrimitiveRenderer.h"

/**
 * @class GameObject
 * @brief Abstrakcyjna klasa bazowa dla wszystkich obiekt�w w grze.
 *
 * Klasa definiuje interfejs dla obiekt�w gry, wymagaj�c implementacji
 * metod do aktualizacji stanu oraz rysowania.
 */
class GameObject {
public:
    /**
     * @brief Aktualizuje stan obiektu.
     *
     * Funkcja czysto wirtualna, kt�ra musi by� zaimplementowana w klasach pochodnych.
     * Odpowiada za aktualizacj� logiki zwi�zanej z danym obiektem.
     */
    virtual void update() = 0;

    /**
     * @brief Rysuje obiekt na ekranie.
     *
     * Funkcja czysto wirtualna, kt�ra musi by� zaimplementowana w klasach pochodnych.
     * Umo�liwia renderowanie obiektu z u�yciem SFML i niestandardowego renderera prymityw�w.
     *
     * @param window Referencja do obiektu sf::RenderWindow, w kt�rym obiekt zostanie narysowany.
     * @param renderer Referencja do obiektu PrimitiveRenderer u�ywanego do rysowania prymityw�w.
     * @param color Kolor u�ywany podczas rysowania (domy�lnie sf::Color::White).
     */
    virtual void draw(sf::RenderWindow& window, PrimitiveRenderer& renderer, sf::Color color = sf::Color::White) = 0;

    /**
     * @brief Wirtualny destruktor klasy GameObject.
     *
     * Pozwala na poprawne usuni�cie obiekt�w dziedzicz�cych po GameObject.
     */
    virtual ~GameObject() {}
};

#endif // GAME_OBJECT_H
