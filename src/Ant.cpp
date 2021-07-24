#include "Ant.h"
#include "DisplayManager.h"

sf::Vector2f Ant::getPosition() {return position;}

DisplayManager* Ant::displayManager = nullptr;

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
    displayManager->draw(*this);
}

float Ant::getAngle() {return direction;}

void Ant::setDisplayManager(DisplayManager *displayManag) {displayManager = displayManag;}