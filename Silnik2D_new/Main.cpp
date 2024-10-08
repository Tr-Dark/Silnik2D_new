#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class Engine {
public:

    Engine(int width, int height, const std::string& title, bool fullscreen = false) {
        if (fullscreen) {
            window.create(sf::VideoMode(width, height), title, sf::Style::Fullscreen);
        }
        else {
            window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
        }

        window.setFramerateLimit(60); 
    }


    void run() {
        while (window.isOpen()) {
            processEvents();   
            update();          
            render();          
        }
    }

private:
    sf::RenderWindow window;


    void processEvents() {
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
        }
    }

    void update() {
    }

    void render() {
        window.clear(sf::Color::Black); 


        window.display(); 
    }


    void handleKeyboardInput(sf::Keyboard::Key key) {
        if (key == sf::Keyboard::Escape) {
            window.close(); 
        }
    }


    void handleMouseInput(int x, int y) {
        std::cout << "Mouse moved to position: " << x << ", " << y << std::endl;
    }
};

int main() {

    Engine engine(800, 600, "2D Engine", false);
    engine.run(); 

    return 0;
}