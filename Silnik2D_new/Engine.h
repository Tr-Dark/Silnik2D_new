#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include "PrimitiveRenderer.h"
#include "Point2D.h"
#include "LineSegment.h"
#include <vector>
#include <iostream>
#include <fstream>

class Engine {
public:
    Engine(int width, int height, const std::string& title, bool fullscreen = false);
    void run();
    void logError(const std::string& message);

private:
    sf::RenderWindow window;
    PrimitiveRenderer renderer;
    Point2D p1, p2, p3;
    LineSegment line;

    std::vector<Point2D> openPolylinePoints;
    std::vector<Point2D> closedPolylinePoints;

    void processEvents();
    void handleMouseInput(int x, int y);
    void handleKeyboardInput(sf::Keyboard::Key key);
    void displayMouseCoordinates(int x, int y);
    void update();
    void render();
};

#endif
