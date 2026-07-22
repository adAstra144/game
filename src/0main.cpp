#include <iostream>
#include <string>
#include <limits>
#include <cstdio>

// Dev Tools
#include "devTools.h"

// Main Player Class
#include "player.h"

// Main Enemy Class
#include "enemy.h"

// Separate Enemy Classes / Unique Enemies With distinguishing Features
#include "kingGoblin.h"
#include "skeleton.h"

// Includes Player Global Progression
#include "gameState.h"

// Paths
// Root Path
#include "path0.h"

// Paths 1
#include "path1.h"

// Paths 2
#include "path2.h"

// Paths 3
#include "path3.h"

// Combat 
#include "combat.h"

int main ()
{

    // Game State
    gameState g;

    // Quests
    g.qWizard.active = false;
    g.qWizard.finished = false;


    // Dialogues
    g.dialogue2 = true;

    int menuOptions;
    
    std::cout << "Welcome to Astra's short game" << std::endl;
    std::cout << "Type the respective number of the decision you want to make" << std::endl;

    while (1)
    {
        std::cout << "[1] Start Game" << std::endl;
        std::cout << "[2] Exit" << std::endl;
        std::cout << "Next Move: ";
        std::cin >> menuOptions;

        if (menuOptions == 0) // Return To 1 After Development
        {
            std::cout << "Starting game. . . " << std::endl;
            
            std::cout << "Enter player name: ";
            std::string name;
            std::cin >> name;
            g.p.name = name;
            
            std::cout << "Presented before you are 3 paths" << std::endl;

            path0(&g);

            break;
        }
        else if (menuOptions == 2)
        {
            std::cout << "Goodbye!" << std::endl;
            break;
        } 
        else if (menuOptions == 1) // Quick Start. Defaulted Player Name To Astra (Remove After Development)
        {
            g.p.name = "Astra";       
            
            std::cout << "Presented before you are 3 paths" << std::endl;
            
            path0(&g);

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
