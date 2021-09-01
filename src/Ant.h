#ifndef ANTSIMULATION_ANT_H
#define ANTSIMULATION_ANT_H

#include <Vector>

#include "DisplayManager.h"
#include "Random.h"
#include "Marker.h"
#include "Food.h"


class Ant {
public:
    Ant(float x = 0.0f, float y = 0.0f, float direction = Random::getRandomAngle()):
        position(x, y),
        direction(direction)
        {hasFood = false;}

    //TODO to implement
    void move(MarkerContainer* markerContainer, Food* foodPoints);

    //TODO to implement
    void draw(DisplayManager* displayManager);

    ~Ant() = default;

    sf::Vector2f getPosition();

    float getAngle();

    bool isCarryingFood();
    
private:
    void leaveMarker(MarkerContainer& markerContainer);

    void directionToMarker(MarkerContainer* markerContainer);

    void moveForward();

    void takeFood(Food* food);

    void leaveFood(Food* food);

    bool hasFood;

    float direction;

    sf::Vector2f position;

    static DisplayManager* displayManager;
};

#endif //ANTSIMULATION_ANT_H
