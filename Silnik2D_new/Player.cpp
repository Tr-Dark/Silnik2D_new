#include "Player.h"
#include "BitmapHandler.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Player::Player(BitmapHandler& bmp) : currentBitmapIndex(0), isMoving(false) {
    
setTextureRect(sf::IntRect(0, 0, 50, 50)); // Прямокутник текстури спрайта, якщо використовується текстура

setTexture(bmp.getTexture(bitmapIndices_prawy[0]));  // Przypisanie tekstury do sprite
sprite.setPosition(100, 100);
  
}

void Player::setTexture(const sf::Texture& texture) {
    sprite.setTexture(texture);  // Ustawienie tekstury na sprite
}


void Player::handleInput(const sf::Event& event, BitmapHandler& bmp, int& currentBitmap) {
    
    if (event.type == sf::Event::KeyPressed) {
        isMoving = true;
        
        switch (event.key.code) {
        case sf::Keyboard::Left:
            //animate();
            currentBitmapIndex = (currentBitmapIndex + 1) % 4;
            currentBitmap = bitmapIndices_lewy[currentBitmapIndex];
            setTexture(bmp.getTexture(currentBitmap));  // Анімація ліворуч
            sprite.move(-10, 0);
            break;
        case sf::Keyboard::Right:
            //animate();
            currentBitmapIndex = (currentBitmapIndex + 1) % 4;
            currentBitmap = bitmapIndices_prawy[currentBitmapIndex];
            setTexture(bmp.getTexture(currentBitmap)); 
            sprite.move(10, 0);
            break;
        case sf::Keyboard::Up:
            //animate();
            currentBitmapIndex = (currentBitmapIndex + 1) % 4;
            currentBitmap = bitmapIndices_gora[currentBitmapIndex];
            setTexture(bmp.getTexture(currentBitmap)); // Анімація вгору
            sprite.move(0, -10);
            break;
        case sf::Keyboard::Down:
            //animate();
            currentBitmapIndex = (currentBitmapIndex + 1) % 4;
            currentBitmap = bitmapIndices_dol[currentBitmapIndex];
            setTexture(bmp.getTexture(currentBitmap)); // Анімація вниз
            sprite.move(0, 10);
            break;
        default:
            isMoving = false;
            break;
        }
    }
}

// Переміщення гравця
void Player::translate(float dx, float dy) {
    sprite.move(dx, dy); // Переміщення спрайта
}

// Масштабування гравця
void Player::scale(float factorX, float factorY) {
    sprite.scale(factorX, factorY); // Масштабування спрайта
}

void Player::draw(sf::RenderWindow& window, PrimitiveRenderer& renderer)
{
    if (sprite.getTexture() == nullptr) {
        std::cerr << "Sprite texture is null!" << std::endl;
    }
    // Використовуємо спрайт для малювання гравця на екрані
    window.draw(sprite);  // sprite - об'єкт класу sf::Sprite, що містить текстуру гравця

    // Якщо потрібно малювати додаткові елементи, наприклад, прямокутник через PrimitiveRenderer:
    //renderer.drawRectangle(window, playerRectangle.getPosition(), playerRectangle.getWidth(), playerRectangle.getHeight(), sf::Color::Blue);
}

void Player::animate()
{

}

// Оновлення гравця
void Player::update() {
    if (isMoving) {
        animate(); // Виклик анімації під час руху
    }
}

sf::Sprite& Player::getSprite() {
    return sprite;  // Zwrócenie referencji do sprite
}
