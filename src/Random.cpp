#include <ctime>

#include "Random.h"

std::default_random_engine Random::randomEngine(std::time(0));

float Random::getRandomAngle() {
    std::uniform_real_distribution<float> distribution(0.0f, 360.0f);
    return distribution(Random::randomEngine);
}