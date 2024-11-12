#ifndef PLAYER_H
#define PLAYER_H

#include "SpriteObject.h"
#include "Rectangle.h"
#include "BitmapHandler.h"

class Player : public SpriteObject {
public:
    Player();

    // Метод для обробки вводу
    void handleInput(const sf::Event& event, BitmapHandler& bmp);

    // Метод для оновлення гравця
    void update() override;

    // Трансформаційні методи
    void translate(float dx, float dy) override;
    void rotate(float angle) override;
    void scale(float factorX, float factorY) override;

private:
    bool isMoving;                    // Вказує, чи гравець рухається
    int currentBitmapIndex;           // Індекс поточної текстури
    Rectangle playerRectangle;        // Прямокутник, що представляє гравця
};

#endif // PLAYER_H
