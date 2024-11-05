/*
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
#include <string>

class GameObject {
public:
    virtual ~GameObject() {}

    // Metody czysto wirtualne
    virtual void update() = 0;
    virtual void draw() = 0;

    // Metoda do logowania b³êdów
    virtual void logError(const std::string& message) {
        std::cerr << "Error: " << message << std::endl;
    }
};

#endif // GAMEOBJECT_H
*/