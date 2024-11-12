#ifndef TRANSFORMABLE_OBJECT_H
#define TRANSFORMABLE_OBJECT_H

#include "GameObject.h"

class TransformableObject : public virtual GameObject {
public:
    virtual void translate(float dx, float dy) = 0;

    virtual void rotate(float angle) = 0;

    virtual void scale(float factorX, float factorY) = 0;

    virtual ~TransformableObject() {}
};

#endif // TRANSFORMABLE_OBJECT_H
