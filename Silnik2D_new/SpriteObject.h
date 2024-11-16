#ifndef SPRITEOBJECT_H
#define SPRITEOBJECT_H

#include "BitmapObject.h"
#include <vector>
#include "PrimitiveRenderer.h"
#include "AnimatedObject.h"

class SpriteObject : public BitmapObject, public AnimatedObject {
protected:
    std::vector<sf::Texture> frames;
    int currentFrame;

public:
    SpriteObject();
    virtual void animate();

    virtual void draw(sf::RenderWindow& window);
};

#endif // SPRITEOBJECT_H
