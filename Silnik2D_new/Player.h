#ifndef PLAYER_H
#define PLAYER_H

#include "SpriteObject.h"
#include "ShapeObject.h"
#include "BitmapHandler.h"
#include <SFML/Graphics.hpp>

class Player : public SpriteObject{
public:
    Player(BitmapHandler& bmp);
    void handleInput(const sf::Event& event, BitmapHandler& bmp, int& currentBitmap);
    void update();
    void translate(float dx, float dy);
    void scale(float factorX, float factorY);
    void draw(sf::RenderWindow& window, PrimitiveRenderer& renderer)override;
    void animate() override;
    sf::Sprite& getSprite();
    void setTexture(const sf::Texture& texture);

private:
    bool isMoving;
    int currentBitmapIndex;
    const int bitmapIndices_prawy[4] = { 1,5, 6, 7 };
    const int bitmapIndices_lewy[4] = { 2,8, 9, 10 };
    const int bitmapIndices_gora[4] = { 3,11, 12, 13 };
    const int bitmapIndices_dol[4] = { 4,14, 15, 16 };
};

#endif // PLAYER_H
