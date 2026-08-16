#include "paths/path1.hpp"

#include <iostream>

#include "paths/path0.hpp"
#include "enemy/kingGoblin.hpp"
#include "combat.hpp" 
#include "devTools.hpp"

// King Goblin Path
void path1 (gameState *g) {
    std::cout << "Current Path: 1" << std::endl;

    std::cout << "# As you wander around you encounter a sign saying \"Danger ahead\"" << std::endl;    

    int move1;
    while (1) {
        std::cout << "[1] Continue To Path 1-2?" << std::endl;
        std::cout << "[2] Turn Back" << std::endl;
        std::cout << "? Next Move :" << std::endl;
        voidPrompt();
        std::cin >> move1;

        cinignore();
        if (move1 == 1) {
            clear();
            std::cout << "* " << g->p.name << " Ignores the sign" << std::endl; 
            contin();
            clear();
            path1_2(g);
            break;
        } else if (move1 == 2) {
            clear();
            std::cout << "* " << g->p.name << " Trusts the sign" << std::endl;
            contin();

            clear();
            path0(g);
        } else if (std::cin.fail()) {
            validnum();
        } else {
            std::cout << "! Invalid Number";
        }
    }
}

void path1_2 (gameState *g) {

    kingGoblin kingGoblin;

    std::cout << "~ Current Path: 1-2" << std::endl;

    dialouge(g->p.name, "Someting doesn't feel right", true);

    dialouge(g->p.name, "! ! !", true);

    horizontalBrokenLines();
    std::cout << "# King Goblin Has Appeared!" << std::endl;
    horizontalBrokenLines();
    contin();
    
    int result = turnBasedCombat(g, &kingGoblin);

    if (result == 0) {
        // TODO: Add Path1_3 Here
        // TODO: What's Next After King Goblin?
        std::cout << "You Won" << std::endl; 
    } else if (result == 2) {
        clear();
        std::cout << "Back at the start..." << std::endl;
        path0(g);
    }
}