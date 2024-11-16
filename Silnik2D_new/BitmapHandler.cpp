#include "BitmapHandler.h"

BitmapHandler::BitmapHandler() {
    std::cout << "BitmapHandler constructor\n";
}

BitmapHandler::~BitmapHandler() {
    std::cout << "BitmapHandler: textures deleted...\n";
}

/**
 * @brief Ładuje teksturę z pliku do wektora tekstur.
 *
 * Ta metoda ładuje plik tekstury z podanej ścieżki do wektora tekstur w odpowiednim miejscu na podstawie indeksu bitmapy.
 * Jeśli indeks bitmapy jest większy niż rozmiar wektora, rozmiar wektora zostaje zwiększony.
 *
 * @param filename Ścieżka do pliku z teksturą.
 * @param bitmapIndex Indeks bitmapy, gdzie tekstura ma zostać załadowana.
 *
 * @return true, jeśli tekstura została załadowana pomyślnie; false w przeciwnym razie.
 */
bool BitmapHandler::loadFromFile(const std::string& filename, int bitmapIndex) {
    // Zwiększ rozmiar wektora, jeśli to konieczne
    if (bitmapIndex > textures.size()) {
        textures.resize(bitmapIndex);
    }

    // Ładowanie tekstury
    if (!textures[bitmapIndex - 1].loadFromFile(filename)) {
        std::cerr << "Failed to load texture from " << filename << std::endl;
        return false;
    }

    std::cout << "BitmapHandler texture " << bitmapIndex << " loaded from " << filename << '\n';
    return true;
}

/**
 * @brief Zwraca teksturę z określonego indeksu.
 *
 * Ta metoda zwraca referencję do tekstury przechowywanej w wektorze na podstawie podanego indeksu bitmapy.
 * Jeśli indeks jest nieprawidłowy (poza zakresem dostępnych indeksów), metoda zgłasza wyjątek.
 *
 * @param bitmapIndex Indeks bitmapy, której tekstura ma zostać zwrócona.
 *
 * @return Referencja do tekstury o podanym indeksie.
 * @throws std::out_of_range Jeśli indeks bitmapy jest poza dozwolonym zakresem.
 */
const sf::Texture& BitmapHandler::getTexture(int bitmapIndex) const {
    if (bitmapIndex < 1 || bitmapIndex > textures.size()) {
        std::cerr << "Invalid bitmap index: " << bitmapIndex << std::endl;
        throw std::out_of_range("Bitmap index out of range");
    }
    return textures[bitmapIndex - 1];
}
