#include "BitmapHandler.h"
#include <iostream>
#include "Rectangle.h"
#include "Engine.h"

BitmapHandler::BitmapHandler(){
    //std::cout << "BitmapHandler constructor\n";
};

bool BitmapHandler::loadFromFile(const std::string& filename, int bitmapIndex) {
    // Sprawdzanie i ładowanie tekstury w zależności od indeksu
    switch (bitmapIndex) {
    case 1:
        if (!bitmap1.loadFromFile(filename)) {
            std::cerr << "Failed to load texture from " << filename << std::endl;
            return false;
        }
        else std::cout << "texture1 loaded";
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
    case 1: std::cout << "bmp.getTexture " << bitmapIndex << '\n'; return texture1;
    case 2: std::cout << "bmp.getTexture " << bitmapIndex << '\n'; return texture2;
    case 3: std::cout << "bmp.getTexture " << bitmapIndex << '\n'; return texture3;
    case 4: std::cout << "bmp.getTexture " << bitmapIndex << '\n'; return texture4;
    case 5: std::cout << "bmp.getTexture " << bitmapIndex << '\n'; return texture5;
    case 6: std::cout << "bmp.getTexture " << bitmapIndex << '\n'; return texture6;
    case 7: std::cout << "bmp.getTexture " << bitmapIndex << '\n'; return texture7;
    case 8: std::cout << "bmp.getTexture " << bitmapIndex << '\n'; return texture8;
    case 9: std::cout << "bmp.getTexture " << bitmapIndex << '\n'; return texture9;
    case 10: std::cout << "bmp.getTexture " << bitmapIndex << '\n'; return texture10;
    case 11: std::cout << "bmp.getTexture " << bitmapIndex << '\n'; return texture11;
    case 12: std::cout << "bmp.getTexture " << bitmapIndex << '\n'; return texture12;
    case 13: std::cout << "bmp.getTexture " << bitmapIndex << '\n'; return texture13;
    case 14: std::cout << "bmp.getTexture " << bitmapIndex << '\n'; return texture14;
    case 15: std::cout << "bmp.getTexture " << bitmapIndex << '\n'; return texture15;
    case 16: std::cout << "bmp.getTexture " << bitmapIndex << '\n'; return texture16;
    default:
        std::cerr << "Invalid bitmap index: " << bitmapIndex << std::endl;
        throw std::invalid_argument("Invalid bitmap index");
    }
}
BitmapHandler::~BitmapHandler(){
    /*bitmap1.~Image();
    bitmap2.~Image();
    bitmap3.~Image();
    bitmap4.~Image();
    bitmap5.~Image();
    bitmap6.~Image();
    bitmap7.~Image();
    bitmap8.~Image();
    bitmap9.~Image();
    bitmap10.~Image();
    bitmap11.~Image();
    bitmap12.~Image();
    bitmap13.~Image();
    bitmap14.~Image();
    bitmap15.~Image();
    bitmap16.~Image();
    texture1.~Texture();
    texture2.~Texture();
    texture3.~Texture();
    texture4.~Texture();
    texture5.~Texture();
    texture6.~Texture();
    texture7.~Texture();
    texture8.~Texture();
    texture9.~Texture();
    texture10.~Texture();
    texture11.~Texture();
    texture12.~Texture();
    texture13.~Texture();
    texture14.~Texture();
    texture15.~Texture();
    texture16.~Texture();*/
    std::cout << "BitmapHandler: textures & images deleted...\n";
}