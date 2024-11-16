#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SFML/Graphics.hpp>
#include "PrimitiveRenderer.h"

/**
 * @class GameObject
 * @brief Abstrakcyjna klasa bazowa dla wszystkich obiektów w grze.
 *
 * Klasa definiuje interfejs dla obiektów gry, wymagaj¹c implementacji
 * metod do aktualizacji stanu oraz rysowania.
 */
class GameObject {
public:
    /**
     * @brief Aktualizuje stan obiektu.
     *
     * Funkcja czysto wirtualna, która musi byæ zaimplementowana w klasach pochodnych.
     * Odpowiada za aktualizacjê logiki zwi¹zanej z danym obiektem.
     */
    virtual void update() = 0;

    /**
     * @brief Rysuje obiekt na ekranie.
     *
     * Funkcja czysto wirtualna, która musi byæ zaimplementowana w klasach pochodnych.
     * Umo¿liwia renderowanie obiektu z u¿yciem SFML i niestandardowego renderera prymitywów.
     *
     * @param window Referencja do obiektu sf::RenderWindow, w którym obiekt zostanie narysowany.
     * @param renderer Referencja do obiektu PrimitiveRenderer u¿ywanego do rysowania prymitywów.
     * @param color Kolor u¿ywany podczas rysowania (domyœlnie sf::Color::White).
     */
    virtual void draw(sf::RenderWindow& window, PrimitiveRenderer& renderer, sf::Color color = sf::Color::White) = 0;

    /**
     * @brief Wirtualny destruktor klasy GameObject.
     *
     * Pozwala na poprawne usuniêcie obiektów dziedzicz¹cych po GameObject.
     */
    virtual ~GameObject() {}
};

#endif // GAME_OBJECT_H
