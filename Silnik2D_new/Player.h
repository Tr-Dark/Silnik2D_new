#ifndef PLAYER_H
#define PLAYER_H

#include "SpriteObject.h"
#include "ShapeObject.h"
#include "BitmapHandler.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

/**
 * @enum Direction
 * @brief Definiuje kierunki ruchu gracza.
 */
enum Direction {
    Left,  ///< Ruch w lewo.
    Right, ///< Ruch w prawo.
    Up,    ///< Ruch w górę.
    Down,  ///< Ruch w dół.
    None   ///< Brak ruchu.
};

/**
 * @class Player
 * @brief Reprezentuje gracza w grze.
 *
 * Klasa gracza rozszerza funkcjonalność SpriteObject, umożliwiając animację,
 * obsługę wejścia oraz rysowanie gracza na ekranie.
 */
class Player : public SpriteObject {
public:
    /**
     * @brief Konstruktor klasy Player.
     *
     * Inicjalizuje gracza oraz ładuje tekstury na podstawie przekazanej tablicy nazw plików.
     *
     * @param PlayerSprite Tablica nazw plików tekstur do załadowania.
     */
    Player(std::array<std::string, 16> PlayerSprite);

    /**
     * @brief Obsługuje wejście od użytkownika.
     *
     * Funkcja analizuje zdarzenia SFML i odpowiednio aktualizuje stan gracza.
     *
     * @param event Zdarzenie SFML.
     */
    void handleInput(const sf::Event& event);

    /**
     * @brief Aktualizuje stan gracza.
     */
    void update();

    /**
     * @brief Przesuwa gracza o podane wartości.
     *
     * @param dx Przesunięcie w osi X.
     * @param dy Przesunięcie w osi Y.
     */
    void translate(float dx, float dy);

    /**
     * @brief Skaluje sprite gracza.
     *
     * @param factorX Współczynnik skalowania w osi X.
     * @param factorY Współczynnik skalowania w osi Y.
     */
    void scale(float factorX, float factorY);

    /**
     * @brief Rysuje gracza na ekranie.
     *
     * @param window Okno SFML do rysowania.
     */
    void draw(sf::RenderWindow& window) override;

    /**
     * @brief Rysuje gracza z wykorzystaniem renderera prymitywów.
     *
     * @param window Okno SFML do rysowania.
     * @param renderer Renderer prymitywów.
     * @param color Kolor do rysowania (domyślnie sf::Color::White).
     */
    void draw(sf::RenderWindow& window, PrimitiveRenderer& renderer, sf::Color color = sf::Color::White) override;

    /**
     * @brief Odpowiada za animację gracza.
     */
    void animate() override;

    /**
     * @brief Pobiera referencję do sprite'a gracza.
     *
     * @return Referencja do sf::Sprite reprezentującego gracza.
     */
    sf::Sprite& getSprite();

    /**
     * @brief Ustawia teksturę sprite'a gracza.
     *
     * @param texture Tekstura do ustawienia.
     */
    void setTexture(const sf::Texture& texture);

    /**
     * @brief Ładuje tekstury dla animacji gracza.
     *
     * @param Sprites Tablica nazw plików tekstur do załadowania.
     */
    void loadTextures(std::array<std::string, 16> Sprites);

    /**
     * @brief Animuje bezczynność gracza.
     */
    void animateIdle();

    /**
     * @brief Obraca sprite gracza.
     *
     * @param angle Kąt obrotu w stopniach.
     */
    void rotate(float angle);

private:
    bool isMoving;             ///< Określa, czy gracz się porusza.
    int currentBitmapIndex;    ///< Aktualny indeks bitmapy.
    Direction currentDirection; ///< Aktualny kierunek ruchu.

    // Tablice indeksów dla animacji
    const int bitmapIndices_prawy[4] = { 1, 2, 3, 4 }; ///< Indeksy bitmap dla ruchu w prawo.
    const int bitmapIndices_lewy[4] = { 5, 6, 7, 8 }; ///< Indeksy bitmap dla ruchu w lewo.
    const int bitmapIndices_gora[4] = { 9, 10, 11, 12 }; ///< Indeksy bitmap dla ruchu w górę.
    const int bitmapIndices_dol[4] = { 13, 14, 15, 16 }; ///< Indeksy bitmap dla ruchu w dół.

    sf::Clock idleClock;         ///< Zegar do śledzenia bezczynności.
    sf::Clock animationClock;    ///< Zegar do śledzenia czasu między klatkami animacji.
    float idleDelay = 2.0f;      ///< Opóźnienie przed animacją bezczynności (w sekundach).
    float animationDelay = 0.5f; ///< Opóźnienie między klatkami animacji (w sekundach).
    int idleFrameIndex = 0;      ///< Aktualny indeks klatki animacji bezczynności.
    const int idleAnimationFrames[4] = { 13, 14, 15, 16 }; ///< Klatki animacji bezczynności.

    BitmapHandler bmp; ///< Obiekt do obsługi bitmap.
};

#endif // PLAYER_H
