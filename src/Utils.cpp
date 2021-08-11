#include "Utils.h"
#include <cmath>


float utils::getDistance(sf::Vector2f pos1, sf::Vector2f pos2){
    return sqrt(pow(pos1.x - pos2.x, 2.f) + pow(pos1.y - pos2.y, 2.f));
}

float utils::getAngle(sf::Vector2f pos1, sf::Vector2f pos2) {
    float delta_x = pos2.x - pos1.x;
    float delta_y = pos2.y - pos1.y;
    float radians = atan2f(delta_y, delta_x);
    float degrees = radians/M_PI * 180.f;
    if(degrees < 0) degrees += 360.f;
    return degrees;
}
