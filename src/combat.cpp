#include "combat.hpp"

#include <iostream>

#include "paths/path0.hpp"
#include "player/playerTools.hpp"
#include "devTools.hpp"

// Main Combat Mechanic
int turnBasedCombat (gameState *g, enemy *e) {
    clear();

    combatVariables cv;

    cv.turn = 0;

    cv.playerStartingHp = g->p.getHp(); 
    cv.enemyStartingHp = e->getHp(); 

    cv.playerTurnCount = 0;
    cv.enemyTurnCount = 0;

    std::cout << "Combat Start!" << std::endl;
    contin();

    // Determine who goes first based on speed stat
    if (g->p.getSpeed() > e->getSpeed()) {   
        // Player Start
        cv.turn = 0;
        std::cout << g->p.name << " Starts First" << std::endl;
    } else {   
        // Enemy Start
        cv.turn = 1;
        std::cout << e->name << " Starts First" << std::endl;
    }
    contin();

    // Main combat loop
    while (1) {
        if (cv.turn == 0) {
            clear();

            cv.enemyHpBeforeAttack = e->getHp();

            cv.playerTurnCount++;
            std::cout << g->p.name << "\'s Turn" << " | " << cv.playerTurnCount << std::endl;

            g->p.setDefend(false); // Resets Defending to false 
            int decision = playerCombatOptions(g, e, &cv); 

            // If Successfully Ran Away. Return To 2 Caller. 
            if (decision == 2) { 
                return 2;
            }

            if (e->getHp() <= 0) {
                cinignore();
                contin();
                clear();
                
                g->p.setHp(cv.playerStartingHp);

                g->p.gainGold(e->getGold());

                horizontalBrokenLines();
                std::cout << "You Win!" << std::endl;
                horizontalBrokenLines();
                std::cout << "Received Gold: " << e->getGold() << std::endl;
                std::cout << "Current Gold: " << g->p.getGold() << std::endl;
                horizontalBrokenLines();

                contin();

                clear();

                return 0; // Returns 0 If The Player Won
            }
            
            if (decision != 3) {
                cinignore();
            }
            contin();


            cv.turn = 1;
        } else if (cv.turn == 1) {
            clear();

            cv.playerHpBeforeAttack = g->p.getHp();

            cv.enemyTurnCount++;
            std::cout << e->name << "\'s Turn" << " | " << cv.enemyTurnCount << std::endl;
            std::cout << e->name << "\'s HP: " << e->getHp() << " / " << cv.enemyStartingHp << std::endl;
            
            delayDots(3, 0, 400, true);

            horizontalBrokenLines();
            std::cout << e->name << " Attacks!" << std::endl;
            horizontalBrokenLines();

            e->specialMove(cv.enemyTurnCount);

            g->p.takeDamage(e->getAtk());
            std::cout << g->p.name << "\'s HP: " << cv.playerHpBeforeAttack << " -> " << g->p.getHp() << std::endl;
            horizontalBrokenLines();

            if (g->p.getDefend() == true) {
                contin();
                horizontalBrokenLines();
                std::cout << g->p.name << " Defended, Reduced Damage Taken" << std::endl;
                horizontalBrokenLines();
            }

            if (g->p.getHp() <= 0) {
                contin();
                clear();
                horizontalBrokenLines();
                std::cout << "You Died!" << std::endl;
                horizontalBrokenLines();

                respawn(g);
                return 1; 
            }
            contin();
            
            cv.turn = 0;
        }
    }
    return -1;
}

// Players Options during Combat
int playerCombatOptions (gameState *g, enemy *e, combatVariables *cv) {
    int combatDecision;

    while (1) {
        std::cout << g->p.name << "\'s HP: " << g->p.getHp() << " / " << cv->playerStartingHp << std::endl; // Display Player HP
        std::cout << "[1] Attack" << std::endl;
        std::cout << "[2] Defend" << std::endl;
        std::cout << "[3] Try To Run" << std::endl;
        std::cout << "[4] Show Player Stats" << std::endl;
        std::cout << "[5] Show Enemy Stats" << std::endl; 

        std::cout << "Next Move: ";
        std::cin >> combatDecision;

        if (combatDecision == 1) { 
            e->takeDamage(g->p.getAtk());
            
            horizontalBrokenLines();
            std::cout << g->p.name << " Attacks!" << std::endl;
            horizontalBrokenLines();
            std::cout << e->name << " HP: " << cv->enemyHpBeforeAttack << " -> " << e->getHp() << std::endl;
            horizontalBrokenLines();
            
            break;
        } else if (combatDecision == 2) {
            g->p.setDefend(true);

            horizontalBrokenLines();
            std::cout << g->p.name << " Defends!" << std::endl;
            horizontalBrokenLines();

            break;
        } else if (combatDecision == 3) {
            cinignore();
            std::cin.clear();

            std::cout << "< " << g->p.name << " >" << std::endl;
            std::cout << "Time to run!" << std::endl;

            if (g->p.getSpeed() > e->getSpeed()) {
                contin();
                horizontalBrokenLines();
                std::cout << " Succesfully Ran Away" << std::endl;
                horizontalBrokenLines();
                contin();

                g->p.setHp(cv->playerStartingHp);

                return 2; 
            } else {
                contin();
                horizontalBrokenLines();
                std::cout << g->p.name << " Failed To Run away" << std::endl;
                horizontalBrokenLines();

                return 3;
            }
        } else if (combatDecision == 4) {
            playerStats(g);
        } else if (combatDecision == 5) {
            enemyStats(e);
        } else if (std::cin.fail()) {
            validnum();
        } else {
            std::cout << "Invalid Number" << std::endl;
        }
    }
    return -1;
}

void respawn (gameState *g) {
    while (1) {
        int respawnDecision;
        std::cout << "Respawn?: " << std::endl;
        
        yn();
        std::cin >> respawnDecision;

        if (respawnDecision == 1) {
            resetPlayerStats(g);
            resetGame(g);
            clear();
            std::cout << "Here we go again. . ." << std::endl;
            path0(g);
            break;
        } else if (respawnDecision == 2) {
            std::cout << "Goobye!" << std::endl;
            
            break;
        } else if (std::cin.fail()) {
            validnum();
        } else {
            std::cout << "Invalid Number" << std::endl;
        }
    }
}

// TODO: Change this ---
// void topCombatUI (gameState *g, enemy *e, int enemyTurnCount, int enemyStartingHp) {
//     if (true) {
//         std::cout << g->p.name << "\'s Turn" << " | " << enemyTurnCount << std::endl;
//         std::cout << g->p.name << "\'s HP: " << g->p.getHp() << " / " << enemyStartingHp << std::endl;
//     } else {
//         std::cout << e->name << "\'s Turn" << " | " << enemyTurnCount << std::endl;
//         std::cout << e->name << "\'s HP: " << e->getHp() << " / " << enemyStartingHp << std::endl;
//     }
// }