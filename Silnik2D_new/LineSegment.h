#ifndef LINE_SEGMENT_H
#define LINE_SEGMENT_H

#include "Point2D.h"
#include <SFML/Graphics.hpp>
#include "PrimitiveRenderer.h"

class LineSegment {
private:
   Point2D start; // Pocz¹tkowy punkt odcinka
   Point2D end;   // Koñcowy punkt odcinka

public:
    // Konstruktor inicjalizuj¹cy pocz¹tek i koniec odcinka
    LineSegment(const Point2D& start, const Point2D& end);
   
    // Metody dostêpu do punktów pocz¹tkowego i koñcowego
    Point2D getStart() const;
    Point2D getEnd() const;

    // Metody ustawiaj¹ce nowe wartoœci dla punktów
    void setStart(const Point2D& point);
    void setEnd(const Point2D& point);

    // Metoda do rysowania odcinka
    void draw(sf::RenderWindow& window, PrimitiveRenderer& renderer, sf::Color color = sf::Color::White, bool incremental = true) const;

};

#endif // LINE_SEGMENT_H
