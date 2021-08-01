#include "Config.h"

//TODO readConfig
void Config::readConfigFile() {

}


///////////Default configuration//////////

unsigned Config::numberOfAnts = 20;
unsigned Config::windowWidth = 700;
unsigned Config::windowHeight = 700;
unsigned Config::boardWidth = 1400;
unsigned Config::boardHeight = 1400;

sf::Color Config::backgroundColor = sf::Color::White;
sf::Color Config::foodColor = sf::Color::Green;
sf::Color Config::toFoodMarkerColor = sf::Color::Blue;
sf::Color Config::toHomeMarkerColor = sf::Color::Yellow;

sf::Vector2f Config::scaleOfAnts(0.1f, 0.1f);






