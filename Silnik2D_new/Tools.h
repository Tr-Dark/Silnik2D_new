#ifndef TOOLS_H
#define TOOLS_H

#include <SFML/Graphics.hpp>
#include "Point2D.h"

/**
 * @class Tools
 * @brief Klasa narzêdziowa zawieraj¹ca statyczne metody pomocnicze.
 *
 * Klasa ta oferuje ró¿ne funkcje pomocnicze, takie jak sprawdzanie, czy ruch figury mieœci siê w granicach okna,
 * oraz generowanie losowych wartoœci przesuniêcia. Jest to klasa statyczna, co oznacza, ¿e jej metody nie wymagaj¹
 * tworzenia obiektu.
 */
static class Tools {
public:
    /**
     * @brief Sprawdza, czy ruch figury (przemieszczenie o dx, dy) jest mo¿liwy w obrêbie okna.
     *
     * Metoda ta analizuje, czy po dokonaniu ruchu figura nadal mieœci siê w obrêbie okna
     * o okreœlonej szerokoœci i wysokoœci.
     *
     * @param figure Wektor punktów reprezentuj¹cych figurê.
     * @param dx Przemieszczenie w osi X.
     * @param dy Przemieszczenie w osi Y.
     * @param windowWidth Szerokoœæ okna.
     * @param windowHeight Wysokoœæ okna.
     * @return `true`, jeœli figura po przemieszczeniu mieœci siê w oknie, `false` w przeciwnym przypadku.
     */
    static bool CheckMove(std::vector<Point2D> figure, float dx, float dy, float windowWidth, float windowHeight);

    /**
     * @brief Generuje losowe przesuniêcie.
     *
     * Metoda ta zwraca losow¹ wartoœæ przesuniêcia, która mo¿e byæ u¿yta do zmiany pozycji obiektów w grze.
     *
     * @return Losowa wartoœæ typu `float`.
     */
    static float getRandomOffset();

    /**
     * @brief Skaluje wielok¹t.
     *
     * @param polygon Wektor punktów definiuj¹cych wielok¹t.
     * @param scaleX Skala w osi X.
     * @param scaleY Skala w osi Y.
     */
    static void scalePolygon(std::vector<Point2D>& polygon, float scaleX, float scaleY);
};

#endif //TOOLS_H
