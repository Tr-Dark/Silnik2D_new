#include "Player.h"
#include "BitmapHandler.h"

Player::Player() : currentBitmapIndex(0), isMoving(false) {
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
    sprite.move(dx, dy); // Переміщення спрайта
}

// Обертання гравця
void Player::rotate(float angle) {
    sprite.rotate(angle); // Обертання спрайта
}

// Масштабування гравця
void Player::scale(float factorX, float factorY) {
    sprite.scale(factorX, factorY); // Масштабування спрайта
}

void Player::draw(sf::RenderWindow& window, PrimitiveRenderer& renderer)
{
    // Використовуємо спрайт для малювання гравця на екрані
    window.draw(sprite);  // sprite - об'єкт класу sf::Sprite, що містить текстуру гравця

    // Якщо потрібно малювати додаткові елементи, наприклад, прямокутник через PrimitiveRenderer:
    //renderer.drawRectangle(window, playerRectangle.getPosition(), playerRectangle.getWidth(), playerRectangle.getHeight(), sf::Color::Blue);
}

// Оновлення гравця
void Player::update() {
    if (isMoving) {
        animate(); // Виклик анімації під час руху
    }
}
