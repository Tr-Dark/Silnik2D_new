#include "Player.h"
#include "BitmapHandler.h"
#include "BitmapObject.h"


Player::Player() : currentBitmapIndex(0), isMoving(false) {
    // Ініціалізація початкового положення та текстури гравця
    playerRectangle = Rectangle(Point2D(100, 100), 50, 50); // Початковий розмір і позиція
    setTextureRect(sf::IntRect(0, 0, 50, 50)); // Прямокутник текстури спрайта, якщо використовується текстура
}

void Player::handleInput(const sf::Event& event, BitmapHandler& bmp) {
    if (event.type == sf::Event::KeyPressed) {
        isMoving = true;
        switch (event.key.code) {
        case sf::Keyboard::Left:
            animate();
            setTexture(bmp.getTexture(2));  // Анімація ліворуч
            sprite.move(-10, 0);
            break;
        case sf::Keyboard::Right:
            animate();
            setTexture(bmp.getTexture(3));  // Анімація праворуч
            sprite.move(10, 0);
            break;
        case sf::Keyboard::Up:
            animate();
            setTexture(bmp.getTexture(4));  // Анімація вгору
            sprite.move(0, -10);
            break;
        case sf::Keyboard::Down:
            animate();
            setTexture(bmp.getTexture(5));  // Анімація вниз
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
    playerRectangle.translate(dx, dy); // Переміщення прямокутника
    sprite.move(dx, dy);               // Переміщення спрайта
}

// Обертання гравця
void Player::rotate(float angle) {
    playerRectangle.rotate(angle); // Обертання прямокутника
    sprite.rotate(angle);          // Обертання спрайта
}

// Масштабування гравця
void Player::scale(float factorX, float factorY) {
    playerRectangle.scale(factorX, factorY); // Масштабування прямокутника
    sprite.scale(factorX, factorY);          // Масштабування спрайта
}

// Оновлення гравця
void Player::update() {
    if (isMoving) {
        animate(); // Виклик анімації під час руху
    }
}
