#pragma once

#include <iostream>
#include "enemy/enemy.hpp"
#include "../devTools.hpp"

class kingGoblin : public enemy {
    public:
        kingGoblin();

        void specialMove(int turnCount) override;
};