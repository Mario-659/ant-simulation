#ifndef ANTSIMULATION_MARKER_H
#define ANTSIMULATION_MARKER_H

#include <SFML/Graphics.hpp>

enum class Mode{
    toFood = 0,
    toHome = 1
};

class Marker
{
public:
    Marker(sf::Vector2f position, Mode mode)
            :position(position),
             type(mode),
             visibility(1.f){}

    sf::Vector2f getPosition();

    void decreaseVisibility();

    Mode getMode();
private:
    float visibility;

    Mode type;

    sf::Vector2f position;
};

class MarkerContainer{

public:

    MarkerContainer();

    ~MarkerContainer() = default;

    void addMarker(sf::Vector2f position, Mode mode);

    Marker* getNearestMarker(sf::Vector2f position, Mode mode);

    float getNearestDistToMarker(sf::Vector2f position, Mode mode);

private:
    std::vector<Marker*> markers;

};

#endif //ANTSIMULATION_MARKER_H
