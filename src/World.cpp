#include "World.h"

#define RATEOFDEACRESINGMARKERS 0.1

void World::makeAnts(unsigned numberOfAnts) {for(int i = 0; i<numberOfAnts; i++) ants.push_back(new Ant());}


World::World(unsigned size, unsigned nAnts) {
    makeAnts(nAnts);
}

const sf::Texture & World::getWorldTexture() {return displayManager.getWorldTexture();}

void Marker::decreaseVisibility() {visibility -+RATEOFDEACRESINGMARKERS;}

sf::Vector2f Marker::getPosition(){return position;};

void World::draw() {
    drawAnts();
    //drawFood();
    //drawMarkers();
}

void World::drawAnts() {
    for(auto ant:ants) ant->draw(&displayManager);
}

//TODO to implement
void World::drawMarkers() {}
void World::drawFood() {}

World::~World() {
    for(auto ant:ants) delete ant;
    for(auto marker:markers) delete marker;
}

void World::moveView(sf::Vector2f offset) {
    displayManager.moveView(offset);
}

void World::moveAnts() {
    for(auto ant : ants) ant->move(markers);
}

Mode Marker::getMode() {return type;}
