#ifndef SPRITEOBJECT_H
#define SPRITEOBJECT_H

#include "BitmapObject.h"
#include <vector>
#include "PrimitiveRenderer.h"

class SpriteObject : public BitmapObject {
protected:
    std::vector<sf::Texture> frames;
    int currentFrame;

public:
    SpriteObject();
    virtual void animate();
    virtual void draw(sf::RenderWindow& window, PrimitiveRenderer& renderer);
};

#endif // SPRITEOBJECT_H
