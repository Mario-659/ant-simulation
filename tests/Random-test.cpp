#include "gtest/gtest.h"

#include "Random.h"

TEST(random, getRandom){
    for(int i=0; i<1000; i++){
        float randomNumber = Random::getRandom(1.f, 100.f);
        EXPECT_TRUE(randomNumber<100.f && randomNumber>=1.f) << randomNumber;
    }
}

TEST(random, getRandomAngle){
    for(int i=0; i<1000; i++){
        float randomNumber = Random::getRandomAngle();
        EXPECT_TRUE(randomNumber<360.f && randomNumber>=0.f) << randomNumber;
    }
}

