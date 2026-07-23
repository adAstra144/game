#include "paths/path0.h"

void path0 (gameState *g) // Root path 
{
    while (1)
    {
        std::cout << "Current Path: 0" << std::endl;
        int move1;
        std::cout << "[1] Enter Path 1" << std::endl;
        std::cout << "[2] Enter Path 2" << std::endl;
        std::cout << "[3] Enter Path 3" << std::endl;
        
        std::cout << "Next Move: ";
        std::cin >> move1;

        if (move1 == 1)
        {
            std::cout << "* " << g->p.name << " Enter's path 1" << std::endl;
            std::cout << "# As you wander around you encounter a sign saying \"Danger ahead\"" << std::endl;      

            path1(g);
            break;
        }
        else if (move1 == 2)
        {

            if (g->dialogue2 == true)
            {
                path2(g);
                break;
            }
            else if (g->dialogue2 == false)
            {
                path2(g);
                break;
            }
            else
            {
                std::cout << "Error" << std::endl;
                break;
            }

        }
        else if (move1 == 3)
        {
            path3(g);
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