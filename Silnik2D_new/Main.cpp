﻿/*
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
        return -1; // Jeśli nie udało się załadować obrazu, kończymy program
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

        // Rysujemy tło na początku
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

//#include <SFML/Graphics.hpp>
//#include "Rectangle.h"
//#include "Point2D.h"
//#include "Position.h"
//#include <iostream>
//#include "Player.h"
//#include "BitmapHandler.h"
//#include "PrimitiveRenderer.h"
//#include "LineSegment.h"
//
//// Dodajemy odpowiednie nagłówki dla innych klas i zasobów
//
//int main() {
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Silnik2D Demo");
//  
//    Point2D rectangleTopLeft(200, 200);
//    Point2D circleCenter(400, 200);
//    Rectangle rectangle(rectangleTopLeft, 150, 100);
//
//    BitmapHandler bmp;
//    if (!bmp.loadFromFile("../images/asd.png", 1)
//        || !bmp.loadFromFile("../images/asd2.png", 2)
//        || !bmp.loadFromFile("../images/asd3.png", 3)
//        || !bmp.loadFromFile("../images/asd4.png", 4)
//        || !bmp.loadFromFile("../images/asd11.png", 5)
//        || !bmp.loadFromFile("../images/asd12.png", 6)
//        || !bmp.loadFromFile("../images/asd13.png", 7)
//        || !bmp.loadFromFile("../images/lewy2.png", 8)
//        || !bmp.loadFromFile("../images/lewy3.png", 9)
//        || !bmp.loadFromFile("../images/lewy4.png", 10)
//        || !bmp.loadFromFile("../images/gora2.png", 11)
//        || !bmp.loadFromFile("../images/gora3.png", 12)
//        || !bmp.loadFromFile("../images/gora4.png", 13)
//        || !bmp.loadFromFile("../images/dol2.png", 14)
//        || !bmp.loadFromFile("../images/dol3.png", 15)
//        || !bmp.loadFromFile("../images/dol4.png", 16)) {
//
//        return -1;
//    }
//    sf::Texture backgroundTexture;
//    if (!backgroundTexture.loadFromFile("../images/tlo.jpg")) {
//        return -1; // Jeśli nie udało się załadować obrazu, kończymy program
//    }
//    sf::Sprite backgroundSprite(backgroundTexture);
//
//    sf::Sprite sprite;
//    int currentBitmap = 1;
//    sprite.setTexture(bmp.getTexture(currentBitmap));
//    sprite.setPosition(100, 100);
//
//    Position position("C:\\Windows\\Fonts\\Arial.ttf");
//    Player player;
//    PrimitiveRenderer renderer;
//    std::vector<LineSegment> lines;
//    bool isDrawingLine = false;
//    Point2D lineStart, lineEnd;
//    bool useBresenham = true;
//    std::vector<Point2D> polygonPoints = {
//        Point2D(100, 100),
//        Point2D(300, 150),
//        Point2D(250, 300),
//        Point2D(150, 250),
//        Point2D(100, 200)
//    };
//
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed) window.close();
//            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
//                int x = event.mouseButton.x;
//                int y = event.mouseButton.y;
//                if (!isDrawingLine) {
//                    lineStart = Point2D(x, y);
//                    isDrawingLine = true;
//                }
//                else {
//                    lineEnd = Point2D(x, y);
//                    lines.emplace_back(lineStart, lineEnd);
//                    isDrawingLine = false;
//                }
//                position.updateClickPosition(x, y);
//            }
//            player.handleInput(event, rectangle, sprite, currentBitmap, bmp);
//        }
//
//        
//        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
//        position.updateCursorPosition(mousePosition.x, mousePosition.y);
//
//        //window.clear(sf::Color::Black);
//
//        window.clear();
//
//        // Rysujemy tło na początku
//        window.draw(backgroundSprite);
//        
//        renderer.drawCircle(window, Point2D(10, 10), 50, sf::Color::Cyan);
//        renderer.drawFilledCircle(window, Point2D(400, 400), 50, sf::Color::Red);
//        renderer.drawFilledPolygon(window, polygonPoints, sf::Color::Green);
//        //rectangle.draw(window);
//        //circle.draw(window);
//        window.draw(sprite);
//        position.draw(window);
//
//
//        //window.clear();
//        for (const auto& line : lines) {
//            line.draw(window, renderer, sf::Color::Blue);
//        }
//
//        window.display();
//    }
//
//    return 0;
//}


//#include <SFML/Graphics.hpp>
//#include "Player.h"
//#include "BitmapHandler.h"
//
//int main() {
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Game with Animated Player");
//    BitmapHandler bmp;
//    if (!bmp.loadFromFile("../images/asd.png", 1)
//                || !bmp.loadFromFile("../images/asd2.png", 2)
//                || !bmp.loadFromFile("../images/asd3.png", 3)
//                || !bmp.loadFromFile("../images/asd4.png", 4)
//                || !bmp.loadFromFile("../images/asd11.png", 5)
//                || !bmp.loadFromFile("../images/asd12.png", 6)
//                || !bmp.loadFromFile("../images/asd13.png", 7)
//                || !bmp.loadFromFile("../images/lewy2.png", 8)
//                || !bmp.loadFromFile("../images/lewy3.png", 9)
//                || !bmp.loadFromFile("../images/lewy4.png", 10)
//                || !bmp.loadFromFile("../images/gora2.png", 11)
//                || !bmp.loadFromFile("../images/gora3.png", 12)
//                || !bmp.loadFromFile("../images/gora4.png", 13)
//                || !bmp.loadFromFile("../images/dol2.png", 14)
//                || !bmp.loadFromFile("../images/dol3.png", 15)
//                || !bmp.loadFromFile("../images/dol4.png", 16)) {
//        
//                return -1;
//            }
//
//    Player player;
//    player.setTexture(bmp.getTexture(1));
//    PrimitiveRenderer renderer;
//
//    while (window.isOpen()) {
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//            player.handleInput(event, bmp);
//        }
//
//        window.clear();
//        player.draw(window, renderer);
//        window.display();
//    }
//
//    return 0;
//}


//#include "Engine.h"
//
//int main() {
//    Engine engine(800, 600, "Game Engine Demo");
//    engine.run();
//    return 0;
//}


#include <SFML/Graphics.hpp>
#include "Engine.h"
#include "BitmapHandler.h"
#include <iostream>
#include "AnimatedObject.h"
#include "Player.h"


int main() {
    Engine engine(800, 600, "Demo with Background and Primitives");
    engine.loadTextures();
    BitmapHandler bmp;
    Player player(bmp);
    PrimitiveRenderer renderer;
    
   // sf::Sprite sprite;
    
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
        
        
    // Завантаження фону
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("../images/tlo.jpg")) {
        std::cerr << "Failed to load background image\n";
        return -1;
    }
   

   engine.setBackground(backgroundTexture);
   engine.getPlayer().getSprite().setPosition(100, 100);

    engine.run();
    return 0;
}