#include "gtest/gtest.h"


#include <SFML/Graphics.hpp>
#include "Config.h"

TEST(congig, defaultConfig){
    EXPECT_EQ(Config::numberOfAnts,20);
    EXPECT_EQ(Config::windowWidth,700);
    EXPECT_EQ(Config::windowHeight,700);
    EXPECT_EQ(Config::boardWidth,1400);
    EXPECT_EQ(Config::boardHeight,1400);

    EXPECT_EQ(Config::backgroundColor, sf::Color::White);
    EXPECT_EQ(Config::foodColor, sf::Color::Green);
    EXPECT_EQ(Config::toFoodMarkerColor, sf::Color::Blue);
    EXPECT_EQ(Config::toHomeMarkerColor, sf::Color::Yellow);

    EXPECT_NO_THROW(Config::loadTexture());
    EXPECT_TRUE(Config::antTexture.getSize() != sf::Vector2u(0, 0));

    Config::loadSprite();
    EXPECT_TRUE(Config::antSprite.getTexture() != NULL);


}