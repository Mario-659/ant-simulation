#ifndef ANTSIMULATION_DISPLAYMANAGER_H
#define ANTSIMULATION_DISPLAYMANAGER_H

#include <SFML/Graphics.hpp>

#include "Config.h"
#include "Ant.h"
#include "World.h"

//class DisplayManager {
//public:
//    DisplayManager();
//
//    ~DisplayManager();
//
//    void update();
//
//private:
//    const sf::RenderWindow window;
//};

class DisplayManager
{
public:
    static void draw(Ant ant);

    //static void draw(Marker marker);

    //TODO ?????
    static void drawFood();

    static sf::RenderWindow window;
};


#endif //ANTSIMULATION_DISPLAYMANAGER_H
