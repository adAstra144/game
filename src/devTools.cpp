#include "devTools.h"

// Error Tools
void validnum (void) // Fixes cin(input) if it's supposed to be a number
{   
    std::cin.clear();
    cinignore();
    
    horizontalBrokenLines();
    std::cout << "Not a number please try again" << std::endl;
    horizontalBrokenLines();
}
void cinignore (void)
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Option Tools
void yn (void)
{
    std::cout << "[1] Yes" << std::endl;
    std::cout << "[2] No" << std::endl;
    std::cout << "Next Move: ";
}

int accept (void) // Return 1 If Accept. 2 If Decline
{
    while (1)
    {
        int decision;
        std::cout << "[1] Accept" << std::endl;
        std::cout << "[2] Decline" << std::endl;

        std::cout << "Next Move: ";
        std::cin >> decision;

        if (decision == 1)
        {
            return 1;
        }
        else if (decision == 2)
        {
            return 0;
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

// Design Tools
void space (void) // Create 1 line space
{
    std::cout << "\n";
}

void contin (void) // Continue dialouge 
{
    std::cout << "->";
    getchar();
}

std::string textSpacerHp (int amount)
{
    if (amount >= 100)
    {
        return "   ";
    }
    else
    {
        return "    ";
    }
}

std::string textSpacerAtk (int amount)
{
    if (amount >= 100)
    {
        return "  ";
    }
    else
    {
        return "   ";
    }
}

std::string textSpacerSpeed (int amount)
{
    if (amount >= 100)
    {
        return "  ";
    }
    else
    {
        return "   ";
    }
}

void horizontalBrokenLines ()
{
    std::cout << "- - - - - - - - - -" << std::endl;
}