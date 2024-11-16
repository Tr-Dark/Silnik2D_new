#include <SFML/Graphics.hpp>
#include "Engine.h"
#include "BitmapHandler.h"
#include <iostream>
#include "AnimatedObject.h"
#include "Player.h"
#include <array>
#include <string>


/**
 * @brief Funkcja główna programu.
 *
 * Tworzy instancję silnika gry i uruchamia go. Ładuje tło oraz ustawia pozycję gracza.
 *
 * @return Zwraca 0 w przypadku sukcesu, -1 w przypadku błędu.
 */
int main() {
    // Ścieżki do obrazów animacji gracza
    std::array<std::string, 16> PlayerSpriteimagePaths = {
        "../images/prawy1.png",
        "../images/prawy2.png",
        "../images/prawy3.png",
        "../images/prawy4.png",
        "../images/lewy1.png",
        "../images/lewy2.png",
        "../images/lewy3.png",
        "../images/lewy4.png",
        "../images/gora1.png",
        "../images/gora2.png",
        "../images/gora3.png",
        "../images/gora4.png",
        "../images/dol1.png",
        "../images/dol2.png",
        "../images/dol3.png",
        "../images/dol4.png"
    };

    // Ścieżka do pliku tła
    std::string backgroundFilePath = "../images/tlo.png";

    // Tworzenie obiektu silnika z rozmiarem okna 800x600 i tytułem
    Engine engine(800, 600, "Demo with Background and Primitives", PlayerSpriteimagePaths);

    // Załadowanie tła
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile(backgroundFilePath)) {
        std::cerr << "Failed to load background image\n";
        return -1;  // Zwraca błąd, jeśli tło nie zostało załadowane
    }

    // Ustawienie tła w silniku
    engine.setBackground(backgroundTexture);

    // Ustawienie początkowej pozycji gracza
    engine.getPlayer().getSprite().setPosition(100, 100);

    // Uruchomienie gry
    engine.run();

    return 0;  // Zwraca 0 w przypadku zakończenia programu
}
