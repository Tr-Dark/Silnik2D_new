#ifndef BITMAP_OBJECT_H
#define BITMAP_OBJECT_H

#include <SFML/Graphics.hpp>
#include "DrawableObject.h"
#include "TransformableObject.h"
#include <vector>

class BitmapObject : public DrawableObject, public TransformableObject {
public:
    BitmapObject();

    // Метод для завантаження текстур із файлів
    bool addTexture(const sf::Texture& texture);

    // Метод для вибору активної текстури
    void setTexture(int index);

    // Реалізація методу draw з DrawableObject
    void draw(sf::RenderWindow& window, PrimitiveRenderer& renderer) override;

protected:
    sf::Sprite sprite;                       // Спрайт для відображення текстури
    std::vector<sf::Texture> textures;       // Колекція текстур

private:
    int currentTextureIndex;                 // Поточний індекс активної текстури
};

#endif // BITMAP_OBJECT_H
