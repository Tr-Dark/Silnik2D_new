#ifndef PRIMITIVE_RENDERER_H
#define PRIMITIVE_RENDERER_H

#include <SFML/Graphics.hpp>
#include <vector>

class LineSegment;
class Point2D;

/**
 * @class PrimitiveRenderer
 * @brief Klasa do rysowania prymitywów graficznych w oknie SFML.
 *
 * Oferuje zestaw metod do rysowania linii, wielok¹tów, okrêgów i elips,
 * zarówno wype³nionych, jak i nie.
 */
class PrimitiveRenderer {
public:
    /**
     * @brief Konstruktor klasy PrimitiveRenderer.
     */
    PrimitiveRenderer();

    /**
     * @brief Rysuje liniê metod¹ przyrostow¹.
     *
     * @param window Obiekt do rysowania (np. sf::RenderTarget).
     * @param p1 Punkt pocz¹tkowy linii.
     * @param p2 Punkt koñcowy linii.
     * @param color Kolor linii.
     */
    void drawLineIncremental(sf::RenderTarget& window, const Point2D& p1, const Point2D& p2, sf::Color color);

    /**
     * @brief Rysuje wieloliniê (polyline).
     *
     * @param window Obiekt do rysowania (np. sf::RenderWindow).
     * @param points Wektor punktów definiuj¹cych wieloliniê.
     * @param color Kolor wielolinii.
     * @param closed Okreœla, czy wielolinia jest zamkniêta (domyœlnie false).
     */
    void drawPolyline(sf::RenderWindow& window, const std::vector<Point2D>& points, sf::Color color, bool closed = false);

    /**
     * @brief Rysuje liniê za pomoc¹ algorytmu podstawowego.
     *
     * @param window Obiekt do rysowania (np. sf::RenderWindow).
     * @param p1 Punkt pocz¹tkowy linii.
     * @param p2 Punkt koñcowy linii.
     * @param color Kolor linii.
     */
    void drawLineBasic(sf::RenderWindow& window, const Point2D& p1, const Point2D& p2, sf::Color color);

    /**
     * @brief Rysuje okr¹g.
     *
     * @param window Obiekt do rysowania (np. sf::RenderWindow).
     * @param center Œrodek okrêgu.
     * @param radius Promieñ okrêgu.
     * @param color Kolor okrêgu.
     */
    void drawCircle(sf::RenderWindow& window, const Point2D& center, int radius, sf::Color color);

    /**
     * @brief Rysuje elipsê.
     *
     * @param window Obiekt do rysowania (np. sf::RenderWindow).
     * @param center Œrodek elipsy.
     * @param radiusX Promieñ w osi X.
     * @param radiusY Promieñ w osi Y.
     * @param color Kolor elipsy.
     */
    void drawEllipse(sf::RenderWindow& window, const Point2D& center, int radiusX, int radiusY, sf::Color color);

    /**
     * @brief Rysuje wielok¹t.
     *
     * @param window Obiekt do rysowania (np. sf::RenderWindow).
     * @param points Wektor punktów definiuj¹cych wielok¹t.
     * @param color Kolor wielok¹ta.
     * @param closed Okreœla, czy wielok¹t jest zamkniêty (domyœlnie true).
     * @return true, jeœli wielok¹t zosta³ narysowany; false w przypadku b³êdu.
     */
    bool drawPolygon(sf::RenderWindow& window, const std::vector<Point2D>& points, sf::Color color, bool closed = true);

    /**
     * @brief Rysuje wype³niony okr¹g.
     *
     * @param window Obiekt do rysowania (np. sf::RenderWindow).
     * @param center Œrodek okrêgu.
     * @param radius Promieñ okrêgu.
     * @param color Kolor wype³nienia.
     */
    void drawFilledCircle(sf::RenderWindow& window, const Point2D& center, int radius, sf::Color color);

    /**
     * @brief Wype³nianie obszaru metod¹ krawêdziow¹ (border fill).
     *
     * @param renderTexture Tekstura do renderowania.
     * @param startX Pozycja pocz¹tkowa w osi X.
     * @param startY Pozycja pocz¹tkowa w osi Y.
     * @param fillColor Kolor wype³nienia.
     * @param boundaryColor Kolor krawêdzi.
     */
    void borderFill(sf::RenderTexture& renderTexture, int startX, int startY, sf::Color fillColor, sf::Color boundaryColor);

    /**
     * @brief Wype³nianie obszaru metod¹ zalewania (flood fill).
     *
     * @param renderTexture Tekstura do renderowania.
     * @param startX Pozycja pocz¹tkowa w osi X.
     * @param startY Pozycja pocz¹tkowa w osi Y.
     * @param fillColor Kolor wype³nienia.
     * @param oldColor Kolor pocz¹tkowy obszaru do wype³nienia.
     */
    void floodFill(sf::RenderTexture& renderTexture, int startX, int startY, sf::Color fillColor, sf::Color oldColor);

    /**
     * @brief Rysuje wype³niony wielok¹t.
     *
     * @param window Obiekt do rysowania (np. sf::RenderWindow).
     * @param points Wektor punktów definiuj¹cych wielok¹t.
     * @param fillColor Kolor wype³nienia.
     */
    void drawFilledPolygon(sf::RenderWindow& window, const std::vector<Point2D>& points, sf::Color fillColor);

    /**
     * @brief Rysuje wielok¹t z wype³nieniem i obrysem.
     *
     * @param window Obiekt do rysowania (np. sf::RenderWindow).
     * @param points Wektor punktów definiuj¹cych wielok¹t.
     * @param fillColor Kolor wype³nienia.
     */
    void drawBorderFilledPolygon(sf::RenderWindow& window, const std::vector<Point2D>& points, sf::Color fillColor);

    /**
     * @brief Rysuje wielok¹t wype³niony metod¹ zalewania (flood fill).
     *
     * @param window Obiekt do rysowania (np. sf::RenderWindow).
     * @param points Wektor punktów definiuj¹cych wielok¹t.
     * @param fillColor Kolor wype³nienia.
     */
    void drawFloodFilledPolygon(sf::RenderWindow& window, const std::vector<Point2D>& points, sf::Color fillColor);

    /**
     * @brief Skaluje wielok¹t.
     *
     * @param polygon Wektor punktów definiuj¹cych wielok¹t.
     * @param scaleX Skala w osi X.
     * @param scaleY Skala w osi Y.
     */
    static void scalePolygon(std::vector<Point2D>& polygon, float scaleX, float scaleY);

private:
    /**
     * @brief Sprawdza, czy istniej¹ przeciêcia miêdzy segmentami.
     *
     * @param segments Wektor segmentów do sprawdzenia.
     * @return true, jeœli istniej¹ przeciêcia; false w przeciwnym razie.
     */
    bool checkForIntersections(const std::vector<LineSegment>& segments);

    /**
     * @brief Sprawdza, czy dwa odcinki przecinaj¹ siê.
     *
     * @param p1 Punkt pocz¹tkowy pierwszego odcinka.
     * @param q1 Punkt koñcowy pierwszego odcinka.
     * @param p2 Punkt pocz¹tkowy drugiego odcinka.
     * @param q2 Punkt koñcowy drugiego odcinka.
     * @return true, jeœli odcinki przecinaj¹ siê; false w przeciwnym razie.
     */
    bool doIntersect(const Point2D& p1, const Point2D& q1, const Point2D& p2, const Point2D& q2);
};

#endif // PRIMITIVE_RENDERER_H
