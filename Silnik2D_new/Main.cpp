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

        player.setSize(sf::Vector2f(50.0f, 50.0f)); 
        player.setFillColor(sf::Color::Green);      
        player.setPosition(width / 2, height / 2);  
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
    sf::RectangleShape player; 
    float playerSpeed = 200.0f; 

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

    void handleMouseInput(int x, int y) {
        std::cout << "Mouse moved to position: " << x << ", " << y << std::endl;
    }


    void handleKeyboardInput(sf::Keyboard::Key key) {
        if (key == sf::Keyboard::Escape) {
            window.close();
        }
    }

    void update() {
        sf::Vector2f movement(0.0f, 0.0f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            movement.y -= playerSpeed * deltaTime; 
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            movement.y += playerSpeed * deltaTime; 
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            movement.x -= playerSpeed * deltaTime;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            movement.x += playerSpeed * deltaTime; 
        }

        player.move(movement);
    }

    void render() {
        window.clear(sf::Color::Black); 

        window.draw(player); 

        window.display(); 
    }


    float deltaTime = 1.0f / 60.0f;
};

int main() {
    Engine engine(800, 600, "2D Engine with Keyboard Movement", false);
    engine.run(); 
    return 0;
}
