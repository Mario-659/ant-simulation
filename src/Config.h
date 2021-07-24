#ifndef ANTSIMULATION_CONFIG_H
#define ANTSIMULATION_CONFIG_H

#include <SFML/Graphics.hpp>

struct Config {

    static unsigned numberOfAnts;
    static unsigned windowWidth;
    static unsigned windowHeight;
    static unsigned boardWidth;
    static unsigned boardHeight;

    static sf::Vector2f scaleOfAnts;

    static sf::Color backgroundColor;
    static sf::Color foodColor;
    static sf::Color toFoodMarkerColor;
    static sf::Color toHomeMarkerColor;

    static sf::Texture antTexture;
    static sf::Sprite antSprite;

    static void readConfigFile();
    static void loadTexture();
};



#endif //ANTSIMULATION_CONFIG_H
