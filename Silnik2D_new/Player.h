#ifndef PLAYER_H
#define PLAYER_H

#include "SpriteObject.h"
#include "ShapeObject.h"
#include "BitmapHandler.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

enum Direction {
    Left,
    Right,
    Up,
    Down,
    None
};


class Player : public SpriteObject{
public:
    Player(std::array<std::string, 16> PlayerSprite);
    void handleInput(const sf::Event& event);
    void update();
    void translate(float dx, float dy);
    void scale(float factorX, float factorY);
    void draw(sf::RenderWindow& window, PrimitiveRenderer& renderer)override;
    void animate() override;
    sf::Sprite& getSprite();
    void setTexture(const sf::Texture& texture);
    BitmapHandler bmp;
    void loadTextures(std::array<std::string, 16> Sprites);
    void animateIdle();

private:
    bool isMoving;
    int currentBitmapIndex;
    Direction currentDirection;
    const int bitmapIndices_prawy[4] = { 1, 2, 3, 4 };
    const int bitmapIndices_lewy[4] = { 5, 6, 7, 8 };
    const int bitmapIndices_gora[4] = { 9, 10, 11, 12 };
    const int bitmapIndices_dol[4] = { 13, 14, 15, 16 };
    sf::Clock idleClock;         // Таймер для відстеження часу бездіяльності
    sf::Clock animationClock;    // Таймер для анімації кадрів
    float idleDelay = 2.0f;      // Затримка перед початком анімації бездіяльності (у секундах)
    float animationDelay = 0.5f; // Затримка між кадрами анімації (у секундах)
    int idleFrameIndex = 0;      // Поточний кадр анімації
    const int idleAnimationFrames[4] = { 13, 14, 15, 16 }; // Кадри анімації бездіяльності
};

#endif // PLAYER_H
