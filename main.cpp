#include <iostream>
#include <string>
#include <limits>
#include <cstdio>


// Structs

struct player 
{
    std::string name;
    int hp;
    int atk;
    int defend;
    int speed;
    int gold;
};

struct quest
{
    bool active;
    bool finished;
};

struct gameState
{
    // Player
    player p;    

    // Quests
    quest wizard;
    
    // Dialogues
    bool dialogue2;
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

// Paths
void path0 (gameState *g);

// Paths 1
void path1 (gameState *g);
void path1_2(gameState *g);

// Paths 2
void path2 (gameState *g);
void path2_2 (gameState *g);

// Paths 3
void path3 (gameState *g);


// Combat 
int turnBasedCombat (gameState *g, enemy *e);
int playerCombatOptions (gameState *g, enemy *e, int playerStartingHp);
void respawn (gameState *g);


// Player Tools
void playerStats (gameState *g);
void enemyStats (enemy *e);


// Dev Tools
void validnum (void);
void yn (void);
void resetPlayerStats (gameState *g);
void resetGame (gameState *g);
int accept (void);
void cinignore (void);


// Path Specific Options
void optionsPath2_2 (gameState *g);


// Design
void space (void);
void contin (void);



int main ()
{

    // Game State
    gameState g;

    // Player
    g.p.hp = 100; // Starting Player Stats
    g.p.atk = 10;
    g.p.speed = 10;
    g.p.gold = 0;


    // Quests
    g.wizard.active = false;
    g.wizard.finished = false;


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
            std::cin >> g.p.name;
            
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
            g.p.name = "Astra"; // Remove This In The Future        
            
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

// - - - - - - - - - - Paths - - - - - - - - - -
void path0 (gameState *g) // Root path 
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


// - - - - - - - - - - Paths 1 - - - - - - - - - -
void path1 (gameState *g) // Pre King Goblin Path
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
            std::cout << "*" << g->p.name << " Continues" << std::endl; 
            path1_2(g);
            break;
        }
        else if (move1 == 2)
        {
            std::cout << "*" << g->p.name << " Turn's Back" << std::endl;
            path0(g);
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

void path1_2 (gameState *g) // King Goblin Path
{
    enemy kingGoblin;
    kingGoblin.name = "King Goblin";
    kingGoblin.hp = 200;
    kingGoblin.atk = 50;
    kingGoblin.speed = 5;
    kingGoblin.gold = 200;

    std::cout << "King Goblin Has Appeared!" << std::endl;
    
    int result = turnBasedCombat(g, &kingGoblin);

    if (result == 0) // Add Path1_3 Here
    {
        std::cout << "You Won" << std::endl; // What's Next After King Goblin?
    }
    else if (result == 2) // If Succesfully Ran Away
    {
        std::cout << "Back at the start. . ." << std::endl;
        path0(g);
    }

}


// - - - - - - - - - - Paths 2 - - - - - - - - - -
void path2 (gameState *g) // Wizard Path (Increase ? Stat)
{   
    if (g->dialogue2 == true) // With Dialogue
    {
        cinignore();

        std::cout << "< ??? >" << std::endl;
        std::cout << "\"What brings thee in this parts?\"" << std::endl;
        contin();
        std::cout << "< " << g->p.name << " >" << std::endl;
        std::cout << "\"Who are you?\"" << std::endl;
        contin();
        std::cout << "< Wizard >" << std::endl;
        std::cout << "\"I am but a humble wizard\"" << std::endl;
        contin();
        std::cout << "< " << g->p.name << " >" << std::endl;
        std::cout << "\"What is a wizard doing here?\"" << std::endl;
        contin();
        std::cout << "< Wizard >" << std::endl;
        std::cout << "\"You need not know of it\"" << std::endl;
        std::cout << "\"Instead I can offer some services if you do me a favor\"" << std::endl;
        contin();
        std::cout << "< " << g->p.name << " >" << std::endl;
        std::cout << "\"What favor?\"" << std::endl;
        contin();
        std::cout << "< Wizard >" << std::endl;
        std::cout << "\"In the room the next of this one\"" << std::endl;
        std::cout << "\"There's a pesky skeleton ruining my garden\"" << std::endl;
        std::cout << "\"Kill it in exchange for a reward\"" << std::endl;
        contin();
        std::cout << "< " << g->p.name << " >" << std::endl;
        int move1 = accept();
        
        space();

        g->dialogue2 = false;

        if (move1 == 1) // Accepted Wizards Offer
        {
            cinignore();

            g->wizard.active = true; // Activates The Wizards Quest

            std::cout << "< Wizard >" << std::endl;
            std::cout << "\"I knew I could count on you!\"" << std::endl;
            contin();

            space();

            // Continue Path 2_2 Here With Wizard Quest
            std::cout << "Entering The Next Room. . ." << std::endl;
            contin();

            path2_2(g); // Enter With Quest Value 1 (With Quest)
        }
        else if (move1 == 0) // Declined Wizard Offer
        {
            cinignore();

            g->wizard.active = false;

            std::cout << "< Wizard >" << std::endl;
            std::cout << "\"Eh? Your loss then\"" << std::endl;
            std::cout << "\"Come to me again if you ever change your mind\"" << std::endl;
            contin();
            
            optionsPath2_2(g);
        }
    }
    else if (g->dialogue2 == false) // No Dialogue
    { 
        optionsPath2_2(g);  
    }

}

void path2_2 (gameState *g)
{
    if (g->wizard.active == true)
    {
        std::cout << "Wizard Quest: Active" << std::endl;
    }
    else if (g->wizard.active == false)
    {
        std::cout << "Wizard Quest: Inactive" << std::endl;
    }

    contin();

    enemy skeleton;
    skeleton.hp = 30;
    skeleton.atk = 5;
    skeleton.speed = 15;
    skeleton.gold = 30;
    skeleton.name = "Skeleton";

    std::cout << "< " << skeleton.name << " >" << std::endl;
    std::cout << "(Bones Crackling)" << std::endl;
    contin();

    std::cout << "# You See A Total Of 3 Skeletons Scattered In The Wizards Garden" << std::endl;
    std::cout << "# They're Busy And Haven't Noticed You Yet" << std::endl;

    int move1;

    while (1)
    {
        std::cout << "[1] Attack Skeleton 1" << std::endl;
        std::cout << "[2] Attack Skeleton 2" << std::endl;
        std::cout << "[3] Attack Skeleton 3" << std::endl;
        std::cout << "[4] Turn Back" << std::endl;

        std::cout << "Next Move: ";
        std::cin >> move1;

        if (move1 == 1)
        {
            std::cout << "Attacking Skeleton 1" << std::endl; // Add Combat Function To Each. After Each Win Make It Realize That the Skeletons Are Dead.
            break;
        }
        else if (move1 == 2)
        {
            std::cout << "Attacking Skeleton 2" << std::endl;
            break;
        }
        else if (move1 == 3)
        {
            std::cout << "Attacking Skeleton 3" << std::endl;
            break;
        }
        else if (move1 == 4)
        {
            cinignore();
            contin(); 
            std::cout << "Turning Back. . ." << std::endl;
            contin();

            g->dialogue2 = false;
            path2(g);
            break;
        }
    }

}


// - - - - - - - - - - Paths 3 - - - - - - - - - -
void path3 (gameState *g)
{
    std::cout << "Welcome to path 3" << std::endl;
}

// - - - - - - - - - - Combat System - - - - - - - - - -
int turnBasedCombat (gameState *g, enemy *e) // Main Combat Mechanics (Basic Turn Based)
{
    int turn; // Determine who starts first

    if (g->p.speed > e->speed)
    {
        turn = 0;
        std::cout << "Player Start" << std::endl;
    }
    else 
    {
        turn = 1;
        std::cout << "Enemy Start" << std::endl;
    }

    int playerStartingHp = g->p.hp; // Stores in HP before the fight begins
    int enemyStartingHp = e->hp; // Used for determining max hp and restoring hp after combat 

    while (1)
    {
        if (turn == 0)
        {
            std::cout << g->p.name << "\'s Turn" << std::endl;

            g->p.defend = 0; // Resets Defending to false 
            int decision = playerCombatOptions(g, e, playerStartingHp);

            if (decision == 2) // If Successfully Ran Away. Return To 2 Caller. 
            {
                return 2;
            }

            if (e->hp <= 0)
            {
                std::cout << "You Win!" << std::endl;
                
                g->p.hp = playerStartingHp; // Restore HP

                g->p.gold = g->p.gold + e->gold; // Receive Enemies Gold
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

            if (g->p.defend == 1) // If defending reduce enemy attack
            {
                contin();
                g->p.hp = g->p.hp - (e->atk / 2);
                std::cout << g->p.name << " Defended, Reduced Damage Taken" << std::endl;
            }
            else
            {
                g->p.hp = g->p.hp - e->atk; // Normal Attack
            }

            if (g->p.hp <= 0)
            {
                std::cout << "You Died!" << std::endl;
                respawn(g);
                return 1;
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
        std::cout << g->p.name << "\'s HP: " << g->p.hp << " / " << playerStartingHp << std::endl; // Display Player HP
        std::cout << "[1] Attack" << std::endl;
        std::cout << "[2] Defend" << std::endl;
        std::cout << "[3] Try To Run" << std::endl;
        std::cout << "[4] Show Player Stats" << std::endl;
        std::cout << "[5] Show Enemy Stats" << std::endl; 

        std::cout << "Next Move: ";
        std::cin >> combatDecision;

        if (combatDecision == 1) // Attack
        {
            e->hp = e->hp - g->p.atk;
            std::cout << g->p.name << " Attacks!" << std::endl;
            break;
        }
        else if (combatDecision == 2) // Defend
        {
            g->p.defend = 1;
            std::cout << g->p.name << " Defends!" << std::endl;
            break;
        }
        else if (combatDecision == 3) // Run
        {
            cinignore();

            contin();
            std::cout << "< " << g->p.name << " >" << std::endl;
            std::cout << "Time to run!" << std::endl;

            if (g->p.speed > e->speed)
            {
                contin();
                std::cout << " Succesfully Ran Away" << std::endl;
                contin();

                g->p.hp = playerStartingHp;

                return 2; 
            }
            else
            {
                std::cout << g->p.name << " Failed To Run away" << std::endl;
                break;
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


// - - - - - - - - - - Player Tools - - - - - - - - - -
void playerStats (gameState *g)
{
    std::cout << g->p.name << "\'s Stats:" << std::endl;
    std::cout << "HP: " << g->p.hp << std::endl;
    std::cout << "ATK: " << g->p.atk << std::endl;
    std::cout << "SPEED: " << g->p.speed << std::endl;
    std::cout << "GOLD: " << g->p.gold << std::endl;

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

void resetPlayerStats (gameState *g)
{
    g->p.hp = 100;
    g->p.atk = 10;
    g->p.speed = 10;
    g->p.gold = 0;
}

void resetGame (gameState *g) // Add All Dialogues and Quests Here
{
    // Dialogues
    g->dialogue2 = true;

    // Quests
    g->wizard.active = false;
    g->wizard.finished = false;

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

void cinignore (void)
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


// - - - - - - - - - - Path Specific Options - - - - - - - - - -
void optionsPath2_2 (gameState *g)
{
    int move1;
    
    std::cout << "[1] Continue to next room " << std::endl;
    std::cout << "[2] Talk to Wizard" << std::endl;
    std::cout << "[3] Go back" << std::endl;
    
    std::cout << "Next Move: ";
    std::cin >> move1;
    
    if (move1 == 1)
    {
        cinignore();
        std::cout << "Entering next room. . ." << std::endl;
        contin();

        path2_2(g);
    }
    else if (move1 == 2)
    {
        int move2;

        std::cout << "Approaching the Wizard. . ." << std::endl;
        
        if (g->wizard.active == true) // If The Quest Is Currently Active
        {
            std::cout << "< Wizard >" << std::endl;
            std::cout << "\"You have Skeletons To Kill\"" << std::endl;
            std::cout << "\"Stop Wasting Time Here!\"" << std::endl;

            path2(g);
        }
        else if (g->wizard.active == false)
        {
            std::cout << "< Wizard >" << std::endl;
            std::cout << "\"Ready To Take My Offer?\"" << std::endl;
            yn();
            std::cin >> move2;

            if (move2 == 1) // If Yes. Accept Wizard Quest
            {
                cinignore();

                std::cout << "< Wizard >" << std::endl;
                std::cout << "\"Nice!\"" << std::endl;
                std::cout << "\"Now Go Slay Me Some Skeletons\"" << std::endl;
                contin();

                std::cout << "Entering Next Room. . ." << std::endl;
                contin();

                g->wizard.active = true; // Activates Quest

                path2_2(g);
            }
            else if (move2 == 2)
            {
                std::cout << "< Wizard >" << std::endl;
                std::cout << "\"Stop Wasting My Time Then!\"" << std::endl;

                path2(g);
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
    else if (move1 == 3)
    {
        std::cout << "Here we are again. . ." << std::endl;
        path0(g);
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


// - - - - - - - - - - Design - - - - - - - - - -
void space (void) // Create 1 line space
{
    std::cout << "\n";
}

void contin (void) // Continue dialouge 
{
    std::cout << "->";
    getchar();
}