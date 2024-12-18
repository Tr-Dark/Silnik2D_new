﻿#include "PrimitiveRenderer.h"
#include "Point2D.h"
#include "LineSegment.h"
#include <cmath> 
#include <stack>
#include <set>
#include <iostream>


/**
 * @brief Konstruktor klasy PrimitiveRenderer.
 * Inicjalizuje obiekt i wyświetla komunikat w konsoli.
 */
PrimitiveRenderer::PrimitiveRenderer() {
    std::cout << "PrimitiveRenderer constructor\n";
}

/**
 * @brief Rysuje linię między dwoma punktami za pomocą algorytmu przyrostowego.
 *
 * @param window Obiekt okna renderowania.
 * @param p1 Punkt początkowy linii.
 * @param p2 Punkt końcowy linii.
 * @param color Kolor linii.
 */
void PrimitiveRenderer::drawLineIncremental(sf::RenderTarget& window, const Point2D& p1, const Point2D& p2, sf::Color color) {
    int x0 = static_cast<int>(p1.getX());
    int y0 = static_cast<int>(p1.getY());
    int x1 = static_cast<int>(p2.getX());
    int y1 = static_cast<int>(p2.getY());

    int dx = x1 - x0;
    int dy = y1 - y0;

    // Sprawdzenie nachylenia odcinka
    bool steep = std::abs(dy) > std::abs(dx);

    if (steep) {
        // Jeśli nachylenie jest strome, zamieniamy x i y miejscami
        std::swap(x0, y0);
        std::swap(x1, y1);
        std::swap(dx, dy);
    }

    // Zapewnienie rysowania od lewej do prawej strony
    if (x0 > x1) {
        std::swap(x0, x1);
        std::swap(y0, y1);
        dx = x1 - x0;
        dy = y1 - y0;
    }

    // Obliczenie nachylenia
    float m = static_cast<float>(dy) / dx;
    float y = y0;

    // Główna pętla rysowania odcinka
    for (int x = x0; x <= x1; ++x) {
        if (steep) {
            // Jeśli nachylenie jest strome, rysujemy punkt z zamienionymi współrzędnymi
            sf::Vertex point(sf::Vector2f(y, x), color);
            window.draw(&point, 1, sf::Points);
        }
        else {
            // Jeśli nachylenie nie jest strome, rysujemy normalnie
            sf::Vertex point(sf::Vector2f(x, y), color);
            window.draw(&point, 1, sf::Points);
        }
        y += m;   // Aktualizacja współrzędnej y
    }
}

/**
 * @brief Rysuje polilinię łączącą zestaw punktów.
 *
 * @param window Obiekt okna renderowania.
 * @param points Wektor punktów definiujących polilinię.
 * @param color Kolor linii.
 * @param closed Jeśli true, rysuje zamkniętą polilinię.
 */
void PrimitiveRenderer::drawPolyline(sf::RenderWindow& window, const std::vector<Point2D>& points, sf::Color color, bool closed) {
    if (points.size() < 2) return;

    for (size_t i = 0; i < points.size() - 1; ++i) {
        drawLineIncremental(window, points[i], points[i + 1], color);
    }

    if (closed) {
        drawLineIncremental(window, points.back(), points.front(), color);
    }
}

/**
 * @brief Rysuje linię między dwoma punktami za pomocą podstawowego rysowania SFML.
 *
 * @param window Obiekt okna renderowania.
 * @param p1 Punkt początkowy linii.
 * @param p2 Punkt końcowy linii.
 * @param color Kolor linii.
 */
void PrimitiveRenderer::drawLineBasic(sf::RenderWindow& window, const Point2D& p1, const Point2D& p2, sf::Color color) {
    sf::VertexArray line(sf::Lines, 2);

    line[0].position = sf::Vector2f(p1.getX(), p1.getY());
    line[0].color = color;

    line[1].position = sf::Vector2f(p2.getX(), p2.getY());
    line[1].color = color;

    window.draw(line);
}

/**
 * @brief Rysuje okrąg za pomocą algorytmu rysowania okręgów.
 *
 * @param window Obiekt okna renderowania.
 * @param center Środek okręgu.
 * @param radius Promień okręgu.
 * @param color Kolor okręgu.
 */
