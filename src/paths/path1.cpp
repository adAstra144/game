#include "paths/path1.hpp"

#include <iostream>

#include "paths/path0.hpp"
#include "enemy/kingGoblin.hpp"
#include "combat.hpp" 
#include "devTools.hpp"

// King Goblin Path
void path1 (gameState *g) {
    std::cout << "Current Path: 1" << std::endl;
    int move1;

    while (1) {
        std::cout << "[1] Continue To Path 1-2?" << std::endl;
        std::cout << "[2] Turn Back" << std::endl;
        std::cout << "Next Move: ";
        std::cin >> move1;

        if (move1 == 1) {
            clear();
            std::cout << "*" << g->p.name << " Continues" << std::endl; 
            path1_2(g);
            break;
        } else if (move1 == 2) {
            clear();
            std::cout << "*" << g->p.name << " Turn's Back" << std::endl;
            path0(g);
        } else if (std::cin.fail()) {
            validnum();
        } else {
            std::cout << "Invalid Number";
        }
    }
}

void path1_2 (gameState *g) {
    cinignore();

    kingGoblin kingGoblin;

    std::cout << "Current Path: 1-2" << std::endl;

    std::cout << "< " << g->p.name << " >" << std::endl;
    std::cout << "Something doesn't feel right" << std::endl;
    contin();

    std::cout << "< " << g->p.name << " >" << std::endl;
    std::cout << "! ! !" << std::endl;
    contin();

    horizontalBrokenLines();
    std::cout << "King Goblin Has Appeared!" << std::endl;
    horizontalBrokenLines();
    contin();
    
    int result = turnBasedCombat(g, &kingGoblin);

    if (result == 0) {
        // Add Path1_3 Here
        // What's Next After King Goblin?
        std::cout << "You Won" << std::endl; 
    } else if (result == 2) {
        // If Succesfully Ran Away
        clear();
        std::cout << "Back at the start. . ." << std::endl;
        path0(g);
    }
}