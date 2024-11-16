#include <SFML/Graphics.hpp>
#include "Engine.h"
#include "BitmapHandler.h"
#include <iostream>
#include "AnimatedObject.h"
#include "Player.h"
#include <array>
#include <string>

//using namespace std;


int main() {
    std::array<std::string, 16> PlayerSpriteimagePaths = {
    "../images/prawy1.png",
    "../images/prawy2.png",
    "../images/prawy3.png",
    "../images/prawy4.png",
    "../images/lewy1.png",
    "../images/lewy2.png",
    "../images/lewy3.png",
    "../images/lewy4.png",
    "../images/gora1.png",
    "../images/gora2.png",
    "../images/gora3.png",
    "../images/gora4.png",
    "../images/dol1.png",
    "../images/dol2.png",
    "../images/dol3.png",
    "../images/dol4.png"
    };
    std::string backgroundFilePath = "../images/tlo.png";


    Engine engine(800, 600, "Demo with Background and Primitives", PlayerSpriteimagePaths);
        
    // Завантаження фону
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("../images/tlo.png")) {
        std::cerr << "Failed to load background image\n";
        return -1;
    }
    
    engine.setBackground(backgroundTexture);

    engine.getPlayer().getSprite().setPosition(100, 100);

    engine.run();
    return 0;
}