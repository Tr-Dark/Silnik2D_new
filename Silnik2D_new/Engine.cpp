#include "Engine.h"

/**
 * @brief Konstruktor klasy Engine, inicjalizuje okno, obiekty i różne parametry.
 *
 * @param width Szerokość okna.
 * @param height Wysokość okna.
 * @param title Tytuł okna.
 * @param PlayerSprite Tablica sprite'ów gracza.
 */
Engine::Engine(int width, int height, const std::string& title, std::array<std::string, 16> PlayerSprite)
    : window(sf::VideoMode(width, height), title),
    triangleVertices{ Point2D(400, 300), Point2D(430, 350), Point2D(370, 350) },
    triangleCenter(400, 334),  // Centrum trójkąta
    player(PlayerSprite), // Tworzenie obiektu Player, przekazując bmp
    rectangle(Point2D(500, 300), 40, 50, sf::Color::Magenta),
    first(450, 450), second(350, 400),
    line(Point2D(450, 450), Point2D(350, 400)),
    polyline{ Point2D(200, 200), Point2D(250, 190), Point2D(350, 200), Point2D(250, 350), Point2D(200, 350) }
{
    std::cout << "Engine constructor\n";
    window.setFramerateLimit(60);
}

/**
 * @brief Zwraca obiekt gracza.
 *
 * @return Referencja do obiektu Player.
 */
Player& Engine::getPlayer()
{
    return player;
}

/**
 * @brief Ustawia tło w oknie gry.
 *
 * @param texture Tekstura tła.
 */
void Engine::setBackground(const sf::Texture& texture) {
    backgroundSprite.setTexture(texture);
    backgroundLoaded = true;
    sf::Vector2u textureSize = texture.getSize();
    sf::Vector2u windowSize = window.getSize();
    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;
    backgroundSprite.setScale(scaleX, scaleY);
}

/**
 * @brief Główna pętla gry, która przetwarza zdarzenia, aktualizuje stan gry i renderuje ją.
 */
void Engine::run() {

    while (window.isOpen()) {
        processEvents();
        update();
        render();

    }
}

/**
 * @brief Przetwarza zdarzenia związane z interakcją z użytkownikiem, takie jak kliknięcia myszą i wciśnięcia klawiszy.
 */
void Engine::processEvents() {
    sf::Event event;
    int currentBitmap = 0;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) { window.close(); }
        player.handleInput(event);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            int x = event.mouseButton.x;
            int y = event.mouseButton.y;
            std::cout << "click on x: " << x << ", y: " << y << '\n';
            if (x > 0 && y > 0 && x < window.getSize().x && y < window.getSize().y) {
                clickPoints.push_back({ (float)x, (float)y });
            }
        }

        if (event.type == sf::Event::KeyPressed) {
            // Sterowanie ruchem
            switch (event.key.code) {
            case sf::Keyboard::W: // W górę
                // Jeśli ruch możliwy, stosujemy go
                if (Tools::CheckMove(triangleVertices, 0, -10, window.getSize().x, window.getSize().y)) {
                    for (Point2D& point : triangleVertices) {
                        point.translate(0, -10);
                    }
                    triangleCenter.translate(0, -10);
                }

                // Jeśli ruch możliwy, stosujemy go
                if (Tools::CheckMove(polyline, 0, -10, window.getSize().x, window.getSize().y)) {
                    for (Point2D& point : polyline) {
                        point.translate(0, -10);
                    }
                }
                break;
            case sf::Keyboard::S: // W dół
                // Jeśli ruch możliwy, stosujemy go
                if (Tools::CheckMove(triangleVertices, 0, 10, window.getSize().x, window.getSize().y)) {
                    for (Point2D& point : triangleVertices) {
                        point.translate(0, 10);
                    }
                    triangleCenter.translate(0, 10);
                }

                // Jeśli ruch możliwy, stosujemy go
                if (Tools::CheckMove(polyline, 0, 10, window.getSize().x, window.getSize().y)) {
                    for (Point2D& point : polyline) {
                        point.translate(0, 10);
                    }
                }

                break;
            case sf::Keyboard::A: // W lewo
                // Jeśli ruch możliwy, stosujemy go
                if (Tools::CheckMove(triangleVertices, -10, 0, window.getSize().x, window.getSize().y)) {
                    for (Point2D& point : triangleVertices) {
                        point.translate(-10, 0);
                    }
                    triangleCenter.translate(-10, 0);
                }
                rectangle.translate(-10, 0);
                line.translate(-20, 0);

                // Jeśli ruch możliwy, stosujemy go
                if (Tools::CheckMove(polyline, -20, 0, window.getSize().x, window.getSize().y)) {
                    for (Point2D& point : polyline) {
                        point.translate(-20, 0);
                    }
                }
                break;
            case sf::Keyboard::D: // W prawo
                // Jeśli ruch możliwy, stosujemy go
                if (Tools::CheckMove(triangleVertices, 10, 0, window.getSize().x, window.getSize().y)) {
                    for (Point2D& point : triangleVertices) {
                        point.translate(10, 0);
                    }
                    triangleCenter.translate(10, 0);
                }
                rectangle.translate(10, 0);
                line.translate(20, 0);
                // Jeśli ruch możliwy, stosujemy go
                if (Tools::CheckMove(polyline, 20, 0, window.getSize().x, window.getSize().y)) {
                    for (Point2D& point : polyline) {
                        point.translate(20, 0);
                    }
                }
                break;
            case sf::Keyboard::I: // Obrót w lewo
                if (triangleRotation > -40.0f) {
                    triangleRotation -= 5.0f;
                }
                break;

            case sf::Keyboard::O: // Obrót w prawo
                if (triangleRotation < 40.0f) {
                    triangleRotation += 5.0f;
                }
                break;
            case sf::Keyboard::K: // Obrót kształtów
                rectangle.rotate(-10.0f);
                player.rotate(-10.0f);
                line.rotate(-10.0f);
                break;
            case sf::Keyboard::L: // Obrót kształtów
                rectangle.rotate(10.0f);
                player.rotate(10.0f);
                break;
            case sf::Keyboard::BackSpace:
                if (!clickPoints.empty()) {
                    clickPoints.pop_back();
                } // Usuwa ostatni element w wektorze
                break;
            case sf::Keyboard::Delete:
                clickPoints.clear();
                break; // Usuwa wszystkie elementy w wektorze 
            case sf::Keyboard::Add:
                PrimitiveRenderer::scalePolygon(polyline, 1.2f, 1.2f);
                rectangle.scale(1.2F, 1.2F);
                line.scale(1.8F, 1.8F);
                break;
            case sf::Keyboard::Subtract:
                PrimitiveRenderer::scalePolygon(polyline, 0.6f, 0.6f);
                rectangle.scale(0.8F, 0.8F);
                line.scale(0.8F, 0.8F);
                break; // Usuwa wszystkie elementy w wektorze 
            case sf::Keyboard::R:
                isRandomMove = !isRandomMove;
                break; // Przełącza tryb ruchów losowych
            case sf::Keyboard::C:
                if (clearWindow)
                {
                    clearWindow = false;
                }
                else { clearWindow = true; }
                break;
            default:
                break;
            }
        }
    }
}

