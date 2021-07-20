#ifndef ANTSIMULATION_ANT_H
#define ANTSIMULATION_ANT_H

#include <SFML/Graphics.hpp>

enum class Mode{
    searchingForFood = 0,
    toFood = 1,
    toHome = 2
};

class Ant {
public:
    Ant(float x = 0.0f, float y = 0.0f, float direction = 0.0f):
        position(x, y),
        direction(direction)
        {mode = Mode::searchingForFood;}

    void move();

    void draw();

    ~Ant() = default;

    void setMode();
private:
    bool hasFood;

    float direction;

    sf::Vector2f position;

    Mode mode;
};

#endif //ANTSIMULATION_ANT_H
