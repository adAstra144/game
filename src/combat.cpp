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

    message(messageType::SYS, {"Combat start!"});
    contin();

    // Determine who goes first based on speed stat
    if (g->p.getSpeed() > e->getSpeed()) {   
        // Player Start
        cv.turn = 0;
        message(messageType::SYS, {g->p.name, "Starts first"});
    } else {   
        // Enemy Start
        cv.turn = 1;
        message(messageType::SYS, {e->name, "Starts first"});
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
                message(messageType::SYS, {"You win!"});
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
            
            // TODO: Consider doing the same with this with what your planning for the player (clear -> print top UI -> print action)
            horizontalBrokenLines();
            message(messageType::ACTION, {e->name,"Attacks!"});
            horizontalBrokenLines();

            e->specialMove(cv.enemyTurnCount);

            g->p.takeDamage(e->getAtk());
            std::cout << g->p.name << "\'s HP: " << cv.playerHpBeforeAttack << " -> " << g->p.getHp() << std::endl;
            horizontalBrokenLines();

            if (g->p.getDefend() == true) {
                contin();
                horizontalBrokenLines();
                message(messageType::ACTION, {g->p.name, "Defended | Reduced damage taken"});
                horizontalBrokenLines();
            }

            if (g->p.getHp() <= 0) {
                contin();
                clear();
                horizontalBrokenLines();
                message(messageType::SYS, {"You died!"});
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

        voidPrompt();
        std::cin >> combatDecision;

        if (combatDecision == 1) { 
            e->takeDamage(g->p.getAtk());
            
            horizontalBrokenLines();
            message(messageType::ACTION, {g->p.name, "Attacks!"});
            horizontalBrokenLines();
            std::cout << e->name << " HP: " << cv->enemyHpBeforeAttack << " -> " << e->getHp() << std::endl;
            horizontalBrokenLines();
            
            break;
        } else if (combatDecision == 2) {
            g->p.setDefend(true);

            horizontalBrokenLines();
            message(messageType::ACTION, {g->p.name, "Defends!"});
            horizontalBrokenLines();

            break;
        } else if (combatDecision == 3) {
            cinignore();
            std::cin.clear();

            dialouge(g->p.name, "Time to run!", false);
            contin();

            if (g->p.getSpeed() > e->getSpeed()) {
                horizontalBrokenLines();
                message(messageType::ACTION, {g->p.name, "Successfully ran away"});
                horizontalBrokenLines();
                contin();

                g->p.setHp(cv->playerStartingHp);

                return 2; 
            } else {
                horizontalBrokenLines();
                message(messageType::ACTION, {g->p.name, "Failed to run away"});
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
            message(messageType::ERROR, {"Invalid number"});
        }
    }
    return -1;
}

void playerStats (gameState *g) {
    clear();
    std::cout << g->p.name << " Stats" << std::endl;
    std::cout << "Stats:    | Level:" << std::endl;
    std::cout << "HP:" << textSpacerHp(g->p.getHp()) << g->p.getHp() << " | " << g->p.getLvlHp() << std::endl;
    std::cout << "ATK:" << textSpacerAtk(g->p.getAtk()) << g->p.getAtk() << " | " << g->p.getLvlAtk() << std::endl;
    std::cout << "SPD:" << textSpacerSpeed(g->p.getSpeed()) << g->p.getSpeed() << " | " << g->p.getLvlSpeed() << std::endl;
    std::cout << "GOLD: " << g->p.getGold() << std::endl;

    cinignore();
    contin();
    clear();
}

void enemyStats (enemy *e) {
    clear();
    std::cout << e->name << " Stats" << std::endl;
    std::cout << "HP:" << textSpacerHp(e->getHp()) << e->getHp() << std::endl;
    std::cout << "ATK:" << textSpacerAtk(e->getAtk()) << e->getAtk() << std::endl;
    std::cout << "SPD:" << textSpacerSpeed(e->getSpeed()) << e->getSpeed() << std::endl;
    std::cout << "GOLD: " << e->getGold() << std::endl;

    cinignore();
    contin();
    clear();
}

void respawn (gameState *g) {
    while (1) {
        int respawnDecision;
        message(messageType::INPUT, {"Respawn :"});    
        yn();
        std::cin >> respawnDecision;

        if (respawnDecision == 1) {
            resetPlayerStats(g);
            resetGame(g);
            clear();
            message(messageType::NARRATE, {"Here we go again..."});
            path0(g);
            break;
        } else if (respawnDecision == 2) {
            message(messageType::SYS, {"Goodbye!"});
            
            break;
        } else if (std::cin.fail()) {
            validnum();
        } else {
            message(messageType::ERROR, {"Invalid number"});
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