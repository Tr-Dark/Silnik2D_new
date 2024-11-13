#include "BitmapHandler.h"
#include <iostream>
#include "Rectangle.h"

BitmapHandler::BitmapHandler() = default;

bool BitmapHandler::loadFromFile(const std::string& filename, int bitmapIndex) {
    // Sprawdzanie i ładowanie tekstury w zależności od indeksu
    switch (bitmapIndex) {
    case 1:
        if (!bitmap1.loadFromFile(filename)) {
            std::cerr << "Failed to load texture from " << filename << std::endl;
            return false;
        }
        texture1.loadFromImage(bitmap1);
        break;
    case 2:
        if (!bitmap2.loadFromFile(filename)) {
            std::cerr << "Failed to load texture from " << filename << std::endl;
            return false;
        }
        texture2.loadFromImage(bitmap2);
        break;
    case 3:
        if (!bitmap3.loadFromFile(filename)) {
            std::cerr << "Failed to load texture from " << filename << std::endl;
            return false;
        }
        texture3.loadFromImage(bitmap3);
        break;
    case 4:
        if (!bitmap4.loadFromFile(filename)) {
            std::cerr << "Failed to load texture from " << filename << std::endl;
            return false;
        }
        texture4.loadFromImage(bitmap4);
        break;
    case 5:
        if (!bitmap5.loadFromFile(filename)) {
            std::cerr << "Failed to load texture from " << filename << std::endl;
            return false;
        }
        texture5.loadFromImage(bitmap5);
        break;
    case 6:
        if (!bitmap6.loadFromFile(filename)) {
            std::cerr << "Failed to load texture from " << filename << std::endl;
            return false;
        }
        texture6.loadFromImage(bitmap6);
        break;
    case 7:
        if (!bitmap7.loadFromFile(filename)) {
            std::cerr << "Failed to load texture from " << filename << std::endl;
            return false;
        }
        texture7.loadFromImage(bitmap7);
        break;
    case 8:
        if (!bitmap8.loadFromFile(filename)) {
            std::cerr << "Failed to load texture from " << filename << std::endl;
            return false;
        }
        texture8.loadFromImage(bitmap8);
        break;
    case 9:
        if (!bitmap9.loadFromFile(filename)) {
            std::cerr << "Failed to load texture from " << filename << std::endl;
            return false;
        }
        texture9.loadFromImage(bitmap9);
        break;
    case 10:
        if (!bitmap10.loadFromFile(filename)) {
            std::cerr << "Failed to load texture from " << filename << std::endl;
            return false;
        }
        texture10.loadFromImage(bitmap10);
        break;
    case 11:
        if (!bitmap11.loadFromFile(filename)) {
            std::cerr << "Failed to load texture from " << filename << std::endl;
            return false;
        }
        texture11.loadFromImage(bitmap11);
        break;
    case 12:
        if (!bitmap12.loadFromFile(filename)) {
            std::cerr << "Failed to load texture from " << filename << std::endl;
            return false;
        }
        texture12.loadFromImage(bitmap12);
        break;
    case 13:
        if (!bitmap13.loadFromFile(filename)) {
            std::cerr << "Failed to load texture from " << filename << std::endl;
            return false;
        }
        texture13.loadFromImage(bitmap13);
        break;
    case 14:
        if (!bitmap14.loadFromFile(filename)) {
            std::cerr << "Failed to load texture from " << filename << std::endl;
            return false;
        }
        texture14.loadFromImage(bitmap14);
        break;
    case 15:
        if (!bitmap15.loadFromFile(filename)) {
            std::cerr << "Failed to load texture from " << filename << std::endl;
            return false;
        }
        texture15.loadFromImage(bitmap15);
        break;
    case 16:
        if (!bitmap16.loadFromFile(filename)) {
            std::cerr << "Failed to load texture from " << filename << std::endl;
            return false;
        }
        texture16.loadFromImage(bitmap16);
        break;
    default:
        std::cerr << "Invalid bitmap index: " << bitmapIndex << std::endl;
        return false;
    }
    return true;
}

const sf::Texture& BitmapHandler::getTexture(int bitmapIndex) {
    // Sprawdzenie, który index i zwrócenie odpowiedniej tekstury
    switch (bitmapIndex) {
    case 1: return texture1;
    case 2: return texture2;
    case 3: return texture3;
    case 4: return texture4;
    case 5: return texture5;
    case 6: return texture6;
    case 7: return texture7;
    case 8: return texture8;
    case 9: return texture9;
    case 10: return texture10;
    case 11: return texture11;
    case 12: return texture12;
    case 13: return texture13;
    case 14: return texture14;
    case 15: return texture15;
    case 16: return texture16;
    default:
        std::cerr << "Invalid bitmap index: " << bitmapIndex << std::endl;
        throw std::invalid_argument("Invalid bitmap index");
    }
}
