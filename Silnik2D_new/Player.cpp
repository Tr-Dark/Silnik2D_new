#include "Player.h"
#include "BitmapHandler.h"
#include "Rectangle.h"


Player::Player()
    : rectangleMoved(false), controlRectangle(true), toggleBitmapRight(false), currentBitmapIndex(0){}

void Player::handleInput(const sf::Event& event, Rectangle& rectangle, sf::Sprite& sprite, int& currentBitmap, BitmapHandler& bmp) {
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
        case sf::Keyboard::Left:
           
                currentBitmapIndex = (currentBitmapIndex + 1) % 4; 
            currentBitmap = bitmapIndices_lewy[currentBitmapIndex]; 
            sprite.setTexture(bmp.getTexture(currentBitmap)); 
            rectangle.translate(-10, 0);
            sprite.move(-10, 0);

            break;

        case sf::Keyboard::Right:
            
            currentBitmapIndex = (currentBitmapIndex + 1) % 4; 
            currentBitmap = bitmapIndices[currentBitmapIndex];
            sprite.setTexture(bmp.getTexture(currentBitmap));
            rectangle.translate(10, 0);
            sprite.move(10, 0);
            
            break;

        case sf::Keyboard::Up:
           
            currentBitmapIndex = (currentBitmapIndex + 1) % 4; 
            currentBitmap = bitmapIndices_gora[currentBitmapIndex];
            sprite.setTexture(bmp.getTexture(currentBitmap)); 
            rectangle.translate(0, -10);
            sprite.move(0, -10);

            break;

        case sf::Keyboard::Down:
            
            currentBitmapIndex = (currentBitmapIndex + 1) % 4; 
            currentBitmap = bitmapIndices_dol[currentBitmapIndex]; 
            sprite.setTexture(bmp.getTexture(currentBitmap)); 
            rectangle.translate(0, 10);
            sprite.move(0, 10);

            break;

        default:
            break;
        }
    }
}