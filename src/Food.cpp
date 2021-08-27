#include "Food.h"
#include "Utils.h"


Food::Food() {}

void Food::addFood(sf::Vector2f pos) {
    foodPoints.push_back(pos);
}

void Food::takeFood(sf::Vector2f pos) {
    if(foodPoints.empty()) throw std::runtime_error("Food positions data underflow");
    for(int i=0; i<foodPoints.size(); i++){
        if(foodPoints[i].x == pos.x && foodPoints[i].y == pos.y){
            foodPoints.erase(foodPoints.begin() + i);
        }
    }
}

sf::Vector2f* Food::getNearestFood(sf::Vector2f pos) {
    if(foodPoints.empty()) return nullptr;

    //TODO this is copy paste from Marker, refactor
    sf::Vector2f* nearestFoodPoint;
    float nearestDistance = utils::getDistance(pos, foodPoints[0]);

    for (auto foodPoint: foodPoints) {
            float distance = utils::getDistance(pos, foodPoint);
            if(distance < nearestDistance){
                nearestFoodPoint = &foodPoint;
                nearestDistance = distance;
            }
    }
    return nearestFoodPoint;
}

void Food::drawFood(DisplayManager *displayManager) {
    for(auto food: foodPoints) displayManager->drawFood(food);
}