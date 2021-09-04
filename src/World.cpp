#include "World.h"

#define TURNSTOLEAVEMARKERS 50

void World::makeAnts(unsigned numberOfAnts) {for(int i = 0; i<numberOfAnts; i++) ants.push_back(new Ant());}


World::World(unsigned size, unsigned nAnts) {
    makeAnts(nAnts);
    markerContainer = new MarkerContainer();
    foodPoints = new Food();
}

const sf::Texture & World::getWorldTexture() {return displayManager.getWorldTexture();}

void World::draw() {
    drawAnts();
    drawFood();
    drawMarkers();
}

void World::drawAnts() {
    for(auto ant:ants) ant->draw(&displayManager);
}

//TODO to implement
void World::drawMarkers() {
    markerContainer->drawMarkers(&displayManager);
}

void World::drawFood() {
    foodPoints->drawFood(&displayManager);
}

World::~World() {
    for(auto ant:ants) delete ant;
    delete markerContainer;
}

void World::moveView(sf::Vector2f offset) {
    displayManager.moveView(offset);
}

void World::moveAnts() {
    for(auto ant : ants) ant->move(markerContainer, foodPoints);
}

void World::update() {
    static int turnsToLeaveMarkers = TURNSTOLEAVEMARKERS;
    turnsToLeaveMarkers--;

    displayManager.clearTexture();
    moveAnts();
    if(turnsToLeaveMarkers == 0)
    {
        for (auto ant: ants) ant->leaveMarker(*markerContainer);
        turnsToLeaveMarkers = TURNSTOLEAVEMARKERS;
    }
}

void World::addFood(sf::Vector2f position) {
    foodPoints->addFood(position);
}