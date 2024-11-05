#include "BitmapHandler.h"
#include <iostream>
#include "Rectangle.h"


BitmapHandler::BitmapHandler() = default;

bool BitmapHandler::loadFromFile(const std::string& filename, int bitmapIndex) {
    if (bitmapIndex == 1) {
        if (!bitmap1.loadFromFile(filename)) {
            return false;
        }
        texture1.loadFromImage(bitmap1); 
    }
    else if (bitmapIndex == 2) {
        if (!bitmap2.loadFromFile(filename)) {
            return false;
        }
        texture2.loadFromImage(bitmap2); 
    }
    else if (bitmapIndex == 3) {
        if (!bitmap3.loadFromFile(filename)) {
            return false;
        }
        texture3.loadFromImage(bitmap3);
    }
    
    else if (bitmapIndex == 4) {
        if (!bitmap4.loadFromFile(filename)) { 
            return false;
        }
        texture4.loadFromImage(bitmap4);
    }
    else if (bitmapIndex == 5) {
        if (!bitmap5.loadFromFile(filename)) { 
            return false;
        }
        texture5.loadFromImage(bitmap5); 
    }
    else if (bitmapIndex == 6) {
        if (!bitmap6.loadFromFile(filename)) { // Używaj bitmap3, a nie bitmap2
            return false;
        }
        texture6.loadFromImage(bitmap6); // Ładowanie tekstury z obrazu
    }
    else if (bitmapIndex == 7) {
        if (!bitmap7.loadFromFile(filename)) { // Używaj bitmap3, a nie bitmap2
            return false;
        }
        texture7.loadFromImage(bitmap7); // Ładowanie tekstury z obrazu
    }
    else if (bitmapIndex == 8) {
        if (!bitmap8.loadFromFile(filename)) { // Używaj bitmap3, a nie bitmap2
            return false;
        }
        texture8.loadFromImage(bitmap8); // Ładowanie tekstury z obrazu
    }
    else if (bitmapIndex == 9) {
        if (!bitmap9.loadFromFile(filename)) { // Używaj bitmap3, a nie bitmap2
            return false;
        }
        texture9.loadFromImage(bitmap9); // Ładowanie tekstury z obrazu
    }
    else if (bitmapIndex == 10) {
        if (!bitmap10.loadFromFile(filename)) { // Używaj bitmap3, a nie bitmap2
            return false;
        }
        texture10.loadFromImage(bitmap10); // Ładowanie tekstury z obrazu
    }
    else if (bitmapIndex == 11) {
        if (!bitmap11.loadFromFile(filename)) { // Używaj bitmap3, a nie bitmap2
            return false;
        }
        texture11.loadFromImage(bitmap11); // Ładowanie tekstury z obrazu
    }
    else if (bitmapIndex == 12) {
        if (!bitmap12.loadFromFile(filename)) { // Używaj bitmap3, a nie bitmap2
            return false;
        }
        texture12.loadFromImage(bitmap12); // Ładowanie tekstury z obrazu
    }
    else if (bitmapIndex == 13) {
        if (!bitmap13.loadFromFile(filename)) { // Używaj bitmap3, a nie bitmap2
            return false;
        }
        texture13.loadFromImage(bitmap13); // Ładowanie tekstury z obrazu
    }
    else if (bitmapIndex == 14) {
        if (!bitmap14.loadFromFile(filename)) { // Używaj bitmap3, a nie bitmap2
            return false;
        }
        texture14.loadFromImage(bitmap14); // Ładowanie tekstury z obrazu
    }
    else if (bitmapIndex == 15) {
        if (!bitmap15.loadFromFile(filename)) { // Używaj bitmap3, a nie bitmap2
            return false;
        }
        texture15.loadFromImage(bitmap15); // Ładowanie tekstury z obrazu
    }
    else if (bitmapIndex == 16) {
        if (!bitmap16.loadFromFile(filename)) { // Używaj bitmap3, a nie bitmap2
            return false;
        }
        texture16.loadFromImage(bitmap16); // Ładowanie tekstury z obrazu
    }
    return true;
}

const sf::Texture& BitmapHandler::getTexture(int bitmapIndex) {
    if (bitmapIndex == 1) {
        return texture1; // Zwróć teksturę dla bitmapy 1
    }
    else if (bitmapIndex == 2) {
        return texture2; // Zwróć teksturę dla bitmapy 2
    }
    else if (bitmapIndex == 3) {
        return texture3; // Zwróć teksturę dla bitmapy 3
    }
    else if (bitmapIndex == 4) {
        return texture4; // Zwróć teksturę dla bitmapy 3
    }
    else if (bitmapIndex == 5) {
        return texture5; // Zwróć teksturę dla bitmapy 3
    }
    else if (bitmapIndex == 6) {
        return texture6; // Zwróć teksturę dla bitmapy 3
    }
    else if (bitmapIndex == 7) {
        return texture7; // Zwróć teksturę dla bitmapy 3
    }
    else if (bitmapIndex == 8) {
        return texture8; // Zwróć teksturę dla bitmapy 3
    }
    else if (bitmapIndex == 9) {
        return texture9; // Zwróć teksturę dla bitmapy 3
    }
    else if (bitmapIndex == 10) {
        return texture10; // Zwróć teksturę dla bitmapy 3
    }
    else if (bitmapIndex == 11) {
        return texture11; // Zwróć teksturę dla bitmapy 3
    }
    else if (bitmapIndex == 12) {
        return texture12; // Zwróć teksturę dla bitmapy 3
    }
    else if (bitmapIndex == 13) {
        return texture13; // Zwróć teksturę dla bitmapy 3
    }
    else if (bitmapIndex == 14) {
        return texture14; // Zwróć teksturę dla bitmapy 3
    }
    else if (bitmapIndex == 15) {
        return texture15; // Zwróć teksturę dla bitmapy 3
    }
    else if (bitmapIndex == 16) {
        return texture16; // Zwróć teksturę dla bitmapy 3
    }
    // Można rzucić wyjątek lub zwrócić domyślną teksturę
    throw std::invalid_argument("Invalid bitmap index"); 
}
