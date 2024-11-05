#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include "PrimitiveRenderer.h"
#include "Point2D.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

class Engine {
public:
    Engine(int width, int height, const std::string& title, bool fullscreen = false);
    void run();
    void logError(const std::string& message);

private:
    sf::RenderWindow window;
    PrimitiveRenderer renderer;
    void processEvents();
    void update();
    void render();
};

#endif

