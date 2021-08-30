#include "gtest/gtest.h"

#include "Food.h"

TEST(foodTest, returnsNullptrWhenEmpty){
    Food food;

    auto pointer = food.getNearestFood(sf::Vector2f(0, 0));
    EXPECT_TRUE(pointer == nullptr);
}
