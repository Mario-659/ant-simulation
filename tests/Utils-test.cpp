#include "gtest/gtest.h"
#include <cmath>

#include <SFML/Graphics.hpp>
#include "Utils.h"

class getDistance: public ::testing::Test{
public:
    void setUp(){};

    void TearDown(){};

    float dist;
};

TEST_F(getDistance, handlesSimplePositions){
    dist = utils::getDistance(sf::Vector2f(0, 0), sf::Vector2f(10, 0));
    EXPECT_FLOAT_EQ(dist, 10.f);

    dist = utils::getDistance(sf::Vector2f(0, 12), sf::Vector2f(0, 0));
    EXPECT_FLOAT_EQ(dist, 12.f);
}

TEST_F(getDistance, handlesSimpleNegativePositions){
    dist = utils::getDistance(sf::Vector2f(0, -12), sf::Vector2f(0, 0));
    EXPECT_FLOAT_EQ(dist, 12.f);

    dist = utils::getDistance(sf::Vector2f(-18, 0), sf::Vector2f(0, 0));
    EXPECT_FLOAT_EQ(dist, 18.f);
}

TEST_F(getDistance, handlesDifficultPositions){
    dist = utils::getDistance(sf::Vector2f(14.f, -8.f), sf::Vector2f(-4.f, 15.f));
    EXPECT_FLOAT_EQ(dist, 29.206164);

    dist = utils::getDistance(sf::Vector2f(-15.748,17.341), sf::Vector2f(-3.567,-21.777));
    EXPECT_FLOAT_EQ(dist, 40.970656);
}

TEST_F(getDistance, handlesPointers){
    sf::Vector2f* positionPointer = new sf::Vector2f(10.f, 0.f);
    dist = utils::getDistance(sf::Vector2f(0.f, 0.f), *positionPointer);
    EXPECT_FLOAT_EQ(dist, 10.f);
}

class getAngle: public ::testing::Test{
public:
    void SetUp(){};

    void TearDown(){};

    float angle;
};

TEST_F(getAngle, handles_x_as_0){
    angle = utils::getAngle(sf::Vector2f(0, 15), sf::Vector2f(0, 0));
    EXPECT_FLOAT_EQ(angle, 270.f);

    angle = utils::getAngle(sf::Vector2f(0,  -13.f), sf::Vector2f(0, 0));
    EXPECT_FLOAT_EQ(angle, 90.f);
}

TEST_F(getAngle, handles_y_as_0){
    angle = utils::getAngle(sf::Vector2f(13.f, 0), sf::Vector2f(0, 0));
    EXPECT_FLOAT_EQ(angle, 180.f);

    angle = utils::getAngle(sf::Vector2f(-13.f,  0), sf::Vector2f(0, 0));
    EXPECT_FLOAT_EQ(angle, 0);

    angle = utils::getAngle(sf::Vector2f(-13.f,  0), sf::Vector2f(-2.f, 0));
    EXPECT_FLOAT_EQ(angle, 0);
}

TEST_F(getAngle, handlesSimplePositions){
    angle = utils::getAngle(sf::Vector2f(13.f, 0.f), sf::Vector2f(-15.567, 0));
    EXPECT_FLOAT_EQ(angle, 180.f);

    angle = utils::getAngle(sf::Vector2f(3.f, 0.f), sf::Vector2f(3.f, 3.f));
    EXPECT_FLOAT_EQ(angle, 90.f);

    angle = utils::getAngle(sf::Vector2f(4.f, 1.f), sf::Vector2f(4.f, 4.f));
    EXPECT_FLOAT_EQ(angle, 90.f);

    angle = utils::getAngle(sf::Vector2f(-1.f, -4.f), sf::Vector2f(-1.f, 1.f));
    EXPECT_FLOAT_EQ(angle, 90.f);

    angle = utils::getAngle(sf::Vector2f(0.f, 0.f), sf::Vector2f(3.f, 3.f));
    EXPECT_FLOAT_EQ(angle, 45.f);

    angle = utils::getAngle(sf::Vector2f(4.f, 4.f), sf::Vector2f(7.f, 7.f));
    EXPECT_FLOAT_EQ(angle, 45.f);

    angle = utils::getAngle(sf::Vector2f(-2.f, -2.f), sf::Vector2f(1.f, 1.f));
    EXPECT_FLOAT_EQ(angle, 45.f);
};

TEST_F(getAngle, handlesEqualPositions){
    angle = utils::getAngle(sf::Vector2f(0, 0), sf::Vector2f(0, 0));
    EXPECT_FLOAT_EQ(angle, 0.f);

    angle = utils::getAngle(sf::Vector2f(13.f, -11.908), sf::Vector2f(13.f, -11.908));
    EXPECT_FLOAT_EQ(angle, 0.f);
};


