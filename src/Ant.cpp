#include "Ant.h"
#include "DisplayManager.h"

sf::Vector2f Ant::getPosition() {return position;}

void Ant::move()
{
    if(mode == Mode::toFood)
    {

    }
    else
    {

    }
}

void Ant::draw() {
    DisplayManager::draw(*this);
}

float Ant::getAngle() {return direction;}