
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "Rectangle.h"
#include "BitmapHandler.h"

class Player {
public:
    Player();
    void handleInput(const sf::Event& event, Rectangle& rectangle, sf::Sprite& sprite, int& currentBitmap, BitmapHandler& bmp);

private:
    bool rectangleMoved;
    bool controlRectangle;
    bool toggleBitmapRight;
    int currentBitmapIndex; 
    const int bitmapIndices[4] = { 1,5, 6, 7 }; 
    const int bitmapIndices_lewy[4] = { 2,8, 9, 10 };
    const int bitmapIndices_gora[4] = { 3,11, 12, 13 };
    const int bitmapIndices_dol[4] = { 4,14, 15, 16 };
};

#endif // PLAYER_H
