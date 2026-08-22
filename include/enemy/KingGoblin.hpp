#pragma once

#include "enemy/Enemy.hpp"

class KingGoblin : public Enemy {
    public:
        KingGoblin();

        void specialMove(int turnCount) override;
};