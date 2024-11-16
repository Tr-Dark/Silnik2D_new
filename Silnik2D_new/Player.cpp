#include "Player.h"
#include "BitmapHandler.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>
#include <string>

/**
 * @brief Konstruktor klasy Player.
 *
 * Inicjalizuje gracza, ustawia pozycję, teksturę i ładuje animacje.
 *
 * @param PlayerSprite Tablica ścieżek do obrazów sprite'ów gracza.
 */
Player::Player(std::array<std::string, 16> PlayerSprite) : currentBitmapIndex(0), isMoving(false), currentDirection(Left) {
    setTextureRect(sf::IntRect(0, 0, 130, 130));  // Prostokąt tekstury sprite'a, jeśli używana jest tekstura
    loadTextures(PlayerSprite);  // Ładowanie tekstur
    setTexture(bmp.getTexture(bitmapIndices_prawy[0]));  // Przypisanie tekstury do sprite
    sprite.setPosition(100, 100);  // Ustawienie pozycji gracza
    std::cout << "Player constructor\n";
}

/**
 * @brief Ustawia teksturę dla sprite'a gracza.
 *
 * @param texture Tekstura, która ma zostać ustawiona.
 */
void Player::setTexture(const sf::Texture& texture) {
    sprite.setTexture(texture);  // Ustawienie tekstury na sprite
    sf::FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);  // Ustawienie punktu początkowego w centrum sprite'a
}

/**
 * @brief Ładuje tekstury z plików i zapisuje je w obiekcie bitmapy.
 *
 * @param Sprites Tablica ścieżek do plików graficznych.
 */
void Player::loadTextures(std::array<std::string, 16> Sprites) {
    for (size_t i = 0; i < Sprites.size(); ++i) {
        if (!bmp.loadFromFile(Sprites[i], i + 1)) {
            std::cerr << "Failed to load: " << Sprites[i] << std::endl;
        }
    }
}

/**
 * @brief Obsługuje wejście gracza z klawiatury.
 *
 * Zmienia pozycję gracza w zależności od wciśniętego klawisza.
 *
 * @param event Zdarzenie klawiatury.
 */
void Player::handleInput(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        isMoving = true;           // Gracz zaczął się poruszać
        idleClock.restart();       // Restartowanie zegara bezczynności

        switch (event.key.code) {
        case sf::Keyboard::Left:
            currentBitmapIndex = (currentBitmapIndex + 1) % 4;
            currentDirection = Direction::Left;
            animate();
            sprite.move(-10, 0);
            break;

        case sf::Keyboard::Right:
            currentBitmapIndex = (currentBitmapIndex + 1) % 4;
            currentDirection = Direction::Right;
            animate();
            sprite.move(10, 0);
            break;

        case sf::Keyboard::Up:
            currentBitmapIndex = (currentBitmapIndex + 1) % 4;
            currentDirection = Direction::Up;
            animate();
            sprite.move(0, -10);
            break;

        case sf::Keyboard::Down:
            currentBitmapIndex = (currentBitmapIndex + 1) % 4;
            currentDirection = Direction::Down;
            animate();
            sprite.move(0, 10);
            break;

        default:
            break;
        }
    }
}

/**
 * @brief Przesuwa gracza o określoną wartość w poziomie i pionie.
 *
 * @param dx Przemieszczenie w osi X.
 * @param dy Przemieszczenie w osi Y.
 */
void Player::translate(float dx, float dy) {
    sprite.move(dx, dy);  // Przemieszczanie sprite'a
}

/**
 * @brief Skaluje sprite gracza.
 *
 * @param factorX Skala w osi X.
 * @param factorY Skala w osi Y.
 */
void Player::scale(float factorX, float factorY) {
    sprite.scale(factorX, factorY);  // Skalowanie sprite'a
}

/**
 * @brief Rysuje gracza na oknie.
 *
 * @param window Okno renderowania.
 */
void Player::draw(sf::RenderWindow& window)
{
    if (sprite.getTexture() == nullptr) {
        std::cerr << "Sprite texture is null!" << std::endl;
    }
    // Rysowanie sprite'a gracza
    window.draw(sprite);  // sprite - obiekt klasy sf::Sprite, który zawiera teksturę gracza
}

/**
 * @brief Rysuje gracza na oknie z użyciem PrimitiveRenderer.
 *
 * @param window Okno renderowania.
 * @param renderer Renderer prymitywów.
 * @param color Kolor rysowanej postaci.
 */
void Player::draw(sf::RenderWindow& window, PrimitiveRenderer& renderer, sf::Color color)
{
    Player::draw(window);  // Rysowanie za pomocą sprite'a
}

/**
 * @brief Animuje gracza w zależności od kierunku.
 */
void Player::animate() {
    const int* bitmapIndices = nullptr;

    // Wybór tablicy tekstur w zależności od kierunku
    switch (currentDirection) {
    case Direction::Left:
        bitmapIndices = bitmapIndices_lewy;
        break;
    case Direction::Right:
        bitmapIndices = bitmapIndices_prawy;
        break;
    case Direction::Up:
        bitmapIndices = bitmapIndices_gora;
        break;
    case Direction::Down:
        bitmapIndices = bitmapIndices_dol;
        break;
    default:
        return;  // Brak animacji, gdy brak kierunku
    }

    // Aktualizacja tekstury w celu animacji
    int textureIndex = bitmapIndices[currentBitmapIndex];
    setTexture(bmp.getTexture(textureIndex));
}

/**
 * @brief Aktualizuje stan gracza.
 *
 * Jeśli gracz się nie porusza, uruchamia animację bezczynności.
 */
void Player::update() {
    // Jeśli gracz się porusza, restartujemy zegar bezczynności
    if (isMoving) {
        idleClock.restart();  // Restartowanie zegara bezczynności
        isMoving = false;     // Resetowanie stanu poruszania się po aktualizacji
    }
    // Jeśli upłynęło więcej czasu niż idleDelay, uruchamiamy animację bezczynności
    else if (idleClock.getElapsedTime().asSeconds() > idleDelay) {
        animateIdle();
    }
}

/**
 * @brief Zwraca referencję do sprite'a gracza.
 *
 * @return Referencja do sprite'a.
 */
sf::Sprite& Player::getSprite() {
    return sprite;  // Zwrócenie referencji do sprite'a
}

/**
 * @brief Animuje stan bezczynności gracza.
 */
void Player::animateIdle() {
    if (animationClock.getElapsedTime().asSeconds() > animationDelay) {
        // Przejście do następnej klatki animacji
        idleFrameIndex = (idleFrameIndex + 1) % 4;
        setTexture(bmp.getTexture(idleAnimationFrames[idleFrameIndex]));

        // Restartowanie zegara animacji
        animationClock.restart();
    }
}

/**
 * @brief Rotuje gracza o określony kąt.
 *
 * @param angle Kąt rotacji.
 */
void Player::rotate(float angle)
{
    // Uzyskanie lokalnych rozmiarów sprite'a
    sf::FloatRect bounds = sprite.getLocalBounds();

    // Obliczanie środka tekstury
    float centerX = bounds.left + bounds.width / 2.0f;
    float centerY = bounds.top + bounds.height / 2.0f;

    // Ustawienie punktu obrotu na środek tekstury
    sprite.setOrigin(centerX, centerY);

    // Wykonanie rotacji
    sprite.rotate(angle);
}
