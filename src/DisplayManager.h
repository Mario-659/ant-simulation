#ifndef ANTSIMULATION_DISPLAYMANAGER_H
#define ANTSIMULATION_DISPLAYMANAGER_H

#include <SFML/Graphics.hpp>

#include "Ant.h"
#include "World.h"

class DisplayManager
{
public:
    DisplayManager();

    ~DisplayManager() = default;

    void draw(Ant ant);

    //static void draw(Marker marker);

    //TODO ?????
    void drawFood();

    void loadAntSprite();

    void createWorldTexture();

    const sf::Texture& getWorldTexture();
private:

    sf::RenderTexture worldTexture;

    sf::Sprite antSprite;
};


#endif //ANTSIMULATION_DISPLAYMANAGER_H
