#ifndef ANTSIMULATION_ANT_H
#define ANTSIMULATION_ANT_H

#include <SFML/Graphics.hpp>

#include "Random.h"

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
    void move();

    //TODO to implement
    void draw();

    ~Ant() = default;

    sf::Vector2f getPosition();

    float getAngle();
private:
    bool hasFood;

    float direction;

    sf::Vector2f position;

    Mode mode;
};

#endif //ANTSIMULATION_ANT_H
