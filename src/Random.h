#ifndef ANTSIMULATION_RANDOM_H
#define ANTSIMULATION_RANDOM_H

#include <random>

class Random {
public:

    static float getRandomAngle();

    static float getRandom(float min, float max);

private:
    static std::default_random_engine randomEngine;
};


#endif //ANTSIMULATION_RANDOM_H
