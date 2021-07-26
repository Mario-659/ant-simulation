#ifndef ANTSIMULATION_WORLD_H
#define ANTSIMULATION_WORLD_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "Ant.h"
#include "DisplayManager.h"
#include "Config.h"

class Marker
{
public:
    Marker(float x, float y, Mode mode)
        :position(x, y),
        type(mode),
        visibility(1.f){}

    sf::Vector2f getPosition();

    void decreaseVisibility();
private:
    float visibility;

    Mode type;

    sf::Vector2f position;
};


class World
{
public:
    World(unsigned size, unsigned nAnts);

    ~World();

    //TODO to implement
    void update();

    //TODO to implement
    void draw();

    const sf::Texture& getWorldTexture();

private:

    void setConfig();

    std::vector<Ant*> ants;

    std::vector<Marker*> markers;

    void makeAnts(unsigned numberOfAnts);

    //void makeCells(unsigned sizeOfBoard);

    void drawAnts();

    void drawMarkers();

    void drawFood();

    DisplayManager displayManager;
};

#endif //ANTSIMULATION_WORLD_H
