#pragma once

#include "enemy/Enemy.hpp"

class Skeleton : public Enemy {
    public:
        Skeleton();
    
        void resetStats ();
};