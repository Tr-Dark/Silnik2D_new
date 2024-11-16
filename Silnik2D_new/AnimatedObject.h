#ifndef ANIMATED_OBJECT_H
#define ANIMATED_OBJECT_H

/**
 * @class AnimatedObject
 * @brief Abstrakcyjna klasa bazowa dla obiektów animowanych.
 *
 * Ta klasa definiuje interfejs do obiektów, które posiadają animację.
 * Klasa jest przeznaczona do dziedziczenia przez inne klasy, które implementują
 * metodę animacji w zależności od swojego typu.
 */

class AnimatedObject {
public:
    /**
     * @brief Wirtualny destruktor klasy AnimatedObject.
     *
     * Destruktor wirtualny zapewnia poprawne usuwanie obiektów pochodnych
     * poprzez wskaźniki do klasy bazowej.
     */
    virtual ~AnimatedObject() = default;
    /**
    * @brief Czysto wirtualna funkcja do animacji obiektu.
    *
    * Każda klasa dziedzicząca po AnimatedObject musi zaimplementować tę metodę,
    * aby określić, jak animacja ma być wykonywana.
    */
    virtual void animate() = 0;
};

#endif // ANIMATED_OBJECT_H
