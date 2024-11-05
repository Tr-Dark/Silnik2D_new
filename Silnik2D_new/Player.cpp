#include "Player.h"
#include "BitmapHandler.h"
#include "Rectangle.h"


Player::Player()
    : rectangleMoved(false), controlRectangle(true), toggleBitmapRight(false), currentBitmapIndex(0){} // Inicjalizacja zmiennych

void Player::handleInput(const sf::Event& event, Rectangle& rectangle, sf::Sprite& sprite, int& currentBitmap, BitmapHandler& bmp) {
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
        case sf::Keyboard::Left:
           
                currentBitmapIndex = (currentBitmapIndex + 1) % 4; 
            currentBitmap = bitmapIndices_lewy[currentBitmapIndex]; // Wyb�r bitmapy na podstawie indeksu
            sprite.setTexture(bmp.getTexture(currentBitmap)); // Ustawienie wybranej bitmapy
            rectangle.translate(-10, 0);
            sprite.move(-10, 0); // Przesuni�cie sprite'a w lewo

            break;

        case sf::Keyboard::Right:
            
            currentBitmapIndex = (currentBitmapIndex + 1) % 4; // Cykl przez 4 bitmapy (0, 1, 2, 3)
            currentBitmap = bitmapIndices[currentBitmapIndex]; // Wyb�r bitmapy na podstawie indeksu
            sprite.setTexture(bmp.getTexture(currentBitmap)); // Ustawienie wybranej bitmapy
            rectangle.translate(10, 0);
            sprite.move(10, 0);
            
            break;

        case sf::Keyboard::Up:
           
            currentBitmapIndex = (currentBitmapIndex + 1) % 4; // Cykl przez 4 bitmapy (0, 1, 2, 3)
            currentBitmap = bitmapIndices_gora[currentBitmapIndex]; // Wyb�r bitmapy na podstawie indeksu
            sprite.setTexture(bmp.getTexture(currentBitmap)); // Ustawienie wybranej bitmapy
            rectangle.translate(0, -10);
            sprite.move(0, -10);

            break;

        case sf::Keyboard::Down:
            
            currentBitmapIndex = (currentBitmapIndex + 1) % 4; // Cykl przez 4 bitmapy (0, 1, 2, 3)
            currentBitmap = bitmapIndices_dol[currentBitmapIndex]; // Wyb�r bitmapy na podstawie indeksu
            sprite.setTexture(bmp.getTexture(currentBitmap)); // Ustawienie wybranej bitmapy
            rectangle.translate(0, 10);
            sprite.move(0, 10);

            break;

        default:
            break;
        }
    }
}