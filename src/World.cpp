#include "World.h"

#define RATEOFDEACRESINGMARKERS 0.1

void World::makeAnts(unsigned numberOfAnts) {for(int i = 0; i<numberOfAnts; i++) ants.push_back(new Ant());}

//void World::makeCells(unsigned sizeOfBoard) {
//    unsigned nCells = sizeOfBoard * sizeOfBoard;
//    for(int i = 0; i<nCells; i++) cells.push_back(new Cell());
//}

World::World(unsigned size, unsigned nAnts) {
    makeAnts(nAnts);
    //makeCells(size);
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

