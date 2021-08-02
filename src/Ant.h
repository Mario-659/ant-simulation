#ifndef ANTSIMULATION_ANT_H
#define ANTSIMULATION_ANT_H

#include <Vector>

#include "DisplayManager.h"
#include "Random.h"

class Marker;

enum class Mode{
    toFood = 0,
    toHome = 1
};

class Ant {
public:
    Ant(float x = 0.0f, float y = 0.0f, float direction = Random::getRandomAngle()):
        position(x, y),
        direction(direction)
        {mode = Mode::toFood;}

    //TODO to implement
    void move(std::vector<Marker*> markers);

    //TODO to implement
    void draw(DisplayManager* displayManager);

    ~Ant() = default;

    sf::Vector2f getPosition();

    float getAngle();
    
private:
    bool hasFood;

    float direction;

    sf::Vector2f position;

    Mode mode;

    static DisplayManager* displayManager;
};

#endif //ANTSIMULATION_ANT_H
