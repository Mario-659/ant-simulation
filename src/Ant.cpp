#include "Ant.h"

sf::Vector2f Ant::getPosition() {return position;}

DisplayManager* Ant::displayManager = nullptr;

void Ant::move()
{

}

void Ant::draw(DisplayManager* displayManager) {
   displayManager->drawAnt(position, direction);
}

float Ant::getAngle() {return direction;}
