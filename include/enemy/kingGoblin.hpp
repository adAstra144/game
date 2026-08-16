#pragma once

#include "enemy/enemy.hpp"

class kingGoblin : public enemy {
    public:
        kingGoblin();

        void specialMove(int turnCount) override;
};