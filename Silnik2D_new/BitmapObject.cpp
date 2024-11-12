#include "BitmapObject.h"

BitmapObject::BitmapObject() : currentTextureIndex(0) {}

bool BitmapObject::addTexture(const sf::Texture& texture) {
    textures.push_back(texture);
    if (textures.size() == 1) {
        sprite.setTexture(textures[0]);
    }
    return true;
}

void BitmapObject::setTexture(int index) {
    if (index >= 0 && index < textures.size()) {
        currentTextureIndex = index;
        sprite.setTexture(textures[currentTextureIndex]);
    }
}

void BitmapObject::draw(sf::RenderWindow& window, PrimitiveRenderer& renderer) {
    window.draw(sprite);
}
