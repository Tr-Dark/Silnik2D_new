
#ifndef SHAPE_OBJECT_H
#define SHAPE_OBJECT_H

class ShapeObject {
public:
    virtual void draw(sf::RenderWindow& window) = 0; // Czysta funkcja wirtualna
    virtual void translate(float dx, float dy) = 0;
    virtual void rotate(float angle) = 0;
    virtual void scale(float factor) = 0;
    virtual ~ShapeObject() {} // Destruktor wirtualny
};


#endif // SHAPE_OBJECT_H
