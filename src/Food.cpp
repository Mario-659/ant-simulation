#include "Food.h"
#include "Utils.h"


Food::Food() {}

void Food::addFood(sf::Vector2f pos) {
    foodPoints.push_back(new sf::Vector2f(pos));
}

void Food::takeFood(sf::Vector2f pos) {
    if(foodPoints.empty()) throw std::runtime_error("Food positions data underflow");

    for(int i=0; i<foodPoints.size(); i++){
        if(foodPoints[i]->x == pos.x && foodPoints[i]->y == pos.y){
            foodPoints.erase(foodPoints.begin() + i);
        }
    }
}

sf::Vector2f* Food::getNearestFood(sf::Vector2f pos) {
    if(foodPoints.empty()) return nullptr;

    sf::Vector2f* nearestFoodPoint;
    float nearestDistance = utils::getDistance(pos, *foodPoints[0]);

    for(int i=0; i<foodPoints.size(); i++){
        float distance = utils::getDistance(pos, *foodPoints[i]);
        if(distance <= nearestDistance){
            nearestFoodPoint = foodPoints[i];
            nearestDistance = distance;
        }
    }
    return nearestFoodPoint;
}

void Food::drawFood(DisplayManager *displayManager) {
    for(auto food: foodPoints) displayManager->drawFood(*food);
}