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
    Config::loadTexture();
    Config::loadSprite();
    World world(1, 10);

    while(DisplayManager::window.isOpen())
    {
        sf::Event event;
        while (DisplayManager::window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                DisplayManager::window.close();
        }
        DisplayManager::window.clear(Config::backgroundColor);
        world.draw();

        DisplayManager::window.display();
    }
   return 0;
}