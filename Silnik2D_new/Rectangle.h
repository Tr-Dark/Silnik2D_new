/*
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <SFML/Graphics.hpp>
#include "ShapeObject.h"
#include "Point2D.h"

class Rectangle : public ShapeObject {
private:
    Point2D topLeft;  // Lewy g�rny r�g prostok�ta
    float width, height;  // Szeroko�� i wysoko�� prostok�ta

public:
    // Konstruktor
    Rectangle(Point2D topLeft, float width, float height);

    // Metody wirtualne
    void draw(sf::RenderWindow& window) override;
    void translate(float dx, float dy) override;
    void rotate(float angle) override;
    void scale(float factor) override;
};

#endif // RECTANGLE_H
*/

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <SFML/Graphics.hpp>
#include "ShapeObject.h"
#include "Point2D.h"

class Rectangle : public ShapeObject {
private:
    Point2D topLeft;
    float width, height;
    sf::RectangleShape rectShape;  // Obiekt SFML dla prostok�ta

public:
    Rectangle(Point2D topLeft, float width, float height);
    void setTexture(const sf::Texture& texture); // Ustawienie tekstury
    virtual void draw(sf::RenderWindow& window) override;
    void translate(float dx, float dy) override;
    void rotate(float angle) override;
    void scale(float factor) override;
    void updateSize(float newWidth, float newHeight); // Zmiana rozmiaru prostok�ta
};

#endif // RECTANGLE_H




