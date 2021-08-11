#ifndef ANTSIMULATION_UTILS_H
#define ANTSIMULATION_UTILS_H

#include <SFML/Graphics.hpp>

namespace utils{

    float getDistance(sf::Vector2f pos1, sf::Vector2f pos2);

    float getAngle(sf::Vector2f pos1, sf::Vector2f pos2);

    float getDegrees(float radians);
}



#endif //ANTSIMULATION_UTILS_H
