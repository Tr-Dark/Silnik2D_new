#include "Engine.h"
#include <string>
#include <iostream>
#include <fstream>


Engine::Engine(int width, int height, const std::string& title, bool fullscreen, int fps, sf::Color backgroundColor)
    : fps(fps), backgroundColor(backgroundColor) {
    try {
        if (fullscreen) {
            window.create(sf::VideoMode(width, height), title, sf::Style::Fullscreen);
        }
        else {
            window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
        }

        window.setFramerateLimit(fps);

        if (!window.isOpen()) {
            throw std::runtime_error("Failed to create the window.");
        }
    }
    catch (const std::exception& e) {
        logError(e.what());
    }
} 




void Engine::logError(const std::string& message) {
    std::ofstream errorLog("error_log.txt", std::ios::app);
    if (errorLog.is_open()) {
        errorLog << "Error: " << message << std::endl;
        errorLog.close();
    }
    std::cerr << "Error: " << message << std::endl;
}

void Engine::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Engine::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void Engine::update() {}

void Engine::render() {
    window.clear(backgroundColor);
    window.display();
}