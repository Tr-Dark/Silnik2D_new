#include "Tools.h"
#include <iostream>

/**
 * @brief Sprawdza, czy ruch figury o zadany wektor przesunięcia jest możliwy w obrębie okna.
 * @param figure Wektor punktów reprezentujących figurę, którą próbujemy przesunąć.
 * @param dx Przesunięcie figury wzdłuż osi X.
 * @param dy Przesunięcie figury wzdłuż osi Y.
 * @param windowWidth Szerokość okna, w którym figura ma pozostać.
 * @param windowHeight Wysokość okna, w którym figura ma pozostać.
 * @return `true` jeśli figura może zostać przesunięta, w przeciwnym razie `false`.
 */
bool Tools::CheckMove(std::vector<Point2D> figure, float dx, float dy, float windowWidth, float windowHeight)
{
    bool canMove = true;
    for (const Point2D& point : figure) {
        // Sprawdzamy, czy każdy punkt figury mieści się w granicach okna po przesunięciu
        if (!point.isWithinBounds(dx, dy, windowWidth, windowHeight)) {
            canMove = false;
            break;
        }
    }

    return canMove;
}

/**
 * @brief Generuje losowe przesunięcie w zakresie od -5 do 5.
 * Funkcja zwraca losową wartość w tym przedziale, którą można wykorzystać do modyfikacji położenia obiektów.
 * @return Losowa wartość typu float w przedziale [-5, 5].
 */
float Tools::getRandomOffset()
{
    static bool initialized = false;
    if (!initialized) {
        // Inicjalizacja generatora liczb losowych tylko raz
        std::srand(static_cast<unsigned>(std::time(nullptr)));
        initialized = true;
    }

    // Zwracamy losową liczbę z zakresu [-5, 5]
    return static_cast<float>(std::rand() % 11 - 5);
}


/**
 * @brief Skalowanie wielokąta względem jego środka.
 *
 * Funkcja przekształca punkty wielokąta, skalując go względem jego geometrycznego środka.
 * Skalowanie odbywa się w kierunkach osi X i Y według współczynników `scaleX` i `scaleY`.
 *
 * @param polygon Wektor punktów reprezentujących wielokąt do skalowania.
 * @param scaleX Współczynnik skalowania w osi X.
 * @param scaleY Współczynnik skalowania w osi Y.
 *
 * @note Punkty wielokąta są modyfikowane bezpośrednio w przekazanym wektorze.
 * @note Wartości `scaleX` i `scaleY` mniejsze od 1 zmniejszają wielokąt, a większe od 1 powiększają go.
 */
void Tools::scalePolygon(std::vector<Point2D>& polygon, float scaleX, float scaleY) {

    float centerX = 0.0f;
    float centerY = 0.0f;

    for (const auto& point : polygon) {
        centerX += point.getX();
        centerY += point.getY();
    }
    centerX /= polygon.size();
    centerY /= polygon.size();


    for (auto& point : polygon) {
        float dx = point.getX() - centerX;
        float dy = point.getY() - centerY;

        point.setX(centerX + dx * scaleX);
        point.setY(centerY + dy * scaleY);
        std::cerr << "centerX: " << centerX + dx * scaleX << std::endl;
    }
}
