#include "Player.h"
#include "BitmapHandler.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Player::Player() : currentBitmapIndex(0), isMoving(false) {
    
setTextureRect(sf::IntRect(0, 0, 200, 200)); // Прямокутник текстури спрайта, якщо використовується текстура
loadTextures();
setTexture(bmp.getTexture(bitmapIndices_prawy[0]));  // Przypisanie tekstury do sprite
sprite.setPosition(100, 100);

std::cout << "Player constructor\n";
}

void Player::setTexture(const sf::Texture& texture) {
    sprite.setTexture(texture);// Ustawienie tekstury na sprite
}

void Player::loadTextures() {
    if (!bmp.loadFromFile("../images/asd.png", 1)
        || !bmp.loadFromFile("../images/asd2.png", 2)
        || !bmp.loadFromFile("../images/asd3.png", 3)
        || !bmp.loadFromFile("../images/asd4.png", 4)
        || !bmp.loadFromFile("../images/asd11.png", 5)
        || !bmp.loadFromFile("../images/asd12.png", 6)
        || !bmp.loadFromFile("../images/asd13.png", 7)
        || !bmp.loadFromFile("../images/lewy2.png", 8)
        || !bmp.loadFromFile("../images/lewy3.png", 9)
        || !bmp.loadFromFile("../images/lewy4.png", 10)
        || !bmp.loadFromFile("../images/gora2.png", 11)
        || !bmp.loadFromFile("../images/gora3.png", 12)
        || !bmp.loadFromFile("../images/gora4.png", 13)
        || !bmp.loadFromFile("../images/dol2.png", 14)
        || !bmp.loadFromFile("../images/dol3.png", 15)
        || !bmp.loadFromFile("../images/dol4.png", 16)) {
        std::cerr << "Failed to load some images\n";
        return;
    }
    else std::cout << "texture loaded\n";
}


void Player::handleInput(const sf::Event& event, int& currentBitmap) {
    
    if (event.type == sf::Event::KeyPressed) {
        isMoving = true;
        
        switch (event.key.code) {
        case sf::Keyboard::Left:
            std::cout << "Left\n";
            currentBitmapIndex = (currentBitmapIndex + 1) % 4;
            currentBitmap = bitmapIndices_lewy[currentBitmapIndex];
            std::cout << currentBitmap << '\n';
            setTexture(bmp.getTexture(currentBitmap));  // Анімація ліворуч
            sprite.move(-10, 0);
            break;
        case sf::Keyboard::Right:
            std::cout << "Right\n";
            currentBitmapIndex = (currentBitmapIndex + 1) % 4;
            currentBitmap = bitmapIndices_prawy[currentBitmapIndex];
            std::cout << currentBitmap << '\n';
            setTexture(bmp.getTexture(currentBitmap)); 
            sprite.move(10, 0);
            break;
        case sf::Keyboard::Up:
            std::cout << "Up\n";
            currentBitmapIndex = (currentBitmapIndex + 1) % 4;
            currentBitmap = bitmapIndices_gora[currentBitmapIndex];
            std::cout << currentBitmap << '\n';
            setTexture(bmp.getTexture(currentBitmap)); // Анімація вгору
            sprite.move(0, -10);
            break;
        case sf::Keyboard::Down:
            std::cout << "Down\n";
            currentBitmapIndex = (currentBitmapIndex + 1) % 4;
            currentBitmap = bitmapIndices_dol[currentBitmapIndex];
            std::cout << currentBitmap << '\n';
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
}

void Player::animate()
{
    //if (isMoving) {
    //    currentBitmapIndex = (currentBitmapIndex + 1) % 4; // Перехід до наступного кадру анімації

    //    // Вибір текстури залежно від напрямку
    //    if (sprite.getTexture() == nullptr) {
    //        std::cerr << "Sprite texture is null during animation!" << std::endl;
    //        return;
    //    }

    //    // Напрямок руху визначається поточним положенням спрайта
    //    const sf::Texture* currentTexture = sprite.getTexture();

    //    if (std::find(std::begin(bitmapIndices_prawy), std::end(bitmapIndices_prawy), currentBitmapIndex) != std::end(bitmapIndices_prawy)) {
    //        setTexture(bmp.getTexture()); // Текстура для руху вправо
    //    }
    //    else if (std::find(std::begin(bitmapIndices_lewy), std::end(bitmapIndices_lewy), currentBitmapIndex) != std::end(bitmapIndices_lewy)) {
    //        setTexture(currentTexture); // Текстура для руху вліво
    //    }
    //    else if (std::find(std::begin(bitmapIndices_gora), std::end(bitmapIndices_gora), currentBitmapIndex) != std::end(bitmapIndices_gora)) {
    //        setTexture(currentTexture); // Текстура для руху вгору
    //    }
    //    else if (std::find(std::begin(bitmapIndices_dol), std::end(bitmapIndices_dol), currentBitmapIndex) != std::end(bitmapIndices_dol)) {
    //        setTexture(currentTexture); // Текстура для руху вниз
    //    }
    //}
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
