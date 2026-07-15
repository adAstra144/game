#include <iostream>
#include <string>
#include <limits>
#include <cstdio>

struct player 
{
    std::string name;
    int hp;
    int atk;
    int defend;
    int speed;
    int gold;
};

struct enemy 
{
    std::string name;
    int hp;
    int atk;
    int speed;
    int gold;
};


// Functions

// Paths 1
void path0(player *p);
void path1(player *p);
void path2(player *p);
void path3(player *p);

// Paths 2
void path1_2(player *p);


// Combat 
int turnBasedCombat (player *p, enemy *e);
void playerCombatOptions (player *p, enemy *e, int playerStartingHp);


// Player Tools
void playerStats (player *p);
void enemyStats (enemy *e);

// Dev Tools
void validnum (void);
void yn (void);
void respawn (player *p);
void resetPlayerStats (player *p);
int accept (void);
void space (void);
void contin (void);
void cinignore (void);


int main ()
{
    int menuOptions;
    
    std::cout << "Welcome to Astra's short game" << std::endl;
    std::cout << "Type the respective number of the decision you want to make" << std::endl;

    while (1)
    {

        std::cout << "[1] Start Game" << std::endl;
        std::cout << "[2] Exit" << std::endl;
        std::cout << "Next Move: ";
        std::cin >> menuOptions;

        if (menuOptions == 1)
        {
            std::cout << "Starting game. . . " << std::endl;

            player p; // Starting Player Stats
            p.hp = 100;
            p.atk = 10;
            p.speed = 10;
            p.gold = 0;

            std::cout << "Enter player name: ";
            std::cin >> p.name;

            std::cout << "Presented before you are 3 paths" << std::endl;

            path0(&p);

            break;
        }
        else if (menuOptions == 2)
        {
            std::cout << "Goodbye!" << std::endl;
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

// - - - - - - - - - - Paths - - - - - - - - - -
void path0 (player *p) // Root path 
{
    while (1)
    {
        int move1;
        std::cout << "[1] Enter Path 1" << std::endl;
        std::cout << "[2] Enter Path 2" << std::endl;
        std::cout << "[3] Enter Path 3" << std::endl;
        
        std::cout << "Next Move: ";
        std::cin >> move1;

        if (move1 == 1)
        {
            std::cout << "* " << p->name << " Enter's path 1" << std::endl;
            std::cout << "# As you wander around you encounter a sign saying \"Danger ahead\"" << std::endl;      

            path1(p);
            break;
        }
        else if (move1 == 2)
        {
            path2(p);
            break;
        }
        else if (move1 == 3)
        {
            path3(p);
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

void path1 (player *p) // Pre King Goblin Path
{
    int move1;

    while (1)
    {
        std::cout << "[1] Continue Path 1" << std::endl;
        std::cout << "[2] Turn Back" << std::endl;
        std::cout << "Next Move: ";
        std::cin >> move1;

        if (move1 == 1)
        {
            std::cout << "*" << p->name << " Continues" << std::endl; 
            path1_2(p);
            break;
        }
        else if (move1 == 2)
        {
            std::cout << "*" << p->name << " Turn's Back" << std::endl;
            path0(p);
        }
        else if (std::cin.fail())
        {
            validnum();
        }
        else 
        {
            std::cout << "Invalid Number";
        }
    }
}

void path2 (player *p) // Wizard Path (Increase ? Stat)
{
    cinignore();

    std::cout << "- - - - - Dialouge Start - - - - -" << std::endl;

    std::cout << "< ??? >" << std::endl;
    std::cout << "What brings thee in this parts?" << std::endl;
    contin();
    std::cout << "< " << p->name << " >" << std::endl;
    std::cout << "Who are you?" << std::endl;
    contin();
    std::cout << "< Wizard >" << std::endl;
    std::cout << "I am but a humble wizard" << std::endl;
    contin();
    std::cout << "< " << p->name << " >" << std::endl;
    std::cout << "What is a wizard doing here?" << std::endl;
    contin();
    std::cout << "< Wizard >" << std::endl;
    std::cout << "You need not know of it" << std::endl;
    std::cout << "Instead I can offer some services if you do me a favor" << std::endl;
    contin();
    std::cout << "< " << p->name << " >" << std::endl;
    std::cout << "What favor?" << std::endl;
    contin();
    std::cout << "< Wizard >" << std::endl;
    std::cout << "In the room the next of this one" << std::endl;
    std::cout << "There's a pesky skeleton ruining my garden" << std::endl;
    std::cout << "Kill it in exchange for a reward" << std::endl;
    contin();
    std::cout << "< " << p->name << " >" << std::endl;
    int move1 = accept();
    space();

    if (move1 == 1)
    {
        std::cout << "< Wizard >" << std::endl;
        std::cout << "I knew I could count on you!" << std::endl;
        contin();

        // Continue Path 2_2 Here
    }
    else if (move1 == 0)
    {
        std::cout << "< Wizard >" << std::endl;
        std::cout << "Eh? Your loss then" << std::endl;
        std::cout << "Come to me again if you ever change your mind" << std::endl;
        contin();

        // 3 Options : 1. Talk to wizard (Shortened ex. "Want to take the offer now?") 2. Return to parent path 3. Continue path2_2
        
        std::cout << "- - - - - Dialouge End - - - - -" << std::endl;
        
        space();
        
        int move2;
        
        std::cout << "[1] Continue to next room " << std::endl;
        std::cout << "[2] Talk to Wizard" << std::endl;
        std::cout << "[3] Go back" << std::endl;
        
        std::cout << "Next Move: ";
        std::cin >> move2;
        
        if (move2 == 1)
        {
            std::cout << "Entering next room. . ." << std::endl;
         }
         else if (move2 == 2)
         {
             std::cout << "Approaching the Wizard. . ." << std::endl;   
         }
         else if (move2 == 3)
         {
             std::cout << "Here we are again. . ." << std::endl;
             path0(p);
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

void path3 (player *p)
{
    std::cout << "Welcome to path 3" << std::endl;
}


// - - - - - - - - - - Paths 2 - - - - - - - - - -
void path1_2(player *p) // King Goblin Path
{
    enemy kingGoblin;
    kingGoblin.name = "King Goblin";
    kingGoblin.hp = 200;
    kingGoblin.atk = 50;
    kingGoblin.speed = 5;
    kingGoblin.gold = 200;

    std::cout << "King Goblin Has Appeared!" << std::endl;
    
    int result = turnBasedCombat(p, &kingGoblin);

    if (result == 0) // Add Path1_3 Here
    {
        std::cout << "You Won" << std::endl; // What's Next After King Goblin?
    }

}


// - - - - - - - - - - Combat System - - - - - - - - - -
int turnBasedCombat (player *p, enemy *e) // Main Combat Mechanics (Basic Turn Based)
{
    int turn; // Determine who starts first

    if (p->speed > e->speed)
    {
        turn = 0;
        std::cout << "Player Start" << std::endl;
    }
    else 
    {
        turn = 1;
        std::cout << "Enemy Start" << std::endl;
    }

    int playerStartingHp = p->hp; // Stores in HP before the fight begins
    int enemyStartingHp = e->hp; // Used for determining max hp and restoring hp after combat 

    while (1)
    {
        if (turn == 0)
        {
            std::cout << p->name << "\'s Turn" << std::endl;

            p->defend = 0; // Resets Defending to false 
            playerCombatOptions(p, e, playerStartingHp);

            if (e->hp <= 0)
            {
                std::cout << "You Win!" << std::endl;
                
                p->hp = playerStartingHp; // Restore HP

                p->gold = p->gold + e->gold; // Receive Enemies Gold
                std::cout << "Received Gold: " << e->gold << std::endl;

                return 0;
            }
            cinignore();
            contin();

            turn = 1;
        }
        else if (turn == 1)
        {
            std::cout << e->name << "\'s Turn" << std::endl;
            std::cout << e->name << "\'s HP: " << e->hp << " / " << enemyStartingHp << std::endl; // Display Enemy HP
            std::cout << e->name << " Attacks!" << std::endl;

            if (p->defend == 1) // If defending reduce enemy attack
            {
                contin();
                p->hp = p->hp - (e->atk / 2);
                std::cout << p->name << " Defended, Reduced Damage Taken" << std::endl;
            }
            else
            {
                p->hp = p->hp - e->atk; // Normal Attack
            }

            if (p->hp <= 0)
            {
                std::cout << "You Died!" << std::endl;
                respawn(p);
                return 1;
            }
            contin();
            
            turn = 0;
        }
    }

    return -1; // Fail Safe (Claude Suggested)
}

// Players Options during Combat
void playerCombatOptions (player *p, enemy *e, int playerStartingHp)
{
    int combatDecision;

    while (1)
    {
        std::cout << p->name << "\'s HP: " << p->hp << " / " << playerStartingHp << std::endl; // Display Player HP
        std::cout << "[1] Attack" << std::endl;
        std::cout << "[2] Defend" << std::endl;
        std::cout << "[3] Try To Run" << std::endl;
        std::cout << "[4] Show Player Stats" << std::endl;
        std::cout << "[5] Show Enemy Stats" << std::endl; 

        std::cout << "Next Move: ";
        std::cin >> combatDecision;

        if (combatDecision == 1)
        {
            e->hp = e->hp - p->atk;
            std::cout << p->name << " Attacks!" << std::endl;
            break;
        }
        else if (combatDecision == 2)
        {
            p->defend = 1;
            std::cout << p->name << " Defends!" << std::endl;
            break;
        }
        else if (combatDecision == 3)
        {
            if (p->speed > e->speed)
            {
                std::cout << " Succesfully Ran Away" << std::endl;
                std::cout << "You are now back at the start" << std::endl;
                p->hp = playerStartingHp;
                path0(p);
                break;
            }
            else
            {
                std::cout << p->name << " Failed To Run away" << std::endl;
                break;
            }
        }
        else if (combatDecision == 4)
        {
            playerStats(p);
        }
        else if (combatDecision == 5)
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
}

// - - - - - - - - - - Player Tools - - - - - - - - - -
void playerStats (player *p)
{
    std::cout << p->name << "\'s Stats:" << std::endl;
    std::cout << "HP: " << p->hp << std::endl;
    std::cout << "ATK: " << p->atk << std::endl;
    std::cout << "SPEED: " << p->speed << std::endl;
    std::cout << "GOLD: " << p->gold << std::endl;

    cinignore();
    std::cout << "Press Enter To Exit. . .";
    getchar();
}

void enemyStats (enemy *e)
{
    std::cout << e->name << "\'s Stats:" << std::endl;
    std::cout << "HP: " << e->hp << std::endl;
    std::cout << "ATK: " << e->atk << std::endl;
    std::cout << "SPEED: " << e->speed << std::endl;
    std::cout << "GOLD: " << e->gold << std::endl;

    cinignore();
    std::cout << "Press Enter To Exit. . .";
    getchar();
}


// - - - - - - - - - - Dev Tools - - - - - - - - - -
void validnum (void) // Fixes cin(input) if it's supposed to be a number
{   
    std::cin.clear();
    cinignore();
    std::cout << "Not a number please try again" << std::endl;
}

void yn (void)
{
    std::cout << "[1] Yes" << std::endl;
    std::cout << "[2] No" << std::endl;
    std::cout << "Next Move: ";
}

void respawn (player *p)
{
    while (1)
    {
        int respawnDecision;
        std::cout << "Respawn?: " << std::endl;
        
        yn();
        std::cin >> respawnDecision;

        if (respawnDecision == 1)
        {
            resetPlayerStats(p);
            std::cout << "Here we go again. . ." << std::endl;
            path0(p);
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

void resetPlayerStats (player *p)
{
    p->hp = 100;
    p->atk = 10;
    p->speed = 10;
    p->gold = 0;
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

void space (void) // Create 1 line space
{
    std::cout << "\n";
}

void contin (void) // Continue dialouge 
{
    std::cout << "->";
    getchar();
}

void cinignore (void)
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}