/*
#include <SFML/Graphics.hpp>
#include "Circle.h"
#include "Rectangle.h"
#include "Point2D.h"
#include "Position.h" // Dodaj import dla Position
#include <iostream>
#include "Player.h"
#include "BitmapHandler.h"


int main() {
    // Tworzenie okna
    sf::RenderWindow window(sf::VideoMode(800, 600), "Shapes Example");

    // Tworzenie okr�gu w �rodku okna
    Point2D circleCenter(400, 300); // �rodek okr�gu
    Circle circle(circleCenter, 100); // Okr�g o promieniu 100

    // Tworzenie prostok�ta
    Point2D rectangleTopLeft(200, 200); // Lewy g�rny r�g prostok�ta
    Rectangle rectangle(rectangleTopLeft, 150, 100); // Prostok�t o szeroko�ci 150 i wysoko�ci 100

    // Tworzenie obiektu Position
    Position position("C:\\Windows\\Fonts\\Arial.ttf"); // Upewnij si�, �e czcionka jest dost�pna
    Player player;


    // P�tla g��wna
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Odczytanie pozycji klikni�cia myszy
                    std::cout << "Klikniecie myszy: X = " << event.mouseButton.x
                        << ", Y = " << event.mouseButton.y << std::endl;
                    // Uaktualnienie informacji o klikni�ciu
                    position.updateClickPosition(event.mouseButton.x, event.mouseButton.y);
                }
            }
            player.handleInput(event, circle, rectangle);
           
        }
        // Odczytanie pozycji kursora myszy tylko w oknie graficznym
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        position.updateCursorPosition(mousePosition.x, mousePosition.y);

        // Czyszczenie okna
        window.clear(sf::Color::White);

        // Rysowanie okr�gu
        circle.draw(window);
        // Rysowanie prostok�ta
        rectangle.draw(window);

        // Rysowanie tekstu z pozycj� kursora i klikni�ciem
        position.draw(window);

        // Wy�wietlenie zawarto�ci okna
        window.display();
    }


    return 0;
}
*/
/*
#include <SFML/Graphics.hpp>
#include "Circle.h"
#include "Rectangle.h"
#include "Point2D.h"
#include "Position.h"
#include <iostream>
#include "Player.h"
#include "BitmapHandler.h"

int main() {
    // Tworzenie okna
    sf::RenderWindow window(sf::VideoMode(800, 600), "Shapes Example");

    // Tworzenie okr�gu w �rodku okna
    Point2D circleCenter(400, 300); // �rodek okr�gu
    Circle circle(circleCenter, 100); // Okr�g o promieniu 100

    // Tworzenie prostok�ta
    Point2D rectangleTopLeft(200, 200); // Lewy g�rny r�g prostok�ta
    Rectangle rectangle(rectangleTopLeft, 150, 100); // Prostok�t o szeroko�ci 150 i wysoko�ci 100

    // Tworzenie obiektu Position
    Position position("C:\\Windows\\Fonts\\Arial.ttf"); // Upewnij si�, �e czcionka jest dost�pna
    Player player;

    // �adowanie i wy�wietlanie bitmapy za pomoc� BitmapHandler
    BitmapHandler bmp;
    if (!bmp.loadFromFile("D:\\Silnik_nowy\\asd.png")) {
        std::cerr << "Nie uda�o si� wczyta� bitmapy." << std::endl;
        return -1;
    }

    // Konwersja bitmapy na tekstur� SFML
    sf::Texture texture;
    texture.loadFromImage(bmp.getImage());  // Pobieramy sf::Image z BitmapHandler

    // Tworzymy sprite, aby wy�wietli� tekstur�
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(100, 100);  // Ustawienie pozycji obrazu na ekranie

    // P�tla g��wna
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Odczytanie pozycji klikni�cia myszy
                    std::cout << "Klikniecie myszy: X = " << event.mouseButton.x
                        << ", Y = " << event.mouseButton.y << std::endl;
                    // Uaktualnienie informacji o klikni�ciu
                    position.updateClickPosition(event.mouseButton.x, event.mouseButton.y);
                }
            }
            player.handleInput(event, circle, rectangle);
        }

        // Odczytanie pozycji kursora myszy tylko w oknie graficznym
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        position.updateCursorPosition(mousePosition.x, mousePosition.y);

        // Czyszczenie okna
        window.clear(sf::Color::White);

        // Rysowanie okr�gu
        circle.draw(window);
        // Rysowanie prostok�ta
        rectangle.draw(window);
        // Rysowanie bitmapy za pomoc� sprite'a
        window.draw(sprite);

        // Rysowanie tekstu z pozycj� kursora i klikni�ciem
        position.draw(window);

        // Wy�wietlenie zawarto�ci okna
        window.display();
    }

    return 0;
}
*/
/*
#include <SFML/Graphics.hpp>
#include "Circle.h"
#include "Rectangle.h"
#include "Point2D.h"
#include "Position.h"
#include <iostream>
#include "Player.h"
#include "BitmapHandler.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Shapes Example");

    // Punkt startowy dla prostok�ta
    Point2D rectangleTopLeft(200, 200);
    Rectangle rectangle(rectangleTopLeft, 150, 100);

    BitmapHandler bmp;
    if (!bmp.loadFromFile("D:\\Silnik_nowy\\asd.png")) {
        std::cerr << "Nie uda�o si� wczyta� bitmapy." << std::endl;
        return -1;
    }

    // Ustawienia tekstury i rozmiaru prostok�ta
    sf::Texture texture;
    texture.loadFromImage(bmp.getImage());
    rectangle.updateSize(bmp.getSize().x, bmp.getSize().y);
    rectangle.setTexture(texture);

    Position position("C:\\Windows\\Fonts\\Arial.ttf");
    Player player;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    position.updateClickPosition(event.mouseButton.x, event.mouseButton.y);
                }
            }
           player.handleInput(event, rectangle);
        }

        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        position.updateCursorPosition(mousePosition.x, mousePosition.y);

        window.clear(sf::Color::White);
        rectangle.draw(window);
        position.draw(window);

        window.display();
    }

    return 0;
}
*/

