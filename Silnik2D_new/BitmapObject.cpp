#include "BitmapObject.h"
#include <iostream>
BitmapObject::BitmapObject() {
    //std::cout << "BitmapObject constructor\n";
}
void BitmapObject::setTexture(const sf::Texture& texture) {
    sprite.setTexture(texture); // Присвоює текстуру спрайту
}

void BitmapObject::setTextureRect(const sf::IntRect& rect) {
    sprite.setTextureRect(rect); // Встановлює область текстури
}


