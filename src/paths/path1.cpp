#include "paths/path1.hpp"

#include <iostream>

#include "paths/path0.hpp"
#include "enemy/KingGoblin.hpp"
#include "combat.hpp"
#include "devTools.hpp"

//* King Goblin Path
void path1 (GameState *g) {
    std::cout << "Current Path: 1" << std::endl;

    message(MessageType::NARRATE, {"As you wander around you encounter a sign saying \"Danger ahead\""});

    int move1;
    while (1) {
        std::cout << "[1] Continue To Path 1-2" << std::endl;
        std::cout << "[2] Turn Back" << std::endl;
        message(MessageType::INPUT, {"Next Move :"});
        voidPrompt();
        std::cin >> move1;

        cinIgnore();
        if (move1 == 1) {
            clear();
            message(MessageType::ACTION, {g->p.name, "Ignores the sign"});
            contin();
            clear();
            path1_2(g);
            break;
        } else if (move1 == 2) {
            clear();
            message(MessageType::ACTION, {g->p.name, "Trusts the sign"});
            contin();

            clear();
            path0(g);
        } else if (std::cin.fail()) {
            validNum();
        } else {
            message(MessageType::ERROR, {"Invalid number"});
        }
    }
}

void path1_2 (GameState *g) {

    KingGoblin kingGoblin;

    std::cout << "~ Current Path: 1-2" << std::endl;

    dialouge(g->p.name, "Someting doesn't feel right", true);

    dialouge(g->p.name, "! ! !", true);

    horizontalBrokenLines();
    message(MessageType::NARRATE, {"King Goblin has appeared!"});
    horizontalBrokenLines();
    contin();

    CombatResult result = turnBasedCombat(g, &kingGoblin);

    if (result == CombatResult::WON) {
        // TODO: Add Path1_3 Here
        // TODO: What's Next After King Goblin?
        std::cout << "Path 1-3?" << std::endl;
    } else if (result == CombatResult::RAN_AWAY) {
        clear();
        message(MessageType::NARRATE, {"Back at the start..."});
        path0(g);
    }
}
