#ifndef TOOLS_H
#define TOOLS_H

#include <SFML/Graphics.hpp>
#include "Point2D.h"


static class Tools {
public:
	static bool CheckMove(std::vector<Point2D> figure, float dx, float dy, float windowWidth, float windowHeight);
	static float getRandomOffset();

};


#endif //TOOLS_H