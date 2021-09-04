#ifndef ANTSIMULATION_FOOD_H
#define ANTSIMULATION_FOOD_H

#include "SFML/Graphics.hpp"
#include <vector>

#include "DisplayManager.h"



class Food {
public:

    Food();

    ~Food() = default;

    sf::Vector2f* getNearestFood(sf::Vector2f pos);

    void takeFood(sf::Vector2f pos);

    void addFood(sf::Vector2f pos);

    void addUsedFood(sf::Vector2f pos);

    void drawFood(DisplayManager* displayManager);

private:

    std::vector<sf::Vector2f*> usedFoodPoints;

    std::vector<sf::Vector2f*> foodPoints;
};


#endif //ANTSIMULATION_FOOD_H
