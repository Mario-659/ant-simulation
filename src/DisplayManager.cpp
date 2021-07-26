#include "DisplayManager.h"
#include "Config.h"

DisplayManager::DisplayManager() {
    createWorldTexture();
    loadAntSprite();
}

void DisplayManager::createWorldTexture() {
    if(!worldTexture.create(Config::boardWidth, Config::boardHeight)) throw std::runtime_error("Couldn't create WorldTexture");
}

void DisplayManager::loadAntSprite(){
    antSprite.setTexture(Config::antTexture);
    antSprite.setScale(Config::scaleOfAnts);
}

void DisplayManager::drawAnt(sf::Vector2f position, float angle) {
    antSprite.setPosition(position);
    antSprite.setRotation(angle);
    worldTexture.draw(antSprite);
}

const sf::Texture& DisplayManager::getWorldTexture() {
    return worldTexture.getTexture();
}
