#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include "BitmapHandler.h"
#include "PrimitiveRenderer.h"
#include "Point2D.h"
#include <vector>
#include "Player.h"
#include <fstream>
#include <array>
#include <string>
#include "Tools.h"
#include <iostream>
#include "Rectangle.h"
#include "LineSegment.h"

/**
 * @class Engine
 * @brief Główna klasa silnika gry.
 *
 * Klasa odpowiedzialna za zarządzanie główną pętlą gry, renderowaniem,
 * obsługą zdarzeń oraz logiką gry. Umożliwia rysowanie obiektów graficznych,
 * obsługę gracza oraz zarządzanie tłem.
 */
class Engine {
public:
    /**
     * @brief Konstruktor klasy Engine.
     *
     * Inicjalizuje okno renderowania, ładuje tekstury graczy oraz ustawia wstępne wartości dla elementów gry.
     *
     * @param width Szerokość okna gry.
     * @param height Wysokość okna gry.
     * @param title Tytuł okna gry.
     * @param PlayerSprite Tablica nazw plików tekstur gracza.
     */
    Engine(int width, int height, const std::string& title, std::array<std::string, 16> PlayerSprite);

    /**
     * @brief Rozpoczyna główną pętlę gry.
     *
     * Odpowiada za wywoływanie metod obsługi zdarzeń, aktualizacji logiki gry i renderowania.
     */
    void run();

    /**
     * @brief Rejestruje błąd w logach.
     *
     * @param message Wiadomość błędu do zapisania w logu.
     */
    void logError(const std::string& message);

    /**
     * @brief Ustawia teksturę tła dla gry.
     *
     * @param texture Tekstura do ustawienia jako tło.
     */
    void setBackground(const sf::Texture& texture);

    /**
     * @brief Obsługuje zdarzenia użytkownika.
     *
     * Odpowiada za przetwarzanie wejścia użytkownika, takich jak ruchy myszy i naciśnięcia klawiszy.
     */
    void processEvents();

    /**
     * @brief Aktualizuje logikę gry.
     *
     * Metoda jest odpowiedzialna za aktualizację stanu gry, takich jak pozycje obiektów i logika gracza.
     */
    void update();

    /**
     * @brief Renderuje wszystkie elementy na ekranie.
     *
     * Odpowiada za rysowanie obiektów gry, takich jak tło, gracz czy elementy graficzne.
     */
    void render();

    /**
     * @brief Zwraca obiekt gracza.
     *
     * @return Referencja do obiektu gracza.
     */
    Player& getPlayer();

    /**
     * @brief Destruktor klasy Engine.
     *
     * Zwalnia zasoby i zamyka okno renderowania.
     */
    ~Engine();

private:
    sf::RenderWindow window;              ///< Okno renderowania SFML.
    sf::Sprite backgroundSprite;          ///< Sprite tła gry.
    PrimitiveRenderer renderer;           ///< Obiekt do renderowania prymitywów graficznych.
    Player player;                        ///< Obiekt reprezentujący gracza.
    bool backgroundLoaded = false;        ///< Czy tło zostało załadowane.
    std::vector<Point2D> triangleVertices;///< Wierzchołki trójkąta.
    Point2D triangleCenter;               ///< Środek geometryczny trójkąta.
    std::vector<Point2D> polyline;        ///< Punkty tworzące prostokąt lub czworokąt.
    std::vector<Point2D> clickPoints;     ///< Wektor przechowujący punkty kliknięć myszy.
    Rectangle rectangle;                  ///< Prostokąt używany w grze.
    bool clearWindow = false;             ///< Flaga do czyszczenia okna.
    float triangleRotation = 0.0f;        ///< Kąt obrotu trójkąta.
    bool isRandomMove;                    ///< Flaga określająca losowy ruch.
    LineSegment line;                     ///< Odcinek używany w grze.
    Point2D first, second;                ///< Punkty końcowe odcinka.
};

#endif // ENGINE_H
