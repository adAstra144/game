#include "combat.h"

int turnBasedCombat (gameState *g, enemy *e) // Main Combat Mechanics (Basic Turn Based)
{
    int turn; // Determine who starts first

    if (g->p.getSpeed() > e->getSpeed())
    {
        turn = 0;
        std::cout << "Player Start" << std::endl;
    }
    else 
    {
        turn = 1;
        std::cout << "Enemy Start" << std::endl;
    }
    contin();

    int playerStartingHp = g->p.getHp(); // Stores in HP before the fight begins
    int enemyStartingHp = e->getHp(); // Used for determining max hp and restoring hp after combat 

    int playerTurnCount = 0;
    int enemyTurnCount = 0;

    while (1)
    {
        if (turn == 0)
        {
            playerTurnCount++;
            std::cout << g->p.name << "\'s Turn" << " | " << playerTurnCount << std::endl;

            g->p.setDefend(false); // Resets Defending to false 
            int decision = playerCombatOptions(g, e, playerStartingHp); 

            if (decision == 2) // If Successfully Ran Away. Return To 2 Caller. 
            {
                return 2;
            }

            if (e->getHp() <= 0)
            {
                cinignore();
                contin();
                std::cout << "You Win!" << std::endl;
                
                g->p.setHp(playerStartingHp); // Restore HP

                contin();

                g->p.gainGold(e->getGold()); // Receive Enemies Gold
                std::cout << "Received Gold: " << e->getGold() << std::endl;

                contin();

                return 0; // Returns 0 If The Player Won
            }
            if (decision != 3)
            {
                cinignore();
            }
            contin();


            turn = 1;
        }
        else if (turn == 1)
        {
            enemyTurnCount++;
            std::cout << e->name << "\'s Turn" << " | " << enemyTurnCount << std::endl;
            std::cout << e->name << "\'s HP: " << e->getHp() << " / " << enemyStartingHp << std::endl; // Display Enemy HP
            std::cout << e->name << " Attacks!" << std::endl;

            e->specialMove(enemyTurnCount);

            g->p.takeDamage(e->getAtk());

            if (g->p.getDefend() == true)
            {
                contin();
                std::cout << g->p.name << " Defended, Reduced Damage Taken" << std::endl;
            }

            if (g->p.getHp() <= 0)
            {
                std::cout << "You Died!" << std::endl;
                respawn(g);
                return 1; // Returns 1 If Player Lost
            }
            contin();
            
            turn = 0;
        }
    }

    return -1; // Fail Safe (Claude Suggested)
}

// Players Options during Combat
int playerCombatOptions (gameState *g, enemy *e, int playerStartingHp)
{
    int combatDecision;

    while (1)
    {
        std::cout << g->p.name << "\'s HP: " << g->p.getHp() << " / " << playerStartingHp << std::endl; // Display Player HP
        std::cout << "[1] Attack" << std::endl;
        std::cout << "[2] Defend" << std::endl;
        std::cout << "[3] Try To Run" << std::endl;
        std::cout << "[4] Show Player Stats" << std::endl;
        std::cout << "[5] Show Enemy Stats" << std::endl; 

        std::cout << "Next Move: ";
        std::cin >> combatDecision;

        if (combatDecision == 1) // Attack
        {
            e->takeDamage(g->p.getAtk());
            std::cout << g->p.name << " Attacks!" << std::endl;
            break;
        }
        else if (combatDecision == 2) // Defend
        {
            g->p.setDefend(true);
            std::cout << g->p.name << " Defends!" << std::endl;
            break;
        }
        else if (combatDecision == 3) // Run
        {
            cinignore();
            std::cin.clear();

            contin();
            std::cout << "< " << g->p.name << " >" << std::endl;
            std::cout << "Time to run!" << std::endl;

            if (g->p.getSpeed() > e->getSpeed())
            {
                contin();
                std::cout << " Succesfully Ran Away" << std::endl;
                contin();

                g->p.setHp(playerStartingHp);

                return 2; 
            }
            else
            {
                contin();
                std::cout << g->p.name << " Failed To Run away" << std::endl;
                return 3;
            }
        }
        else if (combatDecision == 4) // Player Stats
        {
            playerStats(g);
        }
        else if (combatDecision == 5) // Enemy Stats
        {
            enemyStats(e);
        }
        else if (std::cin.fail())
        {
            validnum();
        }
        else
        {
            std::cout << "Invalid Number" << std::endl;
        }
    }

    return -1;
}

// Handles Player Respawns
void respawn (gameState *g)
{
    while (1)
    {
        int respawnDecision;
        std::cout << "Respawn?: " << std::endl;
        
        yn();
        std::cin >> respawnDecision;

        if (respawnDecision == 1)
        {
            resetPlayerStats(g);
            resetGame(g);
            std::cout << "Here we go again. . ." << std::endl;
            path0(g);
            break;
        }
        else if (respawnDecision == 2)
        {
            std::cout << "Goobye!" << std::endl;
            break;
        }
        else if (std::cin.fail())
        {
            validnum();
        }
        else
        {
            std::cout << "Invalid Number" << std::endl;
        }
    }
}