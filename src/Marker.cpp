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

float MarkerContainer::getNearestDistToMarker(sf::Vector2f position, Mode mode) {
    return utils::getDistance(position, getNearestMarker(position, mode)->getPosition());
}