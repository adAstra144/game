#pragma once

#include <iostream>
#include "enemy.h"
#include "devTools.h"

class kingGoblin : public enemy
{
    public:
        kingGoblin();

        void specialMove(int turnCount) override;
};