#ifndef ANIMATED_OBJECT_H
#define ANIMATED_OBJECT_H

class AnimatedObject {
public:
    virtual ~AnimatedObject() = default;

    // Абстрактний метод для анімації
    virtual void animate() = 0;
};

#endif // ANIMATED_OBJECT_H
