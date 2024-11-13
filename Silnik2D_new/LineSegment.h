#ifndef LINE_SEGMENT_H
#define LINE_SEGMENT_H

#include "Point2D.h"
#include <SFML/Graphics.hpp>
#include "PrimitiveRenderer.h"

class LineSegment {
private:
   Point2D start; // Pocz�tkowy punkt odcinka
   Point2D end;   // Ko�cowy punkt odcinka

public:
    // Konstruktor inicjalizuj�cy pocz�tek i koniec odcinka
    LineSegment(const Point2D& start, const Point2D& end);
   
    // Metody dost�pu do punkt�w pocz�tkowego i ko�cowego
    Point2D getStart() const;
    Point2D getEnd() const;

    // Metody ustawiaj�ce nowe warto�ci dla punkt�w
    void setStart(const Point2D& point);
    void setEnd(const Point2D& point);

    // Metoda do rysowania odcinka
    void draw(sf::RenderWindow& window, PrimitiveRenderer& renderer, sf::Color color = sf::Color::White, bool incremental = true) const;

};

#endif // LINE_SEGMENT_H
