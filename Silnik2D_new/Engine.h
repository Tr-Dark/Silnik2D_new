#ifndef ENGINE_H
#define ENGINE_H
#include <SFML/Graphics.hpp>
#include "BitmapHandler.h"
#include "PrimitiveRenderer.h"
#include "Point2D.h"
#include <vector>
#include "Player.h"
#include <fstream>
#include <array>
#include <string>
#include "Tools.h"
#include <iostream>


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
    bool isRandomMove;
};

#endif // ENGINE_H