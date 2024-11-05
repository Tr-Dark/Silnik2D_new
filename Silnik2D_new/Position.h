#ifndef POSITION_H
#define POSITION_H

#include <SFML/Graphics.hpp>
#include <string>

class Position {
private:
    std::string cursorInfo;
    std::string clickInfo;
    std::string drawingLineInfo;  // Dodana informacja o rysowaniu linii
    sf::Font font;
    sf::Text infoText;

public:
    Position(const std::string& fontPath);
    void updateCursorPosition(int x, int y);
    void updateClickPosition(int x, int y);
    void setDrawingLineInfo(const std::string& info);  // Nowa metoda do ustawiania informacji o rysowaniu linii
    void draw(sf::RenderWindow& window);
};

#endif // POSITION_H
