#include "SpriteObject.h"
#include <iostream>

/**
 * @brief Konstruktor domyślny klasy SpriteObject.
 * Inicjalizuje obiekt SpriteObject, ustawiając bieżącą klatkę animacji na 0.
 */
SpriteObject::SpriteObject() : currentFrame(0) {
    std::cout << "Konstruktor SpriteObject\n";
}

/**
 * @brief Animuje obiekt SpriteObject.
 * Zmienia aktualną klatkę animacji na następną, a następnie ustawia odpowiednią teksturę.
 * Klatki animacji są cyklicznie przełączane.
 */
void SpriteObject::animate() {
    if (!frames.empty()) {
        // Przechodzi do następnej klatki animacji i resetuje, gdy dojdzie do końca
        currentFrame = (currentFrame + 1) % frames.size();
        setTexture(frames[currentFrame]);
    }
}

/**
 * @brief Rysuje obiekt SpriteObject na zadanym oknie.
 * @param window Okno renderujące, w którym zostanie narysowany obiekt.
 */
void SpriteObject::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
