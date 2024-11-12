#include "SpriteObject.h"

SpriteObject::SpriteObject() : currentFrame(0) {}

void SpriteObject::animate() {
    currentFrame = (currentFrame + 1) % frames.size();
    setTexture(frames[currentFrame]);  // Оновлення текстури для відображення анімації
}

void SpriteObject::draw(sf::RenderWindow& window, PrimitiveRenderer& renderer) {
    window.draw(sprite);  // Відображення поточного кадру спрайта
}