/**
 * @brief Aktualizuje stan gry, w tym ruchy losowe i aktualizację obiektów.
 */
void Engine::update() {
    if (isRandomMove) {
        float dx = Tools::getRandomOffset();
        float dy = Tools::getRandomOffset();
        if (Tools::CheckMove(triangleVertices, dx, dy, window.getSize().x, window.getSize().y)) {
            for (Point2D& point : triangleVertices) {
                point.translate(dx, dy);
            }
            triangleCenter.translate(dx, dy);
        }
    }
    player.update();

    // Obliczanie obrotu trójkąta wokół centrum
    float angleRad = triangleRotation * 3.14159f / 180.0f;
    float cosAngle = cos(angleRad);
    float sinAngle = sin(angleRad);

    for (size_t i = 0; i < triangleVertices.size(); i++) {
        float x = triangleVertices[i].getX() - triangleCenter.getX();
        float y = triangleVertices[i].getY() - triangleCenter.getY();

        float rotatedX = x * cosAngle - y * sinAngle;
        float rotatedY = x * sinAngle + y * cosAngle;

        triangleVertices[i].setX(triangleCenter.getX() + rotatedX);
        triangleVertices[i].setY(triangleCenter.getY() + rotatedY);
    }
}

/**
 * @brief Renderuje obiekty gry na ekranie.
 */
void Engine::render() {
    if (!clearWindow) {
        // Czyszczenie ekranu
        window.clear(sf::Color::Black);
        if (backgroundLoaded) {
            window.draw(backgroundSprite);
        }

        // Rysowanie wielokątów
        renderer.drawFilledPolygon(window, triangleVertices, sf::Color::Green);
        // Rysowanie innych figur
        renderer.drawFilledPolygon(window, polyline, sf::Color::Yellow);
        line.draw(window, renderer, sf::Color::Magenta);
        rectangle.draw(window, renderer, sf::Color::Blue);
        renderer.drawCircle(window, { 500, 500 }, 50, sf::Color::Green);
        renderer.drawFilledCircle(window, { 500, 500 }, 30, sf::Color::Red);
        renderer.drawEllipse(window, { 650, 550 }, 100, 50, sf::Color::Red);
        renderer.drawPolyline(window, clickPoints, sf::Color::Red);
        player.draw(window);
        // Wyświetlanie zaktualizowanego klatki
        window.display();
    }
    else {
        window.clear();
        window.display();
    }
}

/**
 * @brief Loguje błędy do pliku oraz wyświetla je w konsoli.
 *
 * @param message Wiadomość o błędzie.
 */
void Engine::logError(const std::string& message) {
    std::ofstream errorLog("error_log.txt", std::ios::app);
    if (errorLog.is_open()) {
        errorLog << "Error: " << message << std::endl;
        errorLog.close();
    }
    std::cerr << "Error: " << message << std::endl;
}

/**
 * @brief Destruktor klasy Engine, zwalnia zasoby.
 */
Engine::~Engine() {
    triangleVertices.~vector();
    clickPoints.~vector();
}
