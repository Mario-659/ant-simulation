#include <SFML/Graphics.hpp>
#include "Config.h"
#include "Ant.h"
#include "World.h"

int main()
{
//    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
//
//    Config::loadTexture();
//    Config::loadSprite();
//
//    World world(20, 1);
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//        window.clear(Config::backgroundColor);
//        //window.draw(ant);
//
//        window.display();
//    }


World world(1,20);

    sf::RenderWindow window(sf::VideoMode(500, 500), "Ant Simulation");

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
        sf::Sprite worldSprite;
        worldSprite.setTexture(world.getWorldTexture());
        window.draw(worldSprite);
        ////////////////


        window.display();
    }



//    Config::loadTexture();
//    DisplayManager::loadAntSprite();
//    World world(1, 1);
//
//    while(DisplayManager::window.isOpen())
//    {
//        sf::Event event;
//        while (DisplayManager::window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                DisplayManager::window.close();
//        }
//        DisplayManager::window.clear(Config::backgroundColor);
//        world.draw();
//
//        DisplayManager::window.display();
//    }
//   return 0;
}