#include "Tools.h"

bool Tools::CheckMove(std::vector<Point2D> figure, float dx, float dy, float windowWidth, float windowHeight)
{
    bool canMove = true;
    for (const Point2D& point : figure) {
        if (!point.isWithinBounds(dx, dy, windowWidth, windowHeight)) {
            canMove = false; // Вершина виходить за межі
            break;
        }
    }

    return canMove;
}

float Tools::getRandomOffset()
{
    // Ініціалізуємо генератор випадкових чисел (тільки один раз на програму)
    static bool initialized = false;
    if (!initialized) {
        std::srand(static_cast<unsigned>(std::time(nullptr)));
        initialized = true;
    }

    // Генеруємо випадкове число від 0 до 10
    return static_cast<float>(std::rand() % 11 - 5); // % 11, оскільки межа 10 включно
}
