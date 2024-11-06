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
        if (!bitmap6.loadFromFile(filename)) { 
            return false;
        }
        texture6.loadFromImage(bitmap6); 
    }
    else if (bitmapIndex == 7) {
        if (!bitmap7.loadFromFile(filename)) { 
            return false;
        }
        texture7.loadFromImage(bitmap7); 
    }
    else if (bitmapIndex == 8) {
        if (!bitmap8.loadFromFile(filename)) { 
            return false;
        }
        texture8.loadFromImage(bitmap8); 
    }
    else if (bitmapIndex == 9) {
        if (!bitmap9.loadFromFile(filename)) { 
            return false;
        }
        texture9.loadFromImage(bitmap9); 
    }
    else if (bitmapIndex == 10) {
        if (!bitmap10.loadFromFile(filename)) { 
            return false;
        }
        texture10.loadFromImage(bitmap10); 
    }
    else if (bitmapIndex == 11) {
        if (!bitmap11.loadFromFile(filename)) { 
            return false;
        }
        texture11.loadFromImage(bitmap11); 
    }
    else if (bitmapIndex == 12) {
        if (!bitmap12.loadFromFile(filename)) { 
            return false;
        }
        texture12.loadFromImage(bitmap12); 
    }
    else if (bitmapIndex == 13) {
        if (!bitmap13.loadFromFile(filename)) { 
            return false;
        }
        texture13.loadFromImage(bitmap13); 
    }
    else if (bitmapIndex == 14) {
        if (!bitmap14.loadFromFile(filename)) { 
            return false;
        }
        texture14.loadFromImage(bitmap14); 
    }
    else if (bitmapIndex == 15) {
        if (!bitmap15.loadFromFile(filename)) { 
            return false;
        }
        texture15.loadFromImage(bitmap15); 
    }
    else if (bitmapIndex == 16) {
        if (!bitmap16.loadFromFile(filename)) { 
            return false;
        }
        texture16.loadFromImage(bitmap16);
    }
    return true;
}

const sf::Texture& BitmapHandler::getTexture(int bitmapIndex) {
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
        throw std::invalid_argument("Invalid bitmap index");
    }
}