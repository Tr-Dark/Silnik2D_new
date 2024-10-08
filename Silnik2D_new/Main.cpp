#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

class Engine {
public:
    // Ініціалізація графічної бібліотеки та вікна
    Engine(int width, int height, const std::string& title, bool fullscreen = false) {
        if (fullscreen) {
            window.create(sf::VideoMode(width, height), title, sf::Style::Fullscreen);
        }
        else {
            window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
        }

        window.setFramerateLimit(60); // Кількість кадрів на секунду

        // Ініціалізація об'єкта для переміщення (квадрат)
        player.setSize(sf::Vector2f(50.0f, 50.0f)); // Розмір квадрата
        player.setFillColor(sf::Color::Green);      // Колір квадрата
        player.setPosition(width / 2, height / 2);  // Початкова позиція
    }

    // Основна петельна функція
    void run() {
        while (window.isOpen()) {
            processEvents();   // Обробка подій
            update();          // Логіка гри
            render();          // Рендеринг
        }
    }

private:
    sf::RenderWindow window;
    sf::RectangleShape player; // Об'єкт-квадрат для переміщення
    float playerSpeed = 200.0f; // Швидкість руху

    // Обробка подій клавіатури і миші
    void processEvents() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();  // Закриття вікна
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

    // Логіка оновлення (рух об'єкта)
    void update() {
        sf::Vector2f movement(0.0f, 0.0f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            movement.y -= playerSpeed * deltaTime; // Рух вгору
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            movement.y += playerSpeed * deltaTime; // Рух вниз
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            movement.x -= playerSpeed * deltaTime; // Рух вліво
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            movement.x += playerSpeed * deltaTime; // Рух вправо
        }

        // Оновлення позиції об'єкта
        player.move(movement);
    }

    // Функція рендерингу
    void render() {
        window.clear(sf::Color::Black); // Очищення екрану

        window.draw(player); // Малювання об'єкта

        window.display(); // Виведення на екран
    }

    // Час між кадрами (для коректного руху)
    float deltaTime = 1.0f / 60.0f; // 60 кадрів на секунду
};

int main() {
    // Ініціалізація рушія з параметрами
    Engine engine(800, 600, "2D Engine with Keyboard Movement", false);
    engine.run(); // Запуск рушія

    return 0;
}
