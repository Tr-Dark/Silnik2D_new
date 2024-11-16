#ifndef PRIMITIVE_RENDERER_H
#define PRIMITIVE_RENDERER_H

#include <SFML/Graphics.hpp>
#include <vector>

class LineSegment;
class Point2D;

/**
 * @class PrimitiveRenderer
 * @brief Klasa do rysowania prymityw�w graficznych w oknie SFML.
 *
 * Oferuje zestaw metod do rysowania linii, wielok�t�w, okr�g�w i elips,
 * zar�wno wype�nionych, jak i nie.
 */
class PrimitiveRenderer {
public:
    /**
     * @brief Konstruktor klasy PrimitiveRenderer.
     */
    PrimitiveRenderer();

    /**
     * @brief Rysuje lini� metod� przyrostow�.
     *
     * @param window Obiekt do rysowania (np. sf::RenderTarget).
     * @param p1 Punkt pocz�tkowy linii.
     * @param p2 Punkt ko�cowy linii.
     * @param color Kolor linii.
     */
    void drawLineIncremental(sf::RenderTarget& window, const Point2D& p1, const Point2D& p2, sf::Color color);

    /**
     * @brief Rysuje wielolini� (polyline).
     *
     * @param window Obiekt do rysowania (np. sf::RenderWindow).
     * @param points Wektor punkt�w definiuj�cych wielolini�.
     * @param color Kolor wielolinii.
     * @param closed Okre�la, czy wielolinia jest zamkni�ta (domy�lnie false).
     */
    void drawPolyline(sf::RenderWindow& window, const std::vector<Point2D>& points, sf::Color color, bool closed = false);

    /**
     * @brief Rysuje lini� za pomoc� algorytmu podstawowego.
     *
     * @param window Obiekt do rysowania (np. sf::RenderWindow).
     * @param p1 Punkt pocz�tkowy linii.
     * @param p2 Punkt ko�cowy linii.
     * @param color Kolor linii.
     */
    void drawLineBasic(sf::RenderWindow& window, const Point2D& p1, const Point2D& p2, sf::Color color);

    /**
     * @brief Rysuje okr�g.
     *
     * @param window Obiekt do rysowania (np. sf::RenderWindow).
     * @param center �rodek okr�gu.
     * @param radius Promie� okr�gu.
     * @param color Kolor okr�gu.
     */
    void drawCircle(sf::RenderWindow& window, const Point2D& center, int radius, sf::Color color);

    /**
     * @brief Rysuje elips�.
     *
     * @param window Obiekt do rysowania (np. sf::RenderWindow).
     * @param center �rodek elipsy.
     * @param radiusX Promie� w osi X.
     * @param radiusY Promie� w osi Y.
     * @param color Kolor elipsy.
     */
    void drawEllipse(sf::RenderWindow& window, const Point2D& center, int radiusX, int radiusY, sf::Color color);

    /**
     * @brief Rysuje wielok�t.
     *
     * @param window Obiekt do rysowania (np. sf::RenderWindow).
     * @param points Wektor punkt�w definiuj�cych wielok�t.
     * @param color Kolor wielok�ta.
     * @param closed Okre�la, czy wielok�t jest zamkni�ty (domy�lnie true).
     * @return true, je�li wielok�t zosta� narysowany; false w przypadku b��du.
     */
    bool drawPolygon(sf::RenderWindow& window, const std::vector<Point2D>& points, sf::Color color, bool closed = true);

    /**
     * @brief Rysuje wype�niony okr�g.
     *
     * @param window Obiekt do rysowania (np. sf::RenderWindow).
     * @param center �rodek okr�gu.
     * @param radius Promie� okr�gu.
     * @param color Kolor wype�nienia.
     */
    void drawFilledCircle(sf::RenderWindow& window, const Point2D& center, int radius, sf::Color color);

    /**
     * @brief Wype�nianie obszaru metod� kraw�dziow� (border fill).
     *
     * @param renderTexture Tekstura do renderowania.
     * @param startX Pozycja pocz�tkowa w osi X.
     * @param startY Pozycja pocz�tkowa w osi Y.
     * @param fillColor Kolor wype�nienia.
     * @param boundaryColor Kolor kraw�dzi.
     */
    void borderFill(sf::RenderTexture& renderTexture, int startX, int startY, sf::Color fillColor, sf::Color boundaryColor);

    /**
     * @brief Wype�nianie obszaru metod� zalewania (flood fill).
     *
     * @param renderTexture Tekstura do renderowania.
     * @param startX Pozycja pocz�tkowa w osi X.
     * @param startY Pozycja pocz�tkowa w osi Y.
     * @param fillColor Kolor wype�nienia.
     * @param oldColor Kolor pocz�tkowy obszaru do wype�nienia.
     */
    void floodFill(sf::RenderTexture& renderTexture, int startX, int startY, sf::Color fillColor, sf::Color oldColor);

    /**
     * @brief Rysuje wype�niony wielok�t.
     *
     * @param window Obiekt do rysowania (np. sf::RenderWindow).
     * @param points Wektor punkt�w definiuj�cych wielok�t.
     * @param fillColor Kolor wype�nienia.
     */
    void drawFilledPolygon(sf::RenderWindow& window, const std::vector<Point2D>& points, sf::Color fillColor);

    /**
     * @brief Rysuje wielok�t z wype�nieniem i obrysem.
     *
     * @param window Obiekt do rysowania (np. sf::RenderWindow).
     * @param points Wektor punkt�w definiuj�cych wielok�t.
     * @param fillColor Kolor wype�nienia.
     */
    void drawBorderFilledPolygon(sf::RenderWindow& window, const std::vector<Point2D>& points, sf::Color fillColor);

    /**
     * @brief Rysuje wielok�t wype�niony metod� zalewania (flood fill).
     *
     * @param window Obiekt do rysowania (np. sf::RenderWindow).
     * @param points Wektor punkt�w definiuj�cych wielok�t.
     * @param fillColor Kolor wype�nienia.
     */
    void drawFloodFilledPolygon(sf::RenderWindow& window, const std::vector<Point2D>& points, sf::Color fillColor);

    /**
     * @brief Skaluje wielok�t.
     *
     * @param polygon Wektor punkt�w definiuj�cych wielok�t.
     * @param scaleX Skala w osi X.
     * @param scaleY Skala w osi Y.
     */
    static void scalePolygon(std::vector<Point2D>& polygon, float scaleX, float scaleY);

private:
    /**
     * @brief Sprawdza, czy istniej� przeci�cia mi�dzy segmentami.
     *
     * @param segments Wektor segment�w do sprawdzenia.
     * @return true, je�li istniej� przeci�cia; false w przeciwnym razie.
     */
    bool checkForIntersections(const std::vector<LineSegment>& segments);

    /**
     * @brief Sprawdza, czy dwa odcinki przecinaj� si�.
     *
     * @param p1 Punkt pocz�tkowy pierwszego odcinka.
     * @param q1 Punkt ko�cowy pierwszego odcinka.
     * @param p2 Punkt pocz�tkowy drugiego odcinka.
     * @param q2 Punkt ko�cowy drugiego odcinka.
     * @return true, je�li odcinki przecinaj� si�; false w przeciwnym razie.
     */
    bool doIntersect(const Point2D& p1, const Point2D& q1, const Point2D& p2, const Point2D& q2);
};

#endif // PRIMITIVE_RENDERER_H
