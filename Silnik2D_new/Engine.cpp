#include "Engine.h"

Engine::Engine(int width, int height, const std::string& title, bool fullscreen)
    : p1(100, 100), p2(300, 300), p3(400, 200), line(p1, p2),
    openPolylinePoints({ p1, {200, 150}, {300, 100}, p3 }),
    closedPolylinePoints({ {500, 400}, {600, 450}, {550, 500}, {500, 450} }) {
    try {
        if (fullscreen) {
            window.create(sf::VideoMode(width, height), title, sf::Style::Fullscreen);
        }
        else {
            window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
        }

        if (!window.isOpen()) {
            throw std::runtime_error("Failed to create the window.");
        }

        window.setFramerateLimit(60); 
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
    if (!window.isOpen()) {
        logError("Window could not be opened. Exiting game loop.");
        return;
    }

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

        if (event.type == sf::Event::KeyPressed) {
            handleKeyboardInput(event.key.code);
        }

        if (event.type == sf::Event::MouseMoved) {
            handleMouseInput(event.mouseMove.x, event.mouseMove.y);
        }

        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                displayMouseCoordinates(event.mouseButton.x, event.mouseButton.y);
            }
        }
    }
}

void Engine::handleMouseInput(int x, int y) {
    std::cout << "Mouse moved to position: (" << x << ", " << y << ")" << std::endl;
}

void Engine::handleKeyboardInput(sf::Keyboard::Key key) {
    if (key == sf::Keyboard::Escape) {
        window.close();
    }
}

void Engine::displayMouseCoordinates(int x, int y) {
    std::cout << "Mouse clicked at position: (" << x << ", " << y << ")" << std::endl;
}

void Engine::update() {

}

void Engine::render() {
    window.clear(sf::Color::Black);  

    renderer.drawOpenPolyline(window, openPolylinePoints, sf::Color::Green);
    renderer.drawClosedPolyline(window, closedPolylinePoints, sf::Color::Blue);
    renderer.drawLine(window, p1, p2, sf::Color::Magenta);
    renderer.drawCircle(window, p3, 200, sf::Color::Yellow);
    renderer.drawTriangle(window, { 500, 400 }, p3, { 600, 450 }, sf::Color::Yellow);

    window.display();  
}
