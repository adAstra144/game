#include "enemy/KingGoblin.hpp"

#include <iostream>

#include "devTools.hpp"

KingGoblin::KingGoblin() : Enemy("King Goblin", 200, 50, 5, 200) {}

void KingGoblin::specialMove (int turnCount) {
    if (turnCount % 3 == 0) {
        hp += hp * 0.05;

        if (hp > 200) {
            hp = 200;
        }

        contin();
        std::cout << name << " Used Special Move: Heal" << std::endl;
        std::cout << name << " New HP: " << hp << " / 200" << std::endl;
    }
}
