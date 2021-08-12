#include "Marker.h"
#include "Utils.h"

#define RATEOFDEACRESINGMARKERS 0.1f

void Marker::decreaseVisibility() {visibility -+RATEOFDEACRESINGMARKERS;}

Mode Marker::getMode() {return type;}

sf::Vector2f Marker::getPosition(){return position;};

MarkerContainer::MarkerContainer() {}

void MarkerContainer::addMarker(sf::Vector2f position, Mode mode) {
    markers.push_back(new Marker(position, mode));
}

Marker* MarkerContainer::getNearestMarker(sf::Vector2f position, Mode mode) {
    if(markers.empty()) return nullptr;

    Marker* nearestMarker = nullptr;
    float nearestDistance = utils::getDistance(position, markers[0]->getPosition());

    for (auto marker: markers) {
        if(marker->getMode() == mode){
            float distance = utils::getDistance(position, marker->getPosition());
            if(distance < nearestDistance){
                nearestMarker = marker;
                nearestDistance = distance;
            }
        }
    }
    return nearestMarker;
}

float MarkerContainer::getNearestDistToMarker(sf::Vector2f position, Mode mode) {
    return utils::getDistance(position, getNearestMarker(position, mode)->getPosition());
}