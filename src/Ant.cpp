#include "Ant.h"

#include "Utils.h"

#define DISTANCETOMARKER 20.f
#define MINANGLE -5.f
#define MAXANGLE 5.f
#define DISTANCEWHENMOVING 0.5
#define DISTANCETOFOOD 1

sf::Vector2f Ant::getPosition() {return position;}

DisplayManager* Ant::displayManager = nullptr;

void Ant::move(MarkerContainer* markerContainer, Food* foodPoints)
{
//    //TODO refactor
//    Marker* nearestMarker = markerContainer.getNearestMarker(position, mode);
//    if(nearestMarker && utils::getDistance(position, nearestMarker->getPosition()) < DISTANCETOMARKER) //first one checks if it is not nullptr
//    {
//        direction = utils::getAngle(position, nearestMarker->getPosition());
//    }
//    else
//    {
//        direction += Random::getRandom(MINANGLE, MAXANGLE);
//        if(direction >= 360.f) direction -= 360.f;
//        else if(direction < 0) direction += 360.f;
//    }
//    sf::Vector2f movement = utils::getVector(direction, DISTANCEWHENMOVING);
//    position += movement;
//
//    markerContainer.addMarker(position, mode);
//
//    sf::Vector2f nearestFood = foodPoints.getNearestFood(position);
//    if(nearestFood.x != 0.f  && utils::getDistance(position, nearestFood) < DISTANCETOFOOD)
//    {
//        foodPoints.takeFood(nearestFood);
//        direction += 180.f;
//        if(direction >= 360.f) direction -= 360.f;
//        mode = Mode::toHome;
//    }

    directionToMarker(markerContainer);
    moveForward();
    takeFood(foodPoints);
}

void Ant::directionToMarker(MarkerContainer* markerContainer) {
    Marker* nearestMarker = markerContainer->getNearestMarker(position, mode);
    if(nearestMarker && utils::getDistance(position, nearestMarker->getPosition()) < DISTANCETOMARKER)
    {
        direction = utils::getAngle(position, nearestMarker->getPosition());
    }
    else
    {
        direction += Random::getRandom(MINANGLE, MAXANGLE);
        if(direction >= 360.f) direction -= 360.f;
        else if(direction < 0) direction += 360.f;
    }
}

void Ant::moveForward() {
    sf::Vector2f movement = utils::getVector(direction, DISTANCEWHENMOVING);
    position += movement;
}

void Ant::takeFood(Food* food) {
    sf::Vector2f* nearestFood = food->getNearestFood(position);
    if(nearestFood && utils::getDistance(position, *nearestFood) < DISTANCETOFOOD){
        food->takeFood(*nearestFood);
        direction += 180.f;
        if(direction >= 360.f) direction -= 360.f;
        mode = Mode::toHome;
    }
}

void Ant::draw(DisplayManager* displayManager) {
   displayManager->drawAnt(position, direction);
}

float Ant::getAngle() {return direction;}
