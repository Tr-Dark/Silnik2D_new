#ifndef POINT2D_H
#define POINT2D_H

#include <SFML/Graphics.hpp>
#include "TransformableObject.h"
#include "PrimitiveRenderer.h"

    class Point2D : public TransformableObject {
    private:
        float x;
        float y;
        //sf::Vector2f origin;

    public:
        Point2D(float x = 0, float y = 0);

        float getX() const;
        float getY() const;

        void setX(float x);
        void setY(float y);

        // Реалізація методів TransformableObject
        void translate(float dx, float dy) override;
        void rotate(float angle) override;
        void scale(float factorX, float factorY) override;
        void update();

        void draw(sf::RenderWindow& window, PrimitiveRenderer& renderer, sf::Color color = sf::Color::White);
        bool isWithinBounds(float dx, float dy, float windowWidth, float windowHeight) const;
    };

#endif //POINT2D_H
