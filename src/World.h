#ifndef ANTSIMULATION_WORLD_H
#define ANTSIMULATION_WORLD_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "Ant.h"
#include "DisplayManager.h"
#include "Config.h"
#include "Marker.h"
#include "Food.h"


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

    void moveView(sf::Vector2f offset);

    void moveAnts();

    void addFood(sf::Vector2f position);

private:

    void setConfig();

    std::vector<Ant*> ants;

    MarkerContainer* markerContainer;

    Food* foodPoints;

    void makeAnts(unsigned numberOfAnts);

    void drawAnts();

    void drawMarkers();

    void drawFood();

    DisplayManager displayManager;
};

#endif //ANTSIMULATION_WORLD_H
