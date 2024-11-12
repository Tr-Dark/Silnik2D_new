#ifndef SPRITE_OBJECT_H
#define SPRITE_OBJECT_H

#include <SFML/Graphics.hpp>
#include "BitmapObject.h"
#include "AnimatedObject.h"

class SpriteObject : public BitmapObject, public AnimatedObject {
public:
    SpriteObject();
    void animate() override;
    void draw(sf::RenderWindow& window, PrimitiveRenderer& renderer) override;

protected:
    int currentFrame;
    std::vector<sf::Texture> frames;
};

#endif // SPRITE_OBJECT_H
