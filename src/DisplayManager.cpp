#include "DisplayManager.h"
#include "Config.h"

DisplayManager::DisplayManager() {
    createWorldTexture();
    loadView();
    loadAntTexture();
    loadAntSprite();
}

void DisplayManager::createWorldTexture() {
    if(!worldTexture.create(Config::boardWidth, Config::boardHeight)) throw std::runtime_error("Couldn't create WorldTexture");
    worldTexture.clear(Config::backgroundColor);
}

void DisplayManager::loadAntSprite(){
    antSprite.setTexture(antTexture);

    float width, height;
    width = antTexture.getSize().x;
    height = antTexture.getSize().y;

    antSprite.setOrigin(width/2, height/2);
    antSprite.setScale(Config::scaleOfAnts);
}

void DisplayManager::loadAntTexture(){
    if(!antTexture.loadFromFile("resources/ant.png")) throw std::runtime_error("Couldn't load textures from resources/png");
}

void DisplayManager::loadView() {
    view.setCenter(sf::Vector2f(0.f, 0.f));
    view.setSize(sf::Vector2f(Config::windowWidth, Config::windowHeight));
    worldTexture.setView(view);
}

void DisplayManager::moveView(sf::Vector2f offset) {
    view.move(offset);
    worldTexture.setView(view);
}

void DisplayManager::drawAnt(sf::Vector2f position, float angle) {
    antSprite.setPosition(position);
    antSprite.setRotation(angle + 90.f);        //TODO don't know why i need to add these 90 degrees
    worldTexture.draw(antSprite);
}

const sf::Texture& DisplayManager::getWorldTexture() {
    worldTexture.display();
    return worldTexture.getTexture();
}

void DisplayManager::clearTexture() {
    worldTexture.clear(Config::backgroundColor);
}