#include "DisplayManager.h"

//DisplayManager::DisplayManager()
//    :window(sf::RenderWindow(sf::VideoMode(Config::windowWidth, Config::windowHeight), "Ant Simulation"))
//{
//    //window = sf::RenderWindow(sf::VideoMode(Config::windowWidth, Config::windowHeight), "Ant Simulation");
//}

sf::RenderWindow DisplayManager::window(sf::VideoMode(Config::windowWidth, Config::windowHeight), "Ant simulation");


void DisplayManager::draw(Ant ant) {
    sf::Sprite sprite = Config::antSprite;
    sprite.setPosition(ant.getPosition());
    //TODO setRotation doesn't do what I thought it would do
    //sprite.setRotation(ant.getAngle());
    DisplayManager::window.draw(sprite);
}
