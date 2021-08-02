#include "Ant.h"

sf::Vector2f Ant::getPosition() {return position;}

DisplayManager* Ant::displayManager = nullptr;

void Ant::move(std::vector<Marker*> markers)
{
    if(hasFood)
    {
        float minDistance;
        for (auto marker: markers) {

        }
    }
    else
    {

    }

}

void Ant::draw(DisplayManager* displayManager) {
   displayManager->drawAnt(position, direction);
}

float Ant::getAngle() {return direction;}
