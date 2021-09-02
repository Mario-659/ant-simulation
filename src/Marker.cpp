#include "Marker.h"
#include "Utils.h"

#define RATEOFDEACRESINGMARKERS 0.1f

void Marker::decreaseVisibility() {visibility -+RATEOFDEACRESINGMARKERS;}

sf::Vector2f Marker::getPosition(){return position;};

MarkerContainer::MarkerContainer() {}

void MarkerContainer::addMarker(sf::Vector2f position, Mode mode) {
    if(mode == Mode::toFood) toFoodMarkers.push_back(new Marker(position));
    else toHomeMarkers.push_back(new Marker(position));
}

//TODO refactor
Marker* MarkerContainer::getNearestMarker(sf::Vector2f position, Mode mode) {
    std::vector<Marker*> markers;
    if(mode == Mode::toFood) markers = toFoodMarkers;
    else markers = toHomeMarkers;
    if(markers.empty()) return nullptr;

    Marker* nearestMarker = markers[0];
    float nearestDistance = utils::getDistance(position, markers[0]->getPosition());

    for (auto marker: markers) {
            float distance = utils::getDistance(position, marker->getPosition());
            if(distance < nearestDistance){
                nearestMarker = marker;
                nearestDistance = distance;
            }
    }
    return nearestMarker;
}

//TODO refactor
Marker* MarkerContainer::getNearestMarker(sf::Vector2f position, Mode mode, Marker* markersToAvoid[2]) {
//    std::vector<Marker*> markers;
//    if(mode == Mode::toFood) markers = toFoodMarkers;
//    else markers = toHomeMarkers;
//    if(markers.empty()) return nullptr;
//
//    Marker* nearestMarker = markers[0];
//    float nearestDistance = utils::getDistance(position, markers[0]->getPosition());
//
//    for (auto marker: markers) {
//        float distance = utils::getDistance(position, marker->getPosition());
//        if(distance < nearestDistance){
//            nearestMarker = marker;
//            nearestDistance = distance;
//        }
//    }
//    return nearestMarker;

    float nearestDistance = 100.f;
    Marker* nearestMarker = nullptr;
    if(Mode::toFood == mode){
        if(toFoodMarkers.empty()) return nearestMarker;
        for (auto marker: toFoodMarkers) {
            float distance = utils::getDistance(position, marker->getPosition());
            if(distance < nearestDistance && marker != markersToAvoid[0] && marker != markersToAvoid[1])
                nearestMarker = marker;
                nearestDistance = distance;
        }
    }
    else{
        if(toHomeMarkers.empty()) return nearestMarker;
        for (auto marker: toHomeMarkers) {
            float distance = utils::getDistance(position, marker->getPosition());
            if(distance < nearestDistance && marker != markersToAvoid[0] && marker != markersToAvoid[1])
                nearestMarker = marker;
            nearestDistance = distance;
        }
    }
    return nearestMarker;
}

float MarkerContainer::getNearestDistToMarker(sf::Vector2f position, Mode mode) {
    return utils::getDistance(position, getNearestMarker(position, mode)->getPosition());
}