/*
#include <SFML/Graphics.hpp>
#include "Circle.h"
#include "Rectangle.h"
#include "Point2D.h"
#include "Position.h"
#include <iostream>
#include "Player.h"
#include "BitmapHandler.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Shapes Example");

    // Punkt startowy dla prostok�ta
    Point2D rectangleTopLeft(200, 200);
    Rectangle rectangle(rectangleTopLeft, 150, 100);

    BitmapHandler bmp;
    if (!bmp.loadFromFile("D:\\Silnik_nowy\\asd.png")) {
        std::cerr << "Nie uda�o si� wczyta� bitmapy." << std::endl;
        return -1;
    }

    sf::Sprite sprite;
    sprite.setTexture(bmp.getTexture()); // Ustawienie tekstury bitmapy w sprite
    sprite.setPosition(100, 100); // Pocz�tkowa pozycja sprite'a

    Position position("C:\\Windows\\Fonts\\Arial.ttf");
    Player player;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    position.updateClickPosition(event.mouseButton.x, event.mouseButton.y);
                }
            }
            player.handleInput(event, rectangle, sprite);
        }

        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        position.updateCursorPosition(mousePosition.x, mousePosition.y);

        window.clear(sf::Color::White);
        rectangle.draw(window);
        window.draw(sprite); // Rysowanie sprite'a z bitmap�
        position.draw(window);

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

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Silnik2D");

    // Punkt startowy dla prostok�ta
    Point2D rectangleTopLeft(200, 200);
    Point2D circleCenter(400, 200);
    Rectangle rectangle(rectangleTopLeft, 150, 100);
    Circle circle(circleCenter, 50); 

    BitmapHandler bmp;
    // �adowanie dw�ch bitmap
    if (!bmp.loadFromFile("D:\\Silnik_nowy\\asd.png", 1) 
        || !bmp.loadFromFile("D:\\Silnik_nowy\\asd2.png", 2) 
        || !bmp.loadFromFile("D:\\Silnik_nowy\\asd3.png", 3) 
        || !bmp.loadFromFile("D:\\Silnik_nowy\\asd4.png", 4) 
        || !bmp.loadFromFile("D:\\Silnik_nowy\\asd11.png", 5)
        || !bmp.loadFromFile("D:\\Silnik_nowy\\asd12.png", 6)
        || !bmp.loadFromFile("D:\\Silnik_nowy\\asd13.png", 7)
        || !bmp.loadFromFile("D:\\Silnik_nowy\\lewy2.png", 8)
        || !bmp.loadFromFile("D:\\Silnik_nowy\\lewy3.png", 9)
        || !bmp.loadFromFile("D:\\Silnik_nowy\\lewy4.png", 10)
        || !bmp.loadFromFile("D:\\Silnik_nowy\\gora2.png", 11)
        || !bmp.loadFromFile("D:\\Silnik_nowy\\gora3.png", 12)
        || !bmp.loadFromFile("D:\\Silnik_nowy\\gora4.png", 13)
        || !bmp.loadFromFile("D:\\Silnik_nowy\\dol2.png", 14)
        || !bmp.loadFromFile("D:\\Silnik_nowy\\dol3.png", 15)
        || !bmp.loadFromFile("D:\\Silnik_nowy\\dol4.png", 16)) {
       
        return -1;
    }

    sf::Sprite sprite;
    int currentBitmap = 1; // Rozpocznij od pierwszej bitmapy
    sprite.setTexture(bmp.getTexture(currentBitmap)); // Ustaw pocz�tkow� tekstur�
    sprite.setPosition(100, 100); // Pocz�tkowa pozycja sprite'a

    Position position("C:\\Windows\\Fonts\\Arial.ttf");
    Player player;

    PrimitiveRenderer renderer;
    std::vector<LineSegment> lines;
    bool isDrawingLine = false;
    Point2D lineStart, lineEnd;

    /*
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    position.updateClickPosition(event.mouseButton.x, event.mouseButton.y);
                }
            }
            player.handleInput(event, rectangle, sprite, currentBitmap, bmp); // Przeka� currentBitmap do handleInput
        }
        */
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Obs�uga klikni�cia myszy
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                int x = event.mouseButton.x;
                int y = event.mouseButton.y;

                if (!isDrawingLine) {
                    // Zapisz pocz�tek nowej linii
                    lineStart = Point2D(x, y);
                    isDrawingLine = true;
                }
                else {
                    // Zapisz koniec linii i dodaj j� do wektora
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
        window.draw(sprite); // Rysowanie sprite'a z bitmap�
        position.draw(window);

        //renderer.drawLine(window, Point2D(100, 100), Point2D(200, 200), sf::Color::White); // Linia bia�a
        //renderer.drawLineIncremental(window, Point2D(200, 100), Point2D(300, 200), sf::Color::Red); // Linia czerwona

        // Rysowanie wszystkich zapisanych linii
        for (const auto& line : lines) {
            line.draw(window, renderer);
        }

        window.display();
    }

    return 0;
}
