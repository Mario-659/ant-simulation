#include <gtest/gtest.h>

#include "Ant.h"

TEST(Ant, Constructor){
    float X{3},Y{5.5},Dir{3.6};
    sf::Vector2f position(X, Y);

    Ant ant(X, Y, Dir);
    EXPECT_EQ(ant.getPosition(), position);

    sf::Vector2f position2(0.0f, 0.0f);
    Ant ant2;
    EXPECT_EQ(ant2.getPosition(), position2);
}

