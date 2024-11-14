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
//void Engine::logError(const std::string& message) {
//    std::ofstream errorLog("error_log.txt", std::ios::app);
//    if (errorLog.is_open()) {
//        errorLog << "Error: " << message << std::endl;
//        errorLog.close();
//    }
//    std::cerr << "Error: " << message << std::endl;
//}
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
//void Engine::update() {}
//
//void Engine::render() {
//    window.clear(backgroundColor);
//    window.display();
//}

// Engine.cpp
//#include "Engine.h"
//#include <iostream>
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
//        if (event.type == sf::Event::Closed)
//            window.close();
//
//        for (auto& obj : gameObjects) {
//            if (auto player = dynamic_cast<Player*>(obj.get())) {
//                player->handleInput(event, bitmapHandler);
//            }
//        }
//    }
//}
//
//void Engine::update() {
//    for (auto& obj : gameObjects) {
//        obj->update();
//    }
//}
//
//void Engine::render() {
//    window.clear(sf::Color::Black);
//    renderer.drawCircle(window, Point2D(500, 500), 50, sf::Color::Green);
//    for (auto& obj : gameObjects) {
//        obj->draw(window, renderer);
//    }
//    
//    window.display();
//}


#include "Engine.h"
#include "Player.h"
#include "Rectangle.h"
#include <vector>
#include "Point2D.h"
#include <iostream>

/*
Engine::Engine(int width, int height, const std::string& title)
    : window(sf::VideoMode(width, height), title),
    triangleVertices{ Point2D(400, 300), Point2D(450, 350), Point2D(350, 350) },
    triangleCenter(400, 325) // Центр трикутника для обертання
{
    window.setFramerateLimit(60);
    BitmapHandler bmp;  // Tworzymy obiekt BitmapHandler
    Player player(bmp); // Przekazujemy bmp do Playera

}
*/
Engine::Engine(int width, int height, const std::string& title)
    : window(sf::VideoMode(width, height), title),
    triangleVertices{ Point2D(400, 300), Point2D(450, 350), Point2D(350, 350) },
    triangleCenter(400, 325),  // Centrum trójkąta
    bmp(), // Tworzenie obiektu BitmapHandler
    player(bmp) // Tworzenie obiektu Player, przekazując bmp
{
    window.setFramerateLimit(60);
    
}
void Engine::loadTextures() {
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
Player& Engine::getPlayer()
{
    return player;
}

void Engine::setBackground(const sf::Texture& texture) {
    backgroundSprite.setTexture(texture);
    backgroundLoaded = true;

}

void Engine::run() {
    BitmapHandler bmp;  // Tworzymy obiekt BitmapHandler
    Player player(bmp); // Przekazujemy bmp do Playera
    
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
            
            player.handleInput(event, bmp, currentBitmap);

        if (event.type == sf::Event::KeyPressed) {
            // Управління рухом
            switch (event.key.code) {
            case sf::Keyboard::W: // Вверх
                for (auto& point : triangleVertices) point.translate(0, -10);
                triangleCenter.translate(0, -10);

                break;
            case sf::Keyboard::S: // Вниз
                for (auto& point : triangleVertices) point.translate(0, 10);
                triangleCenter.translate(0, 10);
                break;
            case sf::Keyboard::A: // Вліво
                for (auto& point : triangleVertices) point.translate(-10, 0);
                triangleCenter.translate(-10, 0);
                break;
            case sf::Keyboard::D: // Вправо
                for (auto& point : triangleVertices) point.translate(10, 0);
                triangleCenter.translate(10, 0);
                break;
                // Обертання
            case sf::Keyboard::I: // Обертання проти годинникової
                triangleRotation -= 10.0f;
                break;
            case sf::Keyboard::O: // Обертання за годинниковою
                triangleRotation += 10.0f;
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
    //player.animate();
    if (backgroundLoaded) {
        window.draw(backgroundSprite);
    }
    player.draw(window, renderer);
    // Малювання трикутника
    renderer.drawPolygon(window, triangleVertices, sf::Color::Yellow, 0); // Замкнений трикутник

    window.display();
}

