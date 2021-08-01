#include "DisplayManager.h"
#include "Config.h"

DisplayManager::DisplayManager() {
    createWorldTexture();
    loadAntTexture();
    loadAntSprite();
}

void DisplayManager::createWorldTexture() {
    if(!worldTexture.create(Config::boardWidth, Config::boardHeight)) throw std::runtime_error("Couldn't create WorldTexture");
    worldTexture.clear(Config::backgroundColor);
}

void DisplayManager::loadAntSprite(){
    antSprite.setTexture(antTexture);
    antSprite.setScale(Config::scaleOfAnts);
}

void DisplayManager::loadAntTexture(){
    if(!antTexture.loadFromFile("resources/ant.png")) throw std::runtime_error("Couldn't load textures from resources/png");
}

void DisplayManager::drawAnt(sf::Vector2f position, float angle) {
    antSprite.setPosition(position);
    antSprite.setRotation(angle);
    worldTexture.draw(antSprite);
}

const sf::Texture& DisplayManager::getWorldTexture() {
    worldTexture.display();
    return worldTexture.getTexture();
}
