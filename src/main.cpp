#include <iostream>
#include <string>
#include <limits>
#include <cstdio>


// Main Enemy Class
#include "enemy/enemy.h"

// Separate Enemy Classes / Unique Enemies With distinguishing Features
#include "enemy/kingGoblin.h"
#include "enemy/skeleton.h"


// Paths
// Root Path
#include "paths/path0.h"

// Paths 1
#include "paths/path1.h"

// Paths 2
#include "paths/path2.h"

// Paths 3
#include "paths/path3.h"


// Main Player Class
#include "player/player.h"


// Combat 
#include "combat.h"

// Dev Tools
#include "devTools.h"

// Includes Player Global Progression
#include "gameState.h"


int main ()
{

    // Game State
    gameState g;

    resetGame(&g); // Sets Gamestate Default Values

    int menuOptions;
    
    std::cout << "Welcome to Astra's short game" << std::endl;
    std::cout << "Type the respective number of the decision you want to make" << std::endl;

    while (1)
    {
        std::cout << "[1] Start Game" << std::endl;
        std::cout << "[2] Exit" << std::endl;
        std::cout << "Next Move: ";
        std::cin >> menuOptions;

        clear();

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
