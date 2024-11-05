/*
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "Circle.h"
#include "Rectangle.h"

class Player {
public:
    Player(); // Konstruktor

    //void handleInput(const sf::Event& event, Circle& circle, Rectangle& rectangle);
    void handleInput(const sf::Event& event,  Rectangle& rectangle);
    bool isControllingRectangle() const; // Metoda do sprawdzenia, czy kontrolowany jest prostok¹t

private:
    bool rectangleMoved; // Flaga do sprawdzania, czy prostok¹t zosta³ przesuniêty
    //bool circleMoved;    // Flaga do sprawdzania, czy okr¹g zosta³ przesuniêty
    bool controlRectangle; // Flaga do okreœlenia, która figura jest kontrolowana
};

#endif // PLAYER_H
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "Rectangle.h"
#include "BitmapHandler.h"

class Player {
public:
    Player();
    void handleInput(const sf::Event& event, Rectangle& rectangle, sf::Sprite& sprite, int& currentBitmap, BitmapHandler& bmp);

private:
    bool rectangleMoved;
    bool controlRectangle;
    bool toggleBitmapRight;
    int currentBitmapIndex; // Zmienna do przechowywania indeksu aktualnej bitmapy
    const int bitmapIndices[4] = { 1,5, 6, 7 }; // Tablica z indeksami bitmap
    const int bitmapIndices_lewy[4] = { 2,8, 9, 10 };
    const int bitmapIndices_gora[4] = { 3,11, 12, 13 };
    const int bitmapIndices_dol[4] = { 4,14, 15, 16 };
};

#endif // PLAYER_H

/*
#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "Rectangle.h"
#include "BitmapHandler.h"

class Player {
public:
    Player();
    void handleInput(const sf::Event& event, Rectangle& rectangle, sf::Sprite& sprite, int& currentBitmap, BitmapHandler& bmp);

private:
    bool rectangleMoved;
    bool controlRectangle;
};

#endif // PLAYER_H
*/

