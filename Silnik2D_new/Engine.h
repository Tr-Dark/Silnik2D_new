//#ifndef ENGINE_H
//#define ENGINE_H
//
//#include <SFML/Graphics.hpp>
//#include <string>
//
//class Engine {
//public:
//    Engine(int width, int height, const std::string& title, bool fullscreen = false, int fps = 60, sf::Color backgroundColor = sf::Color::Black);
//
//    void run();
//
//private:
//    void processEvents();
//    void update();
//    void render();
//    void logError(const std::string& message);
//
//    sf::RenderWindow window;
//    sf::Color backgroundColor;
//    int fps;
//};
//
//#endif


// Engine.h
//#ifndef ENGINE_H
//#define ENGINE_H
//
//#include <SFML/Graphics.hpp>
//#include "Player.h"
//#include "PrimitiveRenderer.h"
//#include "BitmapHandler.h"
//#include <vector>
//#include "GameObject.h"
//
//class Engine {
//public:
//    Engine(int width, int height, const std::string& title);
//    void run();
//    //sf::Texture backgroundSprite;
//
//private:
//    void processEvents();
//    void update();
//    void render();
//
//    sf::RenderWindow window;
//    PrimitiveRenderer renderer;
//    BitmapHandler bitmapHandler;
//    std::vector<std::unique_ptr<GameObject>> gameObjects;
//};
//
//#endif // ENGINE_H

// Engine.h
#ifndef ENGINE_H
#define ENGINE_H
#include <SFML/Graphics.hpp>
#include "BitmapHandler.h"
#include "PrimitiveRenderer.h"
#include "Point2D.h"
#include "Position.h"
#include <vector>
#include "Player.h"
#include <fstream>
#include <array>
#include <string>


class Engine {
public:
    Engine(int width, int height, const std::string& title, std::array<std::string, 16> PlayerSprite);
    void run();
    void logError(const std::string& message);
    void setBackground(const sf::Texture& texture);
    void processEvents();
    void update();
    void render();
    Player& getPlayer();
    ~Engine();
private:
    sf::RenderWindow window;
    sf::Sprite backgroundSprite;
    PrimitiveRenderer renderer;
    BitmapHandler bmp;
    Player player;
    //Position mousePosition;
    bool backgroundLoaded = false;

    // Трикутник
    std::vector<Point2D> triangleVertices;
    Point2D triangleCenter;
    //prostokat/чотирикутник
    std::vector<Point2D> polyline;
    //vector для переховування ліній при натисненні миші
    std::vector<Point2D> clickPoints;
    bool clearWindow = false;
    float triangleRotation = 0.0f; // Кут обертання трикутника
};

#endif // ENGINE_H