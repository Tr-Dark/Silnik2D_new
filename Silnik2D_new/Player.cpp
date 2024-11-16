#include "Player.h"
#include "BitmapHandler.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>
#include <string>

Player::Player(std::array<std::string, 16> PlayerSprite) : currentBitmapIndex(0), isMoving(false), currentDirection(Left) {
    
setTextureRect(sf::IntRect(0, 0, 130, 130)); // Прямокутник текстури спрайта, якщо використовується текстура
loadTextures(PlayerSprite);
setTexture(bmp.getTexture(bitmapIndices_prawy[0]));  // Przypisanie tekstury do sprite
sprite.setPosition(100, 100);
std::cout << "Player constructor\n";
}

void Player::setTexture(const sf::Texture& texture) {
    sprite.setTexture(texture);// Ustawienie tekstury na sprite
    sf::FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
}
void Player::loadTextures(std::array<std::string, 16> Sprites) {
    for (size_t i = 0; i < Sprites.size(); ++i) {
        if (!bmp.loadFromFile(Sprites[i], i + 1)) {
            std::cerr << "Failed to load: " << Sprites[i] << std::endl;
        }
    }
}


void Player::handleInput(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        isMoving = true;          // Гравець почав рухатися
        idleClock.restart();      // Скидаємо таймер бездіяльності

        switch (event.key.code) {
        case sf::Keyboard::Left:
            currentBitmapIndex = (currentBitmapIndex + 1) % 4;
            currentDirection = Direction::Left;
            animate();
            sprite.move(-10, 0);
            break;

        case sf::Keyboard::Right:
            currentBitmapIndex = (currentBitmapIndex + 1) % 4;
            currentDirection = Direction::Right;
            animate();
            sprite.move(10, 0);
            break;

        case sf::Keyboard::Up:
            currentBitmapIndex = (currentBitmapIndex + 1) % 4;
            currentDirection = Direction::Up;
            animate();
            sprite.move(0, -10);
            break;

        case sf::Keyboard::Down:
            currentBitmapIndex = (currentBitmapIndex + 1) % 4;
            currentDirection = Direction::Down;
            animate();
            sprite.move(0, 10);
            break;

        default:
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

void Player::draw(sf::RenderWindow& window)
{
    if (sprite.getTexture() == nullptr) {
        std::cerr << "Sprite texture is null!" << std::endl;
    }
    // Використовуємо спрайт для малювання гравця на екрані
    window.draw(sprite);  // sprite - об'єкт класу sf::Sprite, що містить текстуру гравця
}


void Player::draw(sf::RenderWindow& window, PrimitiveRenderer& renderer, sf::Color color)
{
    Player::draw(window);
}

void Player::animate() {
    const int* bitmapIndices = nullptr;

    // Вибір масиву текстур залежно від напрямку
    switch (currentDirection) {
    case Direction::Left:
        bitmapIndices = bitmapIndices_lewy;
        break;
    case Direction::Right:
        bitmapIndices = bitmapIndices_prawy;
        break;
    case Direction::Up:
        bitmapIndices = bitmapIndices_gora;
        break;
    case Direction::Down:
        bitmapIndices = bitmapIndices_dol;
        break;
    default:
        return; // Немає анімації, якщо немає напрямку
    }

    // Оновлення текстури для анімації
    int textureIndex = bitmapIndices[currentBitmapIndex];
    setTexture(bmp.getTexture(textureIndex));
}

// Оновлення гравця
void Player::update() {
    // Якщо гравець рухається, скидаємо таймер бездіяльності
    if (isMoving) {
        idleClock.restart(); // Скидаємо таймер бездіяльності
        isMoving = false;    // Скидаємо стан руху після оновлення
    }
    // Якщо минуло більше idleDelay секунд без руху, запускаємо анімацію бездіяльності
    else if (idleClock.getElapsedTime().asSeconds() > idleDelay) {
        animateIdle();
    }
}

sf::Sprite& Player::getSprite() {
    return sprite;  // Zwrócenie referencji do sprite
}

void Player::animateIdle() {
    if (animationClock.getElapsedTime().asSeconds() > animationDelay) {
        // Перехід до наступного кадру
        idleFrameIndex = (idleFrameIndex + 1) % 4;
        setTexture(bmp.getTexture(idleAnimationFrames[idleFrameIndex]));

        // Перезапуск таймера анімації
        animationClock.restart();
    }
}

void Player::rotate(float angle)
{
    // Отримуємо локальні розміри спрайта
    sf::FloatRect bounds = sprite.getLocalBounds();

    // Обчислюємо центр текстури
    float centerX = bounds.left + bounds.width / 2.0f;
    float centerY = bounds.top + bounds.height / 2.0f;

    // Встановлюємо точку обертання (центр текстури)
    sprite.setOrigin(centerX, centerY);

    // Виконуємо обертання
    sprite.rotate(angle);
}
