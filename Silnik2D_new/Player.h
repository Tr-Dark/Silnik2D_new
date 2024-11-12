#ifndef PLAYER_H
#define PLAYER_H

#include "SpriteObject.h"
#include "ShapeObject.h"
#include "BitmapHandler.h"
#include <SFML/Graphics.hpp>

class Player : public SpriteObject, public ShapeObject {
public:
    Player();
    void handleInput(const sf::Event& event, BitmapHandler& bmp);
    void update() override;
    void translate(float dx, float dy) override;
    void rotate(float angle) override;
    void scale(float factorX, float factorY) override;
    void draw(sf::RenderWindow& window, PrimitiveRenderer& renderer) override;

private:
    bool isMoving;
    int currentBitmapIndex;
};

#endif // PLAYER_H
