#ifndef ANTSIMULATION_WORLD_H
#define ANTSIMULATION_WORLD_H

#include <vector>

#include "Ant.h"
#include "DisplayManager.h"
#include "Config.h"

class World
{
public:
    void update();

    void draw();

    void setConfig();
private:

    Config config;

    std::vector<Ant*> ants;

    DisplayManager* displayManager;
};

#endif //ANTSIMULATION_WORLD_H
