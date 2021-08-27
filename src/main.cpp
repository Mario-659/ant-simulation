#include <SFML/Graphics.hpp>
#include "Config.h"
#include "Ant.h"
#include "World.h"

int main()
{

    World world(1,20);

    sf::RenderWindow window(sf::VideoMode(1400, 1400), "Ant Simulation");
    sf::Vector2u mousePosition(0, 0);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(Config::backgroundColor);


//        //Moving view with a mouse
//        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
//        {
//            //TODO world.moveView dziala ale cos z ta myszka nie tak
//            sf::Vector2u newPosition(sf::Mouse::getPosition());
//
//            float x = (float) newPosition.x - mousePosition.x;
//            float y = (float) newPosition.y - mousePosition.y;
//            world.moveView(sf::Vector2f(x, y));
//
//            mousePosition = newPosition;
//        }

        ///adding food when clicking
        if(sf::Mouse::isButtonPressed(sf::Mouse::Right))
        {
//            sf::Vector2f mousePosition;
//            mousePosition.x = sf::Mouse::getPosition().x;
//            mousePosition.y = sf::Mouse::getPosition().y;

            world.addFood(sf::Vector2f(100.f, 100.f));
        }


        ////////////////
        world.draw();
        sf::Sprite worldSprite;
        worldSprite.setTexture(world.getWorldTexture());
        window.draw(worldSprite);

        world.update();         //clears world texture and moves ants
        ////////////////


        window.display();
    }
    return 0;
}
