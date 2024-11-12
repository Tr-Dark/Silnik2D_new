/*
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


    Point2D rectangleTopLeft(200, 200);
    Point2D circleCenter(400, 200);
    Rectangle rectangle(rectangleTopLeft, 150, 100);
    Circle circle(circleCenter, 50); 

    BitmapHandler bmp;

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
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("../images/tlo.jpg")) {
        return -1; // Jeœli nie uda³o siê za³adowaæ obrazu, koñczymy program
    }
    sf::Sprite backgroundSprite(backgroundTexture);

    sf::Sprite sprite;
    int currentBitmap = 1; 
    sprite.setTexture(bmp.getTexture(currentBitmap)); 
    sprite.setPosition(100, 100); 

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

 
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                int x = event.mouseButton.x;
                int y = event.mouseButton.y;

                if (!isDrawingLine) {
     
                    lineStart = Point2D(x, y);
                    isDrawingLine = true;
                }
                else {

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

        //window.clear(sf::Color::Black);

        window.clear();

        // Rysujemy t³o na pocz¹tku
        window.draw(backgroundSprite);


        rectangle.draw(window);
        circle.draw(window);
        window.draw(sprite); 
        position.draw(window);

        for (const auto& line : lines) {
            line.draw(window, renderer);
        }

        window.display();
    }

    return 0;
}


*/

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

// Dodajemy odpowiednie nag³ówki dla innych klas i zasobów

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Silnik2D Demo");
  
    Point2D rectangleTopLeft(200, 200);
    Point2D circleCenter(400, 200);
    Rectangle rectangle(rectangleTopLeft, 150, 100);
    Circle circle(circleCenter, 50);

    BitmapHandler bmp;
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
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("../images/tlo.jpg")) {
        return -1; // Jeœli nie uda³o siê za³adowaæ obrazu, koñczymy program
    }
    sf::Sprite backgroundSprite(backgroundTexture);

    sf::Sprite sprite;
    int currentBitmap = 1;
    sprite.setTexture(bmp.getTexture(currentBitmap));
    sprite.setPosition(100, 100);

    Position position("C:\\Windows\\Fonts\\Arial.ttf");
    Player player;
    PrimitiveRenderer renderer;
    std::vector<LineSegment> lines;
    bool isDrawingLine = false;
    Point2D lineStart, lineEnd;
    bool useBresenham = true;
    std::vector<Point2D> polygonPoints = {
        Point2D(100, 100),
        Point2D(300, 150),
        Point2D(250, 300),
        Point2D(150, 250),
        Point2D(100, 200)
    };

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                int x = event.mouseButton.x;
                int y = event.mouseButton.y;
                if (!isDrawingLine) {
                    lineStart = Point2D(x, y);
                    isDrawingLine = true;
                }
                else {
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

        //window.clear(sf::Color::Black);

        window.clear();

        // Rysujemy t³o na pocz¹tku
        window.draw(backgroundSprite);
        
        renderer.drawCircle(window, Point2D(10, 10), 50, sf::Color::Cyan);
        renderer.drawFilledCircle(window, Point2D(400, 400), 50, sf::Color::Red);
        renderer.drawFilledPolygon(window, polygonPoints, sf::Color::Green);
        rectangle.draw(window);
        //circle.draw(window);
        window.draw(sprite);
        position.draw(window);


        //window.clear();
        for (const auto& line : lines) {
            line.draw(window, renderer, sf::Color::Blue);
        }

        window.display();
    }

    return 0;
}


//#include <SFML/Graphics.hpp>
//#include "PrimitiveRenderer.h"
//#include "Point2D.h"
//
//int main() {
//    // ????????? ?????
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Fill Algorithms Demo");
//    window.setFramerateLimit(60);
//
//    // ????????? ??'???? ??? ??????????
//    PrimitiveRenderer renderer;
//
//    // ???????????? ????????
//    sf::Color fillColor = sf::Color::Green;       // ????? ??????????
//    sf::Color borderColor = sf::Color::Red;       // ????? ????
//    sf::Color backgroundColor = sf::Color::White; // ????? ???
//
//    // ????????? ???? (????????????), ??? ???????? ???????? ??????????
//    sf::RectangleShape borderShape(sf::Vector2f(400, 300));
//    borderShape.setPosition(200, 150);
//    borderShape.setFillColor(sf::Color::Transparent);
//    borderShape.setOutlineColor(borderColor);
//    borderShape.setOutlineThickness(2);
//
//    // ???????? ?? ?????? ??? ?????????? ??????????? ??????????
//    sf::RenderTexture renderTexture;
//    renderTexture.create(800, 600);
//    renderTexture.clear(backgroundColor);
//    renderTexture.draw(borderShape);
//    renderTexture.display();
//    sf::Sprite renderSprite(renderTexture.getTexture());
//
//    // ???????? ???? ????????
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//
//            // ?????? border fill ??? ?????????? ????? ?????? ????
//            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
//                int x = event.mouseButton.x;
//                int y = event.mouseButton.y;
//                renderer.borderFill(renderTexture, x, y, fillColor, borderColor);
//                renderTexture.display();
//            }
//
//            // ?????? flood fill ??? ?????????? ?????? ?????? ????
//            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right) {
//                int x = event.mouseButton.x;
//                int y = event.mouseButton.y;
//                renderer.floodFill(renderTexture, x, y, fillColor, backgroundColor);
//                renderTexture.display();
//            }
//        }
//
//        // ???????? ?????
//        window.clear(backgroundColor);
//
//        // ???????????? ??????????? ?? ???????
//        window.draw(renderSprite);
//
//        // ???????????? ??????????
//        window.display();
//    }
//
//    return 0;
//}
