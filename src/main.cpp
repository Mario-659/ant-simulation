#include <SFML/Graphics.hpp>
#include "Config.h"
#include "Ant.h"
#include "World.h"

int main()
{

World world(1,20);

    sf::RenderWindow window(sf::VideoMode(1400, 1400), "Ant Simulation");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(Config::backgroundColor);


        ////////////////
        world.draw();
        sf::Sprite worldSprite;
        worldSprite.setTexture(world.getWorldTexture());
        window.draw(worldSprite);

        ////////////////


        window.display();
    }

}