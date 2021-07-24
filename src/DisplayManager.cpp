#include "DisplayManager.h"

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

void DisplayManager::draw(Ant ant) {
    antSprite.setPosition(ant.getPosition());
    antSprite.setRotation(ant.getAngle());
    worldTexture.draw(antSprite);
}

const sf::Texture& DisplayManager::getWorldTexture() {
    return worldTexture.getTexture();
}
