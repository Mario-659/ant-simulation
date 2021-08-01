#ifndef ANTSIMULATION_DISPLAYMANAGER_H
#define ANTSIMULATION_DISPLAYMANAGER_H

#include <SFML/Graphics.hpp>

class DisplayManager
{
public:
    DisplayManager();

    ~DisplayManager() = default;

    void drawAnt(sf::Vector2f position, float angle);

    //void drawMarker();

    //TODO ?????
    void drawFood();

    void createWorldTexture();

    const sf::Texture& getWorldTexture();

private:
    void loadAntSprite();

    void loadAntTexture();

    sf::Sprite antSprite;

    sf::Texture antTexture;

    sf::RenderTexture worldTexture;

};


#endif //ANTSIMULATION_DISPLAYMANAGER_H
