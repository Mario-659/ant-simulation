#ifndef ANTSIMULATION_ANT_H
#define ANTSIMULATION_ANT_H

#include <Vector>

#include "DisplayManager.h"
#include "Random.h"
#include "Marker.h"
#include "Food.h"


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
    void move(MarkerContainer* markerContainer, Food* foodPoints);

    //TODO to implement
    void draw(DisplayManager* displayManager);

    ~Ant() = default;

    sf::Vector2f getPosition();

    float getAngle();
    
private:
    void directionToMarker(MarkerContainer* markerContainer);

    void moveForward();

    void takeFood(Food* food);

    bool hasFood;

    float direction;

    sf::Vector2f position;

    Mode mode;

    static DisplayManager* displayManager;
};

#endif //ANTSIMULATION_ANT_H
