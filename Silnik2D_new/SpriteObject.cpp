#include "SpriteObject.h"
#include <iostream>
SpriteObject::SpriteObject() : currentFrame(0) {
    std::cout << "SpriteObject constructor\n";
}

void SpriteObject::animate() {
    if (!frames.empty()) {
        currentFrame = (currentFrame + 1) % frames.size();
        setTexture(frames[currentFrame]); // Оновлюємо текстуру для відображення анімації
    }
}

void SpriteObject::draw(sf::RenderWindow& window, PrimitiveRenderer& renderer) {
    window.draw(sprite); // Відображення поточного кадру
}
