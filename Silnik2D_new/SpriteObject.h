#ifndef SPRITEOBJECT_H
#define SPRITEOBJECT_H

#include "BitmapObject.h"
#include <vector>
#include "PrimitiveRenderer.h"
#include "AnimatedObject.h"

/**
 * @class SpriteObject
 * @brief Klasa reprezentująca obiekt typu sprite, który może mieć animowane klatki.
 *
 * Klasa ta dziedziczy po `BitmapObject` i `AnimatedObject`, umożliwiając wyświetlanie animowanych obrazków (sprite'ów)
 * oraz zarządzanie ich klatkami.
 */
class SpriteObject : public BitmapObject, public AnimatedObject {
protected:
    /**
     * @brief Wektor tekstur (klatek) animacji.
     *
     * Przechowuje tekstury, które tworzą animację obiektu.
     */
    std::vector<sf::Texture> frames;

    /**
     * @brief Indeks bieżącej klatki animacji.
     *
     * Określa, która klatka z wektora `frames` jest aktualnie wyświetlana.
     */
    int currentFrame;

public:
    /**
     * @brief Konstruktor klasy `SpriteObject`.
     *
     * Inicjalizuje obiekt typu sprite z pustą listą klatek i ustawia bieżącą klatkę na 0.
     */
    SpriteObject();

    /**
     * @brief Metoda do animowania sprite'a.
     *
     * Przełącza klatki animacji, umożliwiając płynne odtwarzanie animacji.
     */
    virtual void animate();

    /**
     * @brief Metoda rysująca obiekt typu sprite na oknie.
     *
     * Rysuje bieżącą klatkę animacji w danym oknie. Klasy pochodne mogą zaimplementować
     * tę metodę w celu dostosowania renderowania.
     *
     * @param window Okno, w którym obiekt ma być narysowany.
     */
    virtual void draw(sf::RenderWindow& window);
};

#endif // SPRITEOBJECT_H
