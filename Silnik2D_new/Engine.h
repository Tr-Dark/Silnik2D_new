#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include <string>

class Engine {
public:
    Engine(int width, int height, const std::string& title, bool fullscreen = false, int fps = 60, sf::Color backgroundColor = sf::Color::Black);

    void run();

private:
    void processEvents();
    void update();
    void render();
    void logError(const std::string& message);

    sf::RenderWindow window;
    sf::Color backgroundColor;
    int fps;
};

#endif