void PrimitiveRenderer::drawCircle(sf::RenderWindow& window, const Point2D& center, int radius, sf::Color color) {
    int x0 = static_cast<int>(center.getX());
    int y0 = static_cast<int>(center.getY());

    int x = 0;
    int y = radius;
    int d = 1 - radius;


    while (x <= y) {
        sf::Vertex point1(sf::Vector2f(x0 + x, y0 + y), color);
        sf::Vertex point2(sf::Vector2f(x0 - x, y0 + y), color);
        sf::Vertex point3(sf::Vector2f(x0 + x, y0 - y), color);
        sf::Vertex point4(sf::Vector2f(x0 - x, y0 - y), color);
        sf::Vertex point5(sf::Vector2f(x0 + y, y0 + x), color);
        sf::Vertex point6(sf::Vector2f(x0 - y, y0 + x), color);
        sf::Vertex point7(sf::Vector2f(x0 + y, y0 - x), color);
        sf::Vertex point8(sf::Vector2f(x0 - y, y0 - x), color);

        window.draw(&point1, 1, sf::Points);
        window.draw(&point2, 1, sf::Points);
        window.draw(&point3, 1, sf::Points);
        window.draw(&point4, 1, sf::Points);
        window.draw(&point5, 1, sf::Points);
        window.draw(&point6, 1, sf::Points);
        window.draw(&point7, 1, sf::Points);
        window.draw(&point8, 1, sf::Points);

        if (d < 0) {
            d += 2 * x + 3;
        }
        else {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
}

/**
 * @brief Rysuje elipsę.
 *
 * @param window Obiekt okna renderowania.
 * @param center Środek elipsy.
 * @param rx Promień poziomy (wzdłuż osi X).
 * @param ry Promień pionowy (wzdłuż osi Y).
 * @param color Kolor elipsy.
 */
void PrimitiveRenderer::drawEllipse(sf::RenderWindow& window, const Point2D& center, int radiusX, int radiusY, sf::Color color) {
    int x0 = static_cast<int>(center.getX());
    int y0 = static_cast<int>(center.getY());
    int x = 0;
    int y = radiusY;
    int radiusX2 = radiusX * radiusX;
    int radiusY2 = radiusY * radiusY;
    int twoRadiusX2 = 2 * radiusX2;
    int twoRadiusY2 = 2 * radiusY2;
    int p;
    int px = 0;
    int py = twoRadiusX2 * y;

    p = static_cast<int>(radiusY2 - (radiusX2 * radiusY) + (0.25 * radiusX2));
    while (px < py) {
        sf::Vertex point1(sf::Vector2f(x0 + x, y0 + y), color);
        sf::Vertex point2(sf::Vector2f(x0 - x, y0 + y), color);
        sf::Vertex point3(sf::Vector2f(x0 + x, y0 - y), color);
        sf::Vertex point4(sf::Vector2f(x0 - x, y0 - y), color);

        window.draw(&point1, 1, sf::Points);
        window.draw(&point2, 1, sf::Points);
        window.draw(&point3, 1, sf::Points);
        window.draw(&point4, 1, sf::Points);

        x++;
        px += twoRadiusY2;
        if (p < 0) {
            p += radiusY2 + px;
        }
        else {
            y--;
            py -= twoRadiusX2;
            p += radiusY2 + px - py;
        }
    }

    p = static_cast<int>(radiusY2 * (x + 0.5) * (x + 0.5) + radiusX2 * (y - 1) * (y - 1) - radiusX2 * radiusY2);
    while (y >= 0) {
        sf::Vertex point5(sf::Vector2f(x0 + x, y0 + y), color);
        sf::Vertex point6(sf::Vector2f(x0 - x, y0 + y), color);
        sf::Vertex point7(sf::Vector2f(x0 + x, y0 - y), color);
        sf::Vertex point8(sf::Vector2f(x0 - x, y0 - y), color);

        window.draw(&point5, 1, sf::Points);
        window.draw(&point6, 1, sf::Points);
        window.draw(&point7, 1, sf::Points);
        window.draw(&point8, 1, sf::Points);

        y--;
        py -= twoRadiusX2;
        if (p > 0) {
            p += radiusX2 - py;
        }
        else {
            x++;
            px += twoRadiusY2;
            p += radiusX2 - py + px;
        }
    }
}

/**
 * @brief Rysuje wielokąt na podstawie podanych punktów.
 *
 * Funkcja rysuje wielokąt na podstawie wektora punktów, łącząc je odcinkami.
 * Opcjonalnie zamyka wielokąt, łącząc ostatni punkt z pierwszym.
 * W przypadku wykrycia przecinających się odcinków wielokąt nie zostanie narysowany.
 *
 * @param window Obiekt okna renderowania.
 * @param points Wektor punktów definiujących wierzchołki wielokąta.
 * @param color Kolor odcinków wielokąta.
 * @param closed Flaga określająca, czy wielokąt powinien być zamknięty (ostatni punkt połączony z pierwszym).
 *
 * @return true Jeśli wielokąt został poprawnie narysowany.
 * @return false Jeśli podano mniej niż dwa punkty lub wykryto przecinające się odcinki.
 */

bool PrimitiveRenderer::drawPolygon(sf::RenderWindow& window, const std::vector<Point2D>& points, sf::Color color, bool closed) {
    if (points.size() < 2) return false;

    std::vector<LineSegment> segments;
    for (size_t i = 0; i < points.size() - 1; ++i) {
        segments.emplace_back(points[i], points[i + 1]);
    }
    if (closed) {
        segments.emplace_back(points.back(), points[0]);
    }

    if (checkForIntersections(segments)) {
        return false;
    }

    for (auto segment : segments) {
        segment.draw(window, *this, color);
        return true;
    }
}

/**
 * @brief Sprawdza, czy w podanym wektorze odcinków występują przecięcia.
 *
 * Funkcja analizuje wszystkie pary odcinków w podanym wektorze i sprawdza,
 * czy jakiekolwiek dwa odcinki się przecinają.
 * Wykorzystuje funkcję `doIntersect` do wykrycia przecięć.
 *
 * @param segments Wektor odcinków do sprawdzenia.
 *
 * @return true Jeśli co najmniej dwa odcinki się przecinają.
 * @return false Jeśli żadne odcinki się nie przecinają.
 *
 * @see doIntersect
 */
bool PrimitiveRenderer::checkForIntersections(const std::vector<LineSegment>& segments) {
    for (size_t i = 0; i < segments.size(); ++i) {
        for (size_t j = i + 1; j < segments.size(); ++j) {
            if (doIntersect(segments[i].getStartPoint(), segments[i].getEndPoint(), segments[j].getStartPoint(), segments[j].getEndPoint())) {
                return true; 
            }
        }
    }
    return false; 
}

/**
 * @brief Sprawdza, czy dwa odcinki się przecinają.
 *
 * Funkcja określa, czy dwa odcinki, zdefiniowane przez swoje końcowe punkty,
 * przecinają się. Wykorzystuje iloczyn wektorowy do określenia wzajemnego położenia punktów.
 *
 * @param p1 Początek pierwszego odcinka.
 * @param q1 Koniec pierwszego odcinka.
 * @param p2 Początek drugiego odcinka.
 * @param q2 Koniec drugiego odcinka.
 *
 * @return true Jeśli odcinki się przecinają.
 * @return false Jeśli odcinki się nie przecinają.
 *
 * @note Zakłada, że odcinki są ograniczone (nie są przedłużone do prostych).
 */
bool PrimitiveRenderer::doIntersect(const Point2D& p1, const Point2D& q1, const Point2D& p2, const Point2D& q2)
{
    auto crossProduct = [](const Point2D& a, const Point2D& b, const Point2D& c) {
        return (b.getX() - a.getX()) * (c.getY() - a.getY()) - (b.getY() - a.getY()) * (c.getX() - a.getX());
        };

    float d1 = crossProduct(p1, q1, p2);
    float d2 = crossProduct(p1, q1, q2);
    float d3 = crossProduct(p2, q2, p1);
    float d4 = crossProduct(p2, q2, q1);

    if (d1 * d2 < 0 && d3 * d4 < 0) return true;

    return false;
}

/**
 * @brief Rysuje okrąg z wypełnieniem.
 *
 * @param window Obiekt okna renderowania.
 * @param center Środek okręgu.
 * @param radius Promień okręgu.
 * @param color Kolor okręgu.
 */
void PrimitiveRenderer::drawFilledCircle(sf::RenderWindow& window, const Point2D& center, int radius, sf::Color color) {
    for (int y = -radius; y <= radius; y++) {
        for (int x = -radius; x <= radius; x++) {
            if (x * x + y * y <= radius * radius) {
                sf::Vertex point(sf::Vector2f(center.getX() + x, center.getY() + y), color);
                window.draw(&point, 1, sf::Points);
            }
        }
    }
}

/**
 * @brief Wypełnia obszar kolorem do granicy określonej kolorem granicznym.
 *
 * Funkcja wykonuje algorytm wypełniania obszaru (ang. boundary fill), zaczynając od punktu startowego.
 * Wypełnia wszystkie piksele w zadanym obszarze, które nie są w kolorze granicznym
 * i nie są już wypełnione kolorem wypełnienia.
 *
 * @param renderTexture Obiekt `sf::RenderTexture`, w którym przeprowadzane jest wypełnianie.
 * @param startX Współrzędna X punktu początkowego.
 * @param startY Współrzędna Y punktu początkowego.
 * @param fillColor Kolor, którym wypełniany jest obszar.
 * @param boundaryColor Kolor graniczny definiujący zakres wypełnienia.
 *
 * @note Funkcja zakłada, że punkt początkowy znajduje się wewnątrz obszaru do wypełnienia
 *       oraz że kolory `fillColor` i `boundaryColor` są różne.
 */
void PrimitiveRenderer::borderFill(sf::RenderTexture& renderTexture, int startX, int startY, sf::Color fillColor, sf::Color boundaryColor) {
    sf::Image image = renderTexture.getTexture().copyToImage(); // Копіюємо текстуру в зображення
    std::stack<sf::Vector2i> fillStack;
    std::set<std::pair<int, int>> visited;

    fillStack.push(sf::Vector2i(startX, startY));

    while (!fillStack.empty()) {
        sf::Vector2i p = fillStack.top();
        fillStack.pop();

       
        if (p.x < 0 || p.x >= static_cast<int>(image.getSize().x) || p.y < 0 || p.y >= static_cast<int>(image.getSize().y)) {
            continue;
        }

        
        if (visited.find({ p.x, p.y }) != visited.end()) {
            continue;
        }
        visited.insert({ p.x, p.y });

       
        sf::Color currentColor = image.getPixel(p.x, p.y);

        if (currentColor != boundaryColor && currentColor != fillColor) {
           
            sf::Vertex point(sf::Vector2f(p.x, p.y), fillColor);
            renderTexture.draw(&point, 1, sf::Points);

      
            fillStack.push(sf::Vector2i(p.x + 1, p.y));
            fillStack.push(sf::Vector2i(p.x - 1, p.y)); 
            fillStack.push(sf::Vector2i(p.x, p.y + 1)); 
            fillStack.push(sf::Vector2i(p.x, p.y - 1)); 
        }
    }
}

/**
 * @brief Wypełnia obszar kolorem na podstawie algorytmu flood-fill.
 *
 * Funkcja wykonuje algorytm wypełniania obszaru (ang. flood-fill), zaczynając od punktu początkowego.
 * Wypełnia wszystkie sąsiadujące piksele o tym samym kolorze co `oldColor`, zmieniając je na `fillColor`.
 *
 * @param renderTexture Obiekt `sf::RenderTexture`, w którym przeprowadzane jest wypełnianie.
 * @param startX Współrzędna X punktu początkowego.
 * @param startY Współrzędna Y punktu początkowego.
 * @param fillColor Kolor, którym wypełniany jest obszar.
 * @param oldColor Kolor pierwotny, który ma zostać zastąpiony kolorem `fillColor`.
 *
 * @note Funkcja zakłada, że punkt początkowy ma kolor równy `oldColor`.
 *       Jeśli `fillColor` i `oldColor` są takie same, funkcja nic nie zmieni.
 */
void PrimitiveRenderer::floodFill(sf::RenderTexture& renderTexture, int startX, int startY, sf::Color fillColor, sf::Color oldColor) {
    sf::Image image = renderTexture.getTexture().copyToImage(); 
    std::stack<sf::Vector2i> fillStack;
    std::set<std::pair<int, int>> visited;

 
    fillStack.push(sf::Vector2i(startX, startY));

    while (!fillStack.empty()) {
        sf::Vector2i p = fillStack.top();
        fillStack.pop();

     
        if (p.x < 0 || p.x >= static_cast<int>(image.getSize().x) || p.y < 0 || p.y >= static_cast<int>(image.getSize().y)) {
            continue;
        }

        if (visited.find({ p.x, p.y }) != visited.end()) {
            continue;
        }
        visited.insert({ p.x, p.y });

    
        sf::Color currentColor = image.getPixel(p.x, p.y);

        if (currentColor == oldColor) {
        
            sf::Vertex point(sf::Vector2f(p.x, p.y), fillColor);
            renderTexture.draw(&point, 1, sf::Points);

            fillStack.push(sf::Vector2i(p.x + 1, p.y)); 
            fillStack.push(sf::Vector2i(p.x - 1, p.y)); 
            fillStack.push(sf::Vector2i(p.x, p.y + 1)); 
            fillStack.push(sf::Vector2i(p.x, p.y - 1)); 
        }
    }
}

/**
 * @brief Rysuje wielokąt z wypełnieniem, zachowując granicę.
 *
 * Funkcja rysuje wielokąt określony przez wektor punktów, z wypełnieniem w zadanym kolorze.
 * Granice wielokąta są rysowane na podstawie jego wierzchołków, a następnie obszar wewnętrzny
 * wypełniany jest w określonym kolorze, używając algorytmu wypełniania obszaru.
 *
 * @param window Okno, na którym będzie rysowany wielokąt.
 * @param points Wektor punktów, które definiują wierzchołki wielokąta.
 * @param fillColor Kolor wypełnienia obszaru wewnętrznego wielokąta.
 *
 * @note Funkcja sprawdza, czy liczba punktów jest wystarczająca do narysowania wielokąta
 * (musi ich być co najmniej 3). Jeśli liczba punktów jest mniejsza, funkcja nie wykonuje rysowania.
 * @note Funkcja tworzy tymczasowy obiekt `RenderTexture`, aby wykonać operację wypełnienia,
 * a następnie rysuje gotowy obraz w oknie.
 */
void PrimitiveRenderer::drawBorderFilledPolygon(sf::RenderWindow& window, const std::vector<Point2D>& points, sf::Color fillColor) {
    if (points.size() < 3) {
        std::cerr << "drawBorderFilledPolygon: Insufficient vertices to draw a polygon." << std::endl;
        return;
    }

  
    sf::RenderTexture renderTexture;
    if (!renderTexture.create(window.getSize().x, window.getSize().y)) {
        std::cerr << "drawBorderFilledPolygon: Failed to create RenderTexture." << std::endl;
        return;
    }
    renderTexture.clear(sf::Color::Transparent);

   
    for (size_t i = 0; i < points.size(); ++i) {
        Point2D start = points[i];
        Point2D end = points[(i + 1) % points.size()]; 
        drawLineIncremental(renderTexture, start, end, sf::Color::White);
    }

    renderTexture.display(); 


    int minX = static_cast<int>(points[0].getX());
    int minY = static_cast<int>(points[0].getY());
    int maxX = static_cast<int>(points[0].getX());
    int maxY = static_cast<int>(points[0].getY());

    for (const auto& point : points) {
        minX = std::min(minX, static_cast<int>(point.getX()));
        minY = std::min(minY, static_cast<int>(point.getY()));
        maxX = std::max(maxX, static_cast<int>(point.getX()));
        maxY = std::max(maxY, static_cast<int>(point.getY()));
    }

    int startX = (minX + maxX) / 2;
    int startY = (minY + maxY) / 2;

  
    borderFill(renderTexture, startX, startY, fillColor, sf::Color::White);


    sf::Sprite filledPolygon(renderTexture.getTexture());
    window.draw(filledPolygon);
}


void PrimitiveRenderer::drawFilledPolygon(sf::RenderWindow& window, const std::vector<Point2D>& points, sf::Color fillColor) {
    if (points.size() < 3) return;


    int minY = static_cast<int>(points[0].getY());
    int maxY = static_cast<int>(points[0].getY());
    for (const auto& point : points) {
        minY = std::min(minY, static_cast<int>(point.getY()));
        maxY = std::max(maxY, static_cast<int>(point.getY()));
    }

    for (int y = minY; y <= maxY; ++y) {
        std::vector<int> intersections;


        for (size_t i = 0; i < points.size(); ++i) {
            Point2D p1 = points[i];
            Point2D p2 = points[(i + 1) % points.size()];

          
            if ((p1.getY() <= y && p2.getY() > y) || (p2.getY() <= y && p1.getY() > y)) {
          
                float dx = p2.getX() - p1.getX();
                float dy = p2.getY() - p1.getY();
                int x = static_cast<int>(p1.getX() + dx * (y - p1.getY()) / dy);
                intersections.push_back(x);
            }
        }


        std::sort(intersections.begin(), intersections.end());

        for (size_t i = 0; i < intersections.size(); i += 2) {
            if (i + 1 < intersections.size()) {
                int xStart = intersections[i];
                int xEnd = intersections[i + 1];

                for (int x = xStart; x <= xEnd; ++x) {
                    sf::Vertex point(sf::Vector2f(x, y), fillColor);
                    window.draw(&point, 1, sf::Points);
                }
            }
        }
    }
}


/**
 * @brief Rysuje wypełniony wielokąt na podstawie podanych punktów.
 *
 * Funkcja rysuje wypełniony wielokąt na podstawie wierzchołków zdefiniowanych w wektorze punktów.
 * Wypełnienie jest wykonywane na podstawie algorytmu skanowania poziomych linii, w którym obliczane są
 * punkty przecięcia krawędzi wielokąta z poziomymi liniami. Następnie wypełniany jest obszar
 * między tymi punktami.
 *
 * @param window Okno, w którym zostanie narysowany wypełniony wielokąt.
 * @param points Wektor punktów, które definiują wierzchołki wielokąta.
 * @param fillColor Kolor, którym zostanie wypełniony obszar wewnętrzny wielokąta.
 *
 * @note Funkcja sprawdza, czy liczba punktów wynosi co najmniej 3 (minimalna liczba wierzchołków dla
 * wielokąta). Jeśli nie, funkcja nie wykonuje żadnego rysowania.
 * @note Algorytm działa na zasadzie skanowania poziomych linii, gdzie dla każdej linii poziomej
 * (o stałej wartości `y`) obliczane są punkty przecięcia z krawędziami wielokąta. Następnie
 * obszar między tymi punktami jest wypełniany w zadanym kolorze.
 */
void PrimitiveRenderer::drawFloodFilledPolygon(sf::RenderWindow& window, const std::vector<Point2D>& points, sf::Color fillColor) {
    if (points.size() < 3) {
        std::cerr << "drawFloodFilledPolygon: Insufficient vertices to draw a polygon." << std::endl;
        return;
    }


    sf::RenderTexture renderTexture;
    if (!renderTexture.create(window.getSize().x, window.getSize().y)) {
        std::cerr << "drawFloodFilledPolygon: Failed to create RenderTexture." << std::endl;
        return;
    }
    renderTexture.clear(sf::Color::Transparent);

 
    for (size_t i = 0; i < points.size(); ++i) {
        Point2D start = points[i];
        Point2D end = points[(i + 1) % points.size()]; 
        drawLineIncremental(renderTexture, start, end, sf::Color::White);
    }

    renderTexture.display();


    sf::Image image = renderTexture.getTexture().copyToImage();


    int minX = static_cast<int>(points[0].getX());
    int minY = static_cast<int>(points[0].getY());
    int maxX = static_cast<int>(points[0].getX());
    int maxY = static_cast<int>(points[0].getY());

    for (const auto& point : points) {
        minX = std::min(minX, static_cast<int>(point.getX()));
        minY = std::min(minY, static_cast<int>(point.getY()));
        maxX = std::max(maxX, static_cast<int>(point.getX()));
        maxY = std::max(maxY, static_cast<int>(point.getY()));
    }

    int startX = (minX + maxX) / 2;
    int startY = (minY + maxY) / 2;


    sf::Color boundaryColor = sf::Color::White; 
    sf::Color oldColor = image.getPixel(startX, startY);

    if (oldColor == boundaryColor) {
        std::cerr << "drawFloodFilledPolygon: Start point is on the boundary!" << std::endl;
        return;
    }


    floodFill(renderTexture, startX, startY, fillColor, oldColor);


    renderTexture.display();
    sf::Sprite filledPolygon(renderTexture.getTexture());
    window.draw(filledPolygon);
}