#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class Point2D {
public:
    Point2D(float x = 0, float y = 0) : x(x), y(y) {}

    float getX() const { return x; }
    float getY() const { return y; }

    void setX(float newX) { x = newX; }
    void setY(float newY) { y = newY; }

    void draw(sf::RenderWindow& window, sf::Color color = sf::Color::White) const {
        sf::CircleShape point(2);
        point.setPosition(x, y);
        point.setFillColor(color);
        window.draw(point);
    }

private:
    float x, y;
};

class PrimitiveRenderer {
public:
    // Малювання лінії (стандартний алгоритм SFML)
    void drawLine(sf::RenderWindow& window, const Point2D& p1, const Point2D& p2, sf::Color color = sf::Color::White) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(p1.getX(), p1.getY()), color),
            sf::Vertex(sf::Vector2f(p2.getX(), p2.getY()), color)
        };
        window.draw(line, 2, sf::Lines);
    }

    // Прирастовий алгоритм для малювання ліній (алгоритм Брезенхема)
    void drawLineIncremental(sf::RenderWindow& window, const Point2D& p1, const Point2D& p2, sf::Color color = sf::Color::Red) {
        int x1 = static_cast<int>(p1.getX());
        int y1 = static_cast<int>(p1.getY());
        int x2 = static_cast<int>(p2.getX());
        int y2 = static_cast<int>(p2.getY());

        int dx = abs(x2 - x1);
        int dy = abs(y2 - y1);
        int sx = (x1 < x2) ? 1 : -1;
        int sy = (y1 < y2) ? 1 : -1;
        int err = dx - dy;

        while (true) {
            sf::RectangleShape point(sf::Vector2f(1, 1));
            point.setPosition(static_cast<float>(x1), static_cast<float>(y1));
            point.setFillColor(color);
            window.draw(point);

            if (x1 == x2 && y1 == y2) break;

            int e2 = err * 2;
            if (e2 > -dy) {
                err -= dy;
                x1 += sx;
            }
            if (e2 < dx) {
                err += dx;
                y1 += sy;
            }
        }
    }

    // Метод для малювання відкритої ламаної лінії
    void drawOpenPolyline(sf::RenderWindow& window, const std::vector<Point2D>& points, sf::Color color = sf::Color::White) {
        for (size_t i = 0; i < points.size() - 1; ++i) {
            drawLine(window, points[i], points[i + 1], color);
        }
    }

    // Метод для малювання закритої ламаної лінії
    void drawClosedPolyline(sf::RenderWindow& window, const std::vector<Point2D>& points, sf::Color color = sf::Color::White) {
        drawOpenPolyline(window, points, color);
        if (!points.empty()) {
            drawLine(window, points.back(), points.front(), color);  // З'єднуємо останню і першу точку
        }
    }
};

class LineSegment {
public:
    LineSegment(const Point2D& p1, const Point2D& p2) : p1(p1), p2(p2) {}

    Point2D getP1() const { return p1; }
    Point2D getP2() const { return p2; }

    void setP1(const Point2D& newP1) { p1 = newP1; }
    void setP2(const Point2D& newP2) { p2 = newP2; }

    void draw(sf::RenderWindow& window, PrimitiveRenderer& renderer, bool useIncremental = false) const {
        if (useIncremental) {
            renderer.drawLineIncremental(window, p1, p2);
        }
        else {
            renderer.drawLine(window, p1, p2);
        }
    }

private:
    Point2D p1, p2;
};

class Engine {
public:
    Engine(int width, int height, const std::string& title, bool fullscreen = false) {
        if (fullscreen) {
            window.create(sf::VideoMode(width, height), title, sf::Style::Fullscreen);
        }
        else {
            window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
        }

        window.setFramerateLimit(60);
    }

    void run() {
        while (window.isOpen()) {
            processEvents();
            update();
            render();
        }
    }

private:
    sf::RenderWindow window;
    PrimitiveRenderer renderer;
    Point2D p1{ 100, 100 }, p2{ 300, 300 }, p3{400, 200};
    LineSegment line{ p1, p2 };

    std::vector<Point2D> openPolylinePoints = { p1, {200, 150}, {300, 100}, p3 };
    std::vector<Point2D> closedPolylinePoints = { {500, 400}, {600, 450}, {550, 500}, {500, 450} };

    void processEvents() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }

    void update() {
        // Логіка оновлення (можна додати анімацію тощо)
    }

    void render() {
        window.clear(sf::Color::Black);
        //line.draw(window, renderer, true);

        renderer.drawOpenPolyline(window, openPolylinePoints, sf::Color::Green);  // Малюємо відкриту ламану
        renderer.drawClosedPolyline(window, closedPolylinePoints, sf::Color::Blue);  // Малюємо закриту ламану
        renderer.drawLine(window, p1, p2, sf::Color::Magenta);

        window.display();
    }
};

int main() {
    Engine engine(800, 600, "2D Engine with Polylines", false);
    engine.run();
    return 0;
}
