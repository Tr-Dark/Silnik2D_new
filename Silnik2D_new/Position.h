#ifndef POSITION_H
#define POSITION_H

#include <SFML/Graphics.hpp>
#include <string>

class Position {
private:
    std::string cursorInfo;
    std::string clickInfo;
    std::string drawingLineInfo;  
    sf::Font font;
    sf::Text infoText;

public:
    Position(const std::string& fontPath);
    void updateCursorPosition(int x, int y);
    void updateClickPosition(int x, int y);
    void setDrawingLineInfo(const std::string& info); 
    void draw(sf::RenderWindow& window);
};

#endif // POSITION_H
