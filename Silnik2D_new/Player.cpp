/*
#include "Player.h"

Player::Player()
    //: rectangleMoved(false), circleMoved(false), controlRectangle(true) {} // Inicjalizacja zmiennych
    : rectangleMoved(false),  controlRectangle(true) {} // Inicjalizacja zmiennych

//void Player::handleInput(const sf::Event& event, Circle& circle, Rectangle& rectangle) {
void Player::handleInput(const sf::Event& event, Rectangle& rectangle) {
    if (event.type == sf::Event::KeyPressed) {
        // Wybór prostok¹ta lub okrêgu
        switch (event.key.code) {
        case sf::Keyboard::C:
            controlRectangle = false; // Wybierz okr¹g
            break;
        case sf::Keyboard::R:
            controlRectangle = true;  // Wybierz prostok¹t
            break;
        default:
            break;
        }

        // Przesuwanie figury
        switch (event.key.code) {
        case sf::Keyboard::Left:
            if (controlRectangle) {
                rectangle.translate(-10, 0); // Przesuniêcie prostok¹ta w lewo
            }
            else {
                //circle.translate(-10, 0); // Przesuniêcie okrêgu w lewo
            }
            break;

        case sf::Keyboard::Right:
            if (controlRectangle) {
                rectangle.translate(10, 0); // Przesuniêcie prostok¹ta w prawo
            }
            else {
                //circle.translate(10, 0); // Przesuniêcie okrêgu w prawo
            }
            break;

        case sf::Keyboard::Up:
            if (controlRectangle) {
                rectangle.translate(0, -10); // Przesuniêcie prostok¹ta w górê
            }
            else {
                //circle.translate(0, -10); // Przesuniêcie okrêgu w górê
            }
            break;

        case sf::Keyboard::Down:
            if (controlRectangle) {
                rectangle.translate(0, 10); // Przesuniêcie prostok¹ta w dó³
            }
            else {
                //circle.translate(0, 10); // Przesuniêcie okrêgu w dó³
            }
            break;

        default:
            break; // ¯aden z przypadków nie jest spe³niony
        }
    }
}

bool Player::isControllingRectangle() const {
    return controlRectangle;
}
*/
/*
#include "Player.h"

Player::Player()
    : rectangleMoved(false), controlRectangle(true) {} // Inicjalizacja zmiennych

void Player::handleInput(const sf::Event& event, Rectangle& rectangle, sf::Sprite& sprite) {
    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
        case sf::Keyboard::Left:
            rectangle.translate(-10, 0);
            sprite.move(-10, 0); // Przesuniêcie sprite'a w lewo
            break;

        case sf::Keyboard::Right:
            rectangle.translate(10, 0);
            sprite.move(10, 0); // Przesuniêcie sprite'a w prawo
            break;

        case sf::Keyboard::Up:
            rectangle.translate(0, -10);
            sprite.move(0, -10); // Przesuniêcie sprite'a w górê
            break;

        case sf::Keyboard::Down:
            rectangle.translate(0, 10);
            sprite.move(0, 10); // Przesuniêcie sprite'a w dó³
            break;

        default:
            break;
        }
    }
}
*/

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
            currentBitmap = bitmapIndices_lewy[currentBitmapIndex]; // Wybór bitmapy na podstawie indeksu
            sprite.setTexture(bmp.getTexture(currentBitmap)); // Ustawienie wybranej bitmapy
            rectangle.translate(-10, 0);
            sprite.move(-10, 0); // Przesuniêcie sprite'a w lewo

            break;

        case sf::Keyboard::Right:
            
            currentBitmapIndex = (currentBitmapIndex + 1) % 4; // Cykl przez 4 bitmapy (0, 1, 2, 3)
            currentBitmap = bitmapIndices[currentBitmapIndex]; // Wybór bitmapy na podstawie indeksu
            sprite.setTexture(bmp.getTexture(currentBitmap)); // Ustawienie wybranej bitmapy
            rectangle.translate(10, 0);
            sprite.move(10, 0);
            
            break;

        case sf::Keyboard::Up:
           
            currentBitmapIndex = (currentBitmapIndex + 1) % 4; // Cykl przez 4 bitmapy (0, 1, 2, 3)
            currentBitmap = bitmapIndices_gora[currentBitmapIndex]; // Wybór bitmapy na podstawie indeksu
            sprite.setTexture(bmp.getTexture(currentBitmap)); // Ustawienie wybranej bitmapy
            rectangle.translate(0, -10);
            sprite.move(0, -10);

            break;

        case sf::Keyboard::Down:
            
            currentBitmapIndex = (currentBitmapIndex + 1) % 4; // Cykl przez 4 bitmapy (0, 1, 2, 3)
            currentBitmap = bitmapIndices_dol[currentBitmapIndex]; // Wybór bitmapy na podstawie indeksu
            sprite.setTexture(bmp.getTexture(currentBitmap)); // Ustawienie wybranej bitmapy
            rectangle.translate(0, 10);
            sprite.move(0, 10);

            break;

        default:
            break;
        }
    }
}