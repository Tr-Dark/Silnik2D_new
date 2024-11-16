#ifndef BITMAPHANDLER_H
#define BITMAPHANDLER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>

/**
 * @class BitmapHandler
 * @brief Klasa zarządzająca ładowaniem i przechowywaniem bitmap.
 *
 * Klasa umożliwia ładowanie tekstur z plików oraz dostęp do nich
 * poprzez indeksy. Używana jest w aplikacjach graficznych korzystających z SFML.
 */

class BitmapHandler {
public:
    /**
    * @brief Konstruktor klasy BitmapHandler.
    *
    * Inicjalizuje obiekt klasy BitmapHandler.
    */
    BitmapHandler();
    /**
     * @brief Destruktor klasy BitmapHandler.
     *
     * Usuwa wszystkie zasoby zarządzane przez obiekt.
     */
    ~BitmapHandler();
    /**
     * @brief Ładuje teksturę z pliku i zapisuje ją w podanym indeksie.
     *
     * Funkcja próbuje załadować plik graficzny do tekstury. Jeśli operacja się
     * powiedzie, tekstura zostaje przechowana w wewnętrznym wektorze pod
     * wskazanym indeksem.
     *
     * @param filename Ścieżka do pliku graficznego.
     * @param bitmapIndex Indeks, pod którym tekstura ma zostać zapisana.
     * @return true Jeśli tekstura została pomyślnie załadowana.
     * @return false Jeśli nie udało się załadować tekstury.
     */
    bool loadFromFile(const std::string& filename, int bitmapIndex);
    /**
     * @brief Pobiera teksturę z podanego indeksu.
     *
     * Funkcja zwraca stałą referencję do tekstury znajdującej się
     * w wektorze pod wskazanym indeksem.
     *
     * @param bitmapIndex Indeks tekstury w wektorze.
     * @return Stała referencja do obiektu sf::Texture.
     * @throws std::out_of_range Jeśli indeks wykracza poza zakres wektora.
     */
    const sf::Texture& getTexture(int bitmapIndex) const;

private:
    /**
     * @brief Wektor przechowujący załadowane tekstury.
     *
     * Tekstury są przechowywane jako obiekty sf::Texture w wektorze.
     */
    std::vector<sf::Texture> textures; 
};

#endif // BITMAPHANDLER_H