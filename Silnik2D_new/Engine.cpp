//#include "Engine.h"
//#include <string>
//#include <iostream>
//#include <fstream>
//
//
//Engine::Engine(int width, int height, const std::string& title, bool fullscreen, int fps, sf::Color backgroundColor)
//    : fps(fps), backgroundColor(backgroundColor) {
//    try {
//        if (fullscreen) {
//            window.create(sf::VideoMode(width, height), title, sf::Style::Fullscreen);
//        }
//        else {
//            window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
//        }
//
//        window.setFramerateLimit(fps);
//
//        if (!window.isOpen()) {
//            throw std::runtime_error("Failed to create the window.");
//        }
//    }
//    catch (const std::exception& e) {
//        logError(e.what());
//    }
//} 
//
//
//
//


//void Engine::run() {
//    while (window.isOpen()) {
//        processEvents();
//        update();
//        render();
//    }
//}
//
//void Engine::processEvents() {
//    sf::Event event;
//    while (window.pollEvent(event)) {
//        if (event.type == sf::Event::Closed) {
//            window.close();
//        }
//    }
//}
//

//Engine::Engine(int width, int height, const std::string& title)
//    : window(sf::VideoMode(width, height), title) {
//    window.setFramerateLimit(60);
//
//    // Завантаження ресурсів (текстур для анімацій)
//    BitmapHandler& bmp = bitmapHandler;
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
//        std::cerr << "Error loading images." << std::endl;
//        return;
//    }
//    sf::Texture backgroundTexture;
//    if (!backgroundTexture.loadFromFile("../images/tlo.jpg")) {
//        //return -1; // Jeśli nie udało się załadować obrazu, kończymy program
//    }
//    sf::Sprite backgroundSprite(backgroundTexture);
//
//    // Створення і додавання гравця
//    auto player = std::make_unique<Player>();
//    gameObjects.push_back(std::move(player));
//}



#include "Engine.h"
#include "Player.h"
#include "Rectangle.h"
#include <vector>
#include "Point2D.h"
#include "Position.h"
#include <iostream>
#include "BitmapHandler.h"


Engine::Engine(int width, int height, const std::string& title)
    : window(sf::VideoMode(width, height), title),
    triangleVertices{ Point2D(400, 300), Point2D(430, 350), Point2D(370, 350) },
    triangleCenter(400, 334),  // Centrum trójkąta
    //bmp(), // Tworzenie obiektu BitmapHandler
    player(), // Tworzenie obiektu Player, przekazując bmp
    polyline{Point2D(200, 200), Point2D(250, 200), Point2D(250, 350), Point2D(200, 350)}
{   
    std::cout << "Engine constructor\n";
    window.setFramerateLimit(60);
}

Player& Engine::getPlayer()
{
    return player;
}

void Engine::setBackground(const sf::Texture& texture) {
    backgroundSprite.setTexture(texture);
    backgroundLoaded = true;

}

void Engine::run() {  // Tworzymy obiekt BitmapHandler
    
    while (window.isOpen()) {        
        processEvents();
        update();
        render();
        player.update();
    }
}

void Engine::processEvents() {
    sf::Event event;
    int currentBitmap = 0;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {window.close();}
            player.handleInput(event, currentBitmap);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            int x = event.mouseButton.x;
            int y = event.mouseButton.y;
            std::cout << "click on x: " << x << ", y: " << y << '\n';
            if (x > 0 && y > 0 && x < window.getSize().x && y < window.getSize().y) {
                clickPoints.push_back({ (float)x, (float)y });
            }
        }

        if (event.type == sf::Event::KeyPressed) {
            // Управління рухом
            switch (event.key.code) {
            case sf::Keyboard::W: // Вверх
                for (Point2D& point : triangleVertices) { point.translate(0, -10); }
                triangleCenter.translate(0, -10);

                break;
            case sf::Keyboard::S: // Вниз
                for (Point2D& point : triangleVertices) { point.translate(0, 10); }
                triangleCenter.translate(0, 10);
                break;
            case sf::Keyboard::A: // Вліво
                for (Point2D& point : triangleVertices) { point.translate(-10, 0); }
                triangleCenter.translate(-10, 0);
                break;
            case sf::Keyboard::D: // Вправо
                for (Point2D& point : triangleVertices) { point.translate(10, 0); }
                triangleCenter.translate(10, 0);
                break;
                // Обертання
            case sf::Keyboard::I: // Обертання проти годинникової
                triangleRotation -= 10.0f;
                break;
            case sf::Keyboard::O: // Обертання за годинниковою
                triangleRotation += 10.0f;
                break;
            case sf::Keyboard::BackSpace:
                if (!clickPoints.empty()) {
                    clickPoints.pop_back();
                } // видаляє остатній елемент в векторі
                break;
            case sf::Keyboard::Delete:
                clickPoints.clear();
                break;// видяляє всі елементи в векторі 
            case sf::Keyboard::C:
                if (clearWindow)
                {
                    clearWindow = false;
                }
                else { clearWindow = true; }
                break;
            default:
                break;
            }
        }
    }
}

void Engine::update() {
    // Обчислення обертання трикутника навколо центру
    float angleRad = triangleRotation * 3.14159f / 180.0f;
    float cosAngle = cos(angleRad);
    float sinAngle = sin(angleRad);

    for (size_t i = 0; i < triangleVertices.size(); i++) {
        float x = triangleVertices[i].getX() - triangleCenter.getX();
        float y = triangleVertices[i].getY() - triangleCenter.getY();

        float rotatedX = x * cosAngle - y * sinAngle;
        float rotatedY = x * sinAngle + y * cosAngle;

        triangleVertices[i].setX(triangleCenter.getX() + rotatedX);
        triangleVertices[i].setY(triangleCenter.getY() + rotatedY);
    }
}

void Engine::render() {
    
    if (!clearWindow) {
        if (backgroundLoaded) {
            window.draw(backgroundSprite);
        }
        player.draw(window, renderer);

        renderer.drawFilledPolygon(window, polyline, sf::Color::Yellow);//замальований чотирикутник 
        renderer.drawPolyline(window, polyline, sf::Color::Black, 1);//чорний чотирикутник
        renderer.drawFilledPolygon(window, triangleVertices, sf::Color::Black);//Малювання замкненого трикутника
        renderer.drawCircle(window, { 500, 500 }, 50, sf::Color::Green);
        renderer.drawFilledCircle(window, { 500, 500 }, 30, sf::Color::Red);
        renderer.drawEllipse(window, { 650, 550 }, 100, 50, sf::Color::Red);
        renderer.drawPolyline(window, clickPoints, sf::Color::Red);
        
    }
    else window.clear();
    window.display();
}

void Engine::logError(const std::string& message) {
    std::ofstream errorLog("error_log.txt", std::ios::app);
    if (errorLog.is_open()) {
        errorLog << "Error: " << message << std::endl;
        errorLog.close();
    }
    std::cerr << "Error: " << message << std::endl;
}

Engine::~Engine(){
    triangleVertices.~vector();
    clickPoints.~vector();
}