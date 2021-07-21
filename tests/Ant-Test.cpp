#include <gtest/gtest.h>

#include "Ant.h"

TEST(Ant, Constructor){
    float X{3},Y{5.5},Dir{3.6};

    Ant ant(X, Y, Dir);

    Ant ant2;
}

