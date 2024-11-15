#include "BitmapHandler.h"

BitmapHandler::BitmapHandler() {
    std::cout << "BitmapHandler constructor\n";
}

BitmapHandler::~BitmapHandler() {
    std::cout << "BitmapHandler: textures deleted...\n";
}

bool BitmapHandler::loadFromFile(const std::string& filename, int bitmapIndex) {
    // Збільшуємо розмір вектора, якщо потрібно
    if (bitmapIndex > textures.size()) {
        textures.resize(bitmapIndex);
    }

    // Завантаження текстури
    if (!textures[bitmapIndex - 1].loadFromFile(filename)) {
        std::cerr << "Failed to load texture from " << filename << std::endl;
        return false;
    }

    std::cout << "BitmapHandler texture " << bitmapIndex << " loaded from " << filename << '\n';
    return true;
}

const sf::Texture& BitmapHandler::getTexture(int bitmapIndex) const {
    if (bitmapIndex < 1 || bitmapIndex > textures.size()) {
        std::cerr << "Invalid bitmap index: " << bitmapIndex << std::endl;
        throw std::out_of_range("Bitmap index out of range");
    }
    return textures[bitmapIndex - 1];
}
