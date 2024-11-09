
#ifndef PRIMITIVERENDERER_H
#define PRIMITIVERENDERER_H

#include <SFML/Graphics.hpp>
#include "Point2D.h"
#include <vector>

class PrimitiveRenderer {
public:
    //NOWA METODA
    void drawLineBresenham(sf::RenderWindow& window, const Point2D& p1, const Point2D& p2, sf::Color color = sf::Color::Red) const;
    void drawLineIncremental(sf::RenderWindow& window, const Point2D& p1, const Point2D& p2, sf::Color color) const;
    void drawCircle(sf::RenderWindow& window, const Point2D& center, float radius, sf::Color color) const;
    //void drawLine(sf::RenderWindow& window, const Point2D& p1, const Point2D& p2, sf::Color color = sf::Color::Red);
   // void drawCircle(sf::RenderWindow& window, const Point2D& center, float radius, sf::Color color = sf::Color::White);
   // void drawLineIncremental(sf::RenderWindow& window, const Point2D& p1, const Point2D& p2, sf::Color color = sf::Color::Red);

};

#endif // PRIMITIVERENDERER_H