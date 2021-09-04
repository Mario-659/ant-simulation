#include "Ant.h"
#include "Utils.h"

#define DISTANCETOMARKER 2.f
#define MINANGLE -5.f
#define MAXANGLE 5.f
#define DISTANCEWHENMOVING 0.5
#define DISTANCETOFOOD 2
#define DISTANCETOCOLONY 3
#define TURNSTOLEAVEMARKER 1000

sf::Vector2f Ant::getPosition() {return position;}

DisplayManager* Ant::displayManager = nullptr;

void Ant::move(MarkerContainer* markerContainer, Food* foodPoints)
{
    directionToMarker(markerContainer);
    moveForward();
    takeFood(foodPoints);
    leaveFood(foodPoints);
    leaveMarker(*markerContainer);
    markerContainer->decreaseVisibility();
}

//TODO refactor
void Ant::directionToMarker(MarkerContainer* markerContainer) {
    Mode mode;
    if(!hasFood) mode = Mode::toFood;
    else mode = Mode::toHome;

    Marker* nearestMarker = markerContainer->getNearestMarker(position, mode, twoLastMarkers);
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
    addLastMarker(nearestMarker);
}

void Ant::moveForward() {
    sf::Vector2f movement = utils::getVector(direction, DISTANCEWHENMOVING);
    position += movement;
}

void Ant::takeFood(Food* food) {
    if(hasFood) return;
    sf::Vector2f* nearestFood = food->getNearestFood(position);
    if(nearestFood && utils::getDistance(position, *nearestFood) < DISTANCETOFOOD){
        food->takeFood(*nearestFood);
        direction += 180.f;
        if(direction >= 360.f) direction -= 360.f;
        hasFood = true;
    }
}

void Ant::leaveFood(Food* food) {
    if(hasFood && utils::getDistance(position, sf::Vector2f(0.f, 0.f)) < DISTANCETOCOLONY){
        hasFood = false;
        food->addUsedFood(position);
    }
}

void Ant::draw(DisplayManager* displayManager) {
   displayManager->drawAnt(position, direction, hasFood);
}

void Ant::leaveMarker(MarkerContainer& markerContainer) {
    static int turnsToLeaveMarker = TURNSTOLEAVEMARKER;
    turnsToLeaveMarker--;
    if(turnsToLeaveMarker == 0){
        if(!hasFood) markerContainer.addMarker(position, Mode::toHome);
        else markerContainer.addMarker(position, Mode::toFood);
        turnsToLeaveMarker = TURNSTOLEAVEMARKER;
    }
}

float Ant::getAngle() {return direction;}

bool Ant::isCarryingFood() {return hasFood;}

void Ant::addLastMarker(Marker* lastMarker) {
    twoLastMarkers[1] = twoLastMarkers[0];
    twoLastMarkers[0] = lastMarker;
}