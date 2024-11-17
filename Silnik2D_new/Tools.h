#ifndef TOOLS_H
#define TOOLS_H

#include <SFML/Graphics.hpp>
#include "Point2D.h"

/**
 * @class Tools
 * @brief Klasa narz�dziowa zawieraj�ca statyczne metody pomocnicze.
 *
 * Klasa ta oferuje r�ne funkcje pomocnicze, takie jak sprawdzanie, czy ruch figury mie�ci si� w granicach okna,
 * oraz generowanie losowych warto�ci przesuni�cia. Jest to klasa statyczna, co oznacza, �e jej metody nie wymagaj�
 * tworzenia obiektu.
 */
static class Tools {
public:
    /**
     * @brief Sprawdza, czy ruch figury (przemieszczenie o dx, dy) jest mo�liwy w obr�bie okna.
     *
     * Metoda ta analizuje, czy po dokonaniu ruchu figura nadal mie�ci si� w obr�bie okna
     * o okre�lonej szeroko�ci i wysoko�ci.
     *
     * @param figure Wektor punkt�w reprezentuj�cych figur�.
     * @param dx Przemieszczenie w osi X.
     * @param dy Przemieszczenie w osi Y.
     * @param windowWidth Szeroko�� okna.
     * @param windowHeight Wysoko�� okna.
     * @return `true`, je�li figura po przemieszczeniu mie�ci si� w oknie, `false` w przeciwnym przypadku.
     */
    static bool CheckMove(std::vector<Point2D> figure, float dx, float dy, float windowWidth, float windowHeight);

    /**
     * @brief Generuje losowe przesuni�cie.
     *
     * Metoda ta zwraca losow� warto�� przesuni�cia, kt�ra mo�e by� u�yta do zmiany pozycji obiekt�w w grze.
     *
     * @return Losowa warto�� typu `float`.
     */
    static float getRandomOffset();

    /**
     * @brief Skaluje wielok�t.
     *
     * @param polygon Wektor punkt�w definiuj�cych wielok�t.
     * @param scaleX Skala w osi X.
     * @param scaleY Skala w osi Y.
     */
    static void scalePolygon(std::vector<Point2D>& polygon, float scaleX, float scaleY);
};

#endif //TOOLS_H
