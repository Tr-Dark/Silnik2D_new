#ifndef PLAYER_H
#define PLAYER_H

#include "SpriteObject.h"
#include "ShapeObject.h"
#include "BitmapHandler.h"
#include <SFML/Graphics.hpp>

class Player : public SpriteObject{
public:
    Player(std::array<std::string, 16> PlayerSprite);
    void handleInput(const sf::Event& event, int& currentBitmap);
    void update();
    void translate(float dx, float dy);
    void scale(float factorX, float factorY);
    void draw(sf::RenderWindow& window, PrimitiveRenderer& renderer)override;
    void animate() override;
    sf::Sprite& getSprite();
    void setTexture(const sf::Texture& texture);
    BitmapHandler bmp;
    void loadTextures(std::array<std::string, 16> Sprites);

private:
    bool isMoving;
    int currentBitmapIndex;
    
    const int bitmapIndices_prawy[4] = { 1, 2, 3, 4 };
    const int bitmapIndices_lewy[4] = { 5, 6, 7, 8 };
    const int bitmapIndices_gora[4] = { 9, 10, 11, 12 };
    const int bitmapIndices_dol[4] = { 13, 14, 15, 16 };
};

#endif // PLAYER_H
