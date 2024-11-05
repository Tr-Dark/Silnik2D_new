
#include "Engine.h"
#include <string>

Engine::Engine(int width, int height, const std::string& title, bool fullscreen) {
    window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
    window.setFramerateLimit(60);
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
    window.clear(sf::Color::Black);
    window.display();
}

/*
#include "Engine.h"
#include <iostream>
#include "Player.h"


// Konstruktor klasy Engine
Engine::Engine(int width, int height, const std::string& title, bool fullscreen)
    : window(sf::VideoMode(width, height), title, fullscreen ? sf::Style::Fullscreen : sf::Style::Default) {
    // Inicjalizacja renderera, gracza i innych zasobów
}

// Główna pętla gry
void Engine::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

// Logowanie błędów
void Engine::logError(const std::string& message) {
    std::cerr << "Error: " << message << std::endl;
}

// Przetwarzanie zdarzeń
void Engine::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Engine::update() {
    // Obliczanie deltaTime
    static sf::Clock clock;
    float deltaTime = clock.restart().asSeconds();

    player.update(deltaTime); // Umożliwia graczowi sterowanie
}

// Renderowanie obiektów
void Engine::render() {
    window.clear();
    // Renderuj obiekty tutaj (np. player.draw())
    window.display();
}
*/