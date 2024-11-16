#include "BitmapObject.h"
#include <iostream>

BitmapObject::BitmapObject() {
   
}

/**
 * @brief Ustawia teksturę dla obiektu typu BitmapObject.
 *
 * Ta metoda przypisuje teksturę do obiektu `sprite`, który jest częścią klasy `BitmapObject`.
 * Tekstura jest używana do renderowania obrazu na ekranie.
 *
 * @param texture Tekstura, która ma zostać przypisana do obiektu `sprite`.
 */
void BitmapObject::setTexture(const sf::Texture& texture) {
    sprite.setTexture(texture); // Przypisuje teksturę do sprite'a
}

/**
 * @brief Ustawia obszar tekstury dla obiektu typu BitmapObject.
 *
 * Ta metoda ustawia prostokątny obszar tekstury, który ma zostać użyty do renderowania na ekranie.
 * Pozwala to na wyświetlenie tylko części tekstury, a nie całego obrazu.
 *
 * @param rect Prostokątny obszar tekstury, który ma zostać użyty do renderowania.
 */
void BitmapObject::setTextureRect(const sf::IntRect& rect) {
    sprite.setTextureRect(rect); // Ustala obszar tekstury
}
