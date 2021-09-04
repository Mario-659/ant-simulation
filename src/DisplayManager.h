#ifndef ANTSIMULATION_DISPLAYMANAGER_H
#define ANTSIMULATION_DISPLAYMANAGER_H

#include <SFML/Graphics.hpp>

class DisplayManager
{
public:
    DisplayManager();

    ~DisplayManager() = default;

    void drawAnt(sf::Vector2f position, float angle, bool hasFood);

    void drawToFoodMarker(sf::Vector2f position);

    void drawToHomeMarker(sf::Vector2f position);

    void drawFood(sf::Vector2f position);

    void createWorldTexture();

    void moveView(sf::Vector2f offset);

    const sf::Texture& getWorldTexture();

    void clearTexture();

private:
    void loadAntSprite();

    void loadAntTexture();

    void loadView();

    void createFoodSprite();

    void createMarkerSprites();

    sf::CircleShape food;

    sf::CircleShape toHomeMarker;

    sf::CircleShape toFoodMarker;

    sf::Sprite antSprite;

    sf::Texture antTexture;

    sf::RenderTexture worldTexture;

    sf::View view;
};


#endif //ANTSIMULATION_DISPLAYMANAGER_H
