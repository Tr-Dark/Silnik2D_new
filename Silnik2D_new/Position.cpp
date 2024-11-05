
/*
// Position.cpp
#include "Position.h"
#include <iostream>

Position::Position(const std::string& fontPath) {
    if (!font.loadFromFile(fontPath)) {
        std::cerr << "Could not load font from " << fontPath << std::endl;
    }
    infoText.setFont(font);
    infoText.setCharacterSize(20);
    infoText.setFillColor(sf::Color::White);
}

void Position::updateCursorPosition(int x, int y) {
    cursorInfo = "Pozycja kursora: X = " + std::to_string(x) +
        ", Y = " + std::to_string(y);
    infoText.setString(cursorInfo + "\n" + clickInfo);
}

void Position::updateClickPosition(int x, int y) {
    clickInfo = "Klikniecie: X = " + std::to_string(x) +
        ", Y = " + std::to_string(y);
    infoText.setString(cursorInfo + "\n" + clickInfo);
}

void Position::draw(sf::RenderWindow& window) {
    window.draw(infoText);
}
*/

#include "Position.h"
#include <iostream>

Position::Position(const std::string& fontPath) {
    if (!font.loadFromFile(fontPath)) {
        std::cerr << "Could not load font from " << fontPath << std::endl;
    }
    infoText.setFont(font);
    infoText.setCharacterSize(20);
    infoText.setFillColor(sf::Color::White);
}

void Position::updateCursorPosition(int x, int y) {
    cursorInfo = "Pozycja kursora: X = " + std::to_string(x) +
        ", Y = " + std::to_string(y);
    infoText.setString(cursorInfo + "\n" + clickInfo + "\n" + drawingLineInfo);
}

void Position::updateClickPosition(int x, int y) {
    clickInfo = "Klikniecie: X = " + std::to_string(x) +
        ", Y = " + std::to_string(y);
    infoText.setString(cursorInfo + "\n" + clickInfo + "\n" + drawingLineInfo);
}

// Nowa metoda do ustawiania informacji o rysowaniu linii
void Position::setDrawingLineInfo(const std::string& info) {
    drawingLineInfo = info;
    infoText.setString(cursorInfo + "\n" + clickInfo + "\n" + drawingLineInfo);
}

void Position::draw(sf::RenderWindow& window) {
    window.draw(infoText);
}
