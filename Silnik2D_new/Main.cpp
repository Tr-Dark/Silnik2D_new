#include <SFML/Graphics.hpp>
#include "Circle.h"
#include "Rectangle.h"
#include "Point2D.h"
#include "Position.h"
#include <iostream>
#include "Player.h"
#include "BitmapHandler.h"
#include "PrimitiveRenderer.h"
#include "LineSegment.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Silnik2D Demo");

    // Punkt startowy dla prostok¹ta
    Point2D rectangleTopLeft(200, 200);
    Point2D circleCenter(400, 200);
    Rectangle rectangle(rectangleTopLeft, 150, 100);
    Circle circle(circleCenter, 50); 

    BitmapHandler bmp;
    // £adowanie dwóch bitmap
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

        return -1;
    }

    sf::Sprite sprite;
    int currentBitmap = 1; // Rozpocznij od pierwszej bitmapy
    sprite.setTexture(bmp.getTexture(currentBitmap)); // Ustaw pocz¹tkow¹ teksturê
    sprite.setPosition(100, 100); // Pocz¹tkowa pozycja sprite'a

    Position position("C:\\Windows\\Fonts\\Arial.ttf");
    Player player;

    PrimitiveRenderer renderer;
    std::vector<LineSegment> lines;
    bool isDrawingLine = false;
    Point2D lineStart, lineEnd;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Obs³uga klikniêcia myszy
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                int x = event.mouseButton.x;
                int y = event.mouseButton.y;

                if (!isDrawingLine) {
                    // Zapisz pocz¹tek nowej linii
                    lineStart = Point2D(x, y);
                    isDrawingLine = true;
                }
                else {
                    // Zapisz koniec linii i dodaj j¹ do wektora
                    lineEnd = Point2D(x, y);
                    lines.emplace_back(lineStart, lineEnd);
                    isDrawingLine = false;
                }

                position.updateClickPosition(x, y);
            }

            player.handleInput(event, rectangle, sprite, currentBitmap, bmp);
        }


        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        position.updateCursorPosition(mousePosition.x, mousePosition.y);

        window.clear(sf::Color::Black);

        rectangle.draw(window);
        circle.draw(window);
        window.draw(sprite); // Rysowanie sprite'a z bitmap¹
        position.draw(window);

        // Rysowanie wszystkich zapisanych linii
        for (const auto& line : lines) {
            line.draw(window, renderer);
        }

        window.display();
    }

    return 0;
}
