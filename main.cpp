#include <iostream>
#include <string>
#include <limits>
#include <cstdio>



// Design Functions
void space (void);
void contin (void);


// Class

// Main Player 
class player
{
    private:
        int hp;
        int atk;
        int speed;
        int gold;
        bool defend;
    
    public:
        std::string name;

        player()
        {
            hp = 1000;
            atk = 100;
            speed = 10;
            gold = 0;
            defend = false;
        }



        // Combat Methods
        void takeDamage (int amount)
        {
            if (defend) amount /= 2;

            hp -= amount;

            if (hp < 0) hp = 0;
        }


        void gainGold (int gold) // Or Gain Gold
        {
            this->gold += gold;
        }

        // Set Player Variables Methods
        void setHp (int hp)
        {
            this->hp = hp;
        }
        void setAtk (int atk)
        {
            this->atk = atk;
        }
        void setSpeed (int speed)
        {
            this->speed = speed;
        }
        void setGold (int gold)
        {
            this->gold = gold;
        }
        void setDefend (bool defend)
        {
            this->defend = defend;
        }



        // Get Player Variables Methods
        int getHp ()
        {
            return hp;
        }
        int getAtk ()
        {
            return atk;
        }
        int getSpeed ()
        {
            return speed;
        }
        int getGold ()
        {
            return gold;
        }
        bool getDefend ()
        {
            return defend;
        }

        // Methods For Increasing/Upgrading Player Stats
        void hpUp (int amount)
        {
            hp += 10 * amount; 
        }
        void atkUp (int amount)
        {
            atk += 10 * amount;
        }
        void speedUp (int amount)
        {
            speed += 10 * amount;
        }
};

// Main Enemy Class
class enemy 
{
    protected:
        int hp;
        int atk;
        int speed;
        int gold;

    public:
        std::string name;

        enemy(std::string n, int h, int a, int s, int g) // Create Enemies By Using enemy(Name, HP, ATTACK, SPEED, GOLD)
        {
            name = n;
            hp = h;
            atk = a;
            speed = s;
            gold = g;
        }

        // Combat
        void takeDamage (int amount)
        {
            hp -= amount; 
        }
        virtual void specialMove (int turnCount)
        {
            
        }

        // Set Enemy Variables
        void setHp (int hp)
        {
            this->hp = hp;
        }

        // Get Enemy Variables
        int getHp ()
        {
            return hp;
        }
        int getAtk ()
        {
            return atk;
        }
        int getSpeed()
        {
            return speed;
        }
        int getGold ()
        {
            return gold;
        }

};

// Separate Enemy Classes / Unique Enemies With distinguishing Features
class kingGoblin : public enemy
{
    public:
        kingGoblin() : enemy("King Goblin", 200, 50, 5, 200) {}

    void specialMove (int turnCount) override
    {
        if (turnCount % 3 == 0)
        {
            hp += hp * 0.05;

            if (hp > 200) hp = 200;

            contin();
            std::cout << name << " Used Special Move: Heal" << std::endl;
            std::cout << name << " New HP: " << hp << " / 200" << std::endl;
        }
            
    }
    
};

class skeleton : public enemy
{
    public:
        skeleton() : enemy("Skeleton", 30, 5, 15, 30) {}
    
        void resetStats ()
        {
            hp = 30;
            atk = 5;
            speed = 15;
            gold = 30;
        }

};



// Structs

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
    quest qWizard;
    
    // Dialogues
    bool dialogue2;
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

// - - - - - - - - - - Paths - - - - - - - - - -
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


// - - - - - - - - - - Paths 1 - - - - - - - - - -
void path1 (gameState *g) // Pre King Goblin Path
{
    std::cout << "Current Path: 1" << std::endl;
    int move1;

    while (1)
    {
        std::cout << "[1] Continue To Path 1-2?" << std::endl;
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
    cinignore();

    std::cout << "Current Path: 1-2" << std::endl;

    kingGoblin kingGoblin;

    std::cout << "King Goblin Has Appeared!" << std::endl;
    contin();
    
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
    std::cout << "Current Path: 2" << std::endl;

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

            g->qWizard.active = true; // Activates The Wizards Quest

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

            g->qWizard.active = false;

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
    std::cout << "Current Path: 2-2" << std::endl;

    if (g->qWizard.active == true)
    {
        std::cout << "Wizard Quest: Active" << std::endl;
    }
    else if (g->qWizard.active == false)
    {
        std::cout << "Wizard Quest: Inactive" << std::endl;
    }

    contin();

    skeleton skeleton;

    std::cout << "< " << skeleton.name << " >" << std::endl;
    std::cout << "(Bones Crackling)" << std::endl;
    contin();

    std::cout << "# You See A Total Of 3 Skeletons Scattered In The Wizards Garden" << std::endl;
    std::cout << "# They're Busy And Haven't Noticed You Yet" << std::endl;

    int move1;
    int numOfSkeletons = 3;

    while (1)
    {
        if (numOfSkeletons == 3)
        {
            std::cout << "[1] Attack Skeleton 1" << std::endl;
            std::cout << "[2] Attack Skeleton 2" << std::endl;
            std::cout << "[3] Attack Skeleton 3" << std::endl;            
            std::cout << "[4] Turn Back" << std::endl;


        }
        else if (numOfSkeletons == 2)
        {
            std::cout << "[1] Attack Skeleton 1" << std::endl;
            std::cout << "[2] Attack Skeleton 2" << std::endl;
            std::cout << "[3] Turn Back" << std::endl;
        }
        else if (numOfSkeletons == 1)
        {
            std::cout << "[1] Attack Skeleton 1" << std::endl;
            std::cout << "[2] Turn Back" << std::endl;
        }
        else 
        {
            std::cout << "[1] Turn Back" << std::endl;
        }
        std::cout << "Next Move: ";
        std::cin >> move1;
    

        int result;



        // Adaptive Choices (Changes Everytime A Skeleton Is Killed)
        if (numOfSkeletons == 3)
        {
            if (move1 == 1)
            {
                std::cout << "Attacking Skeleton 1" << std::endl; 
                result = turnBasedCombat(g, &skeleton);

                if (result == 0)
                {
                    numOfSkeletons--;
                    skeleton.resetStats();
                }
                else 
                {
                    std::cout << "Error" << std::endl;
                }
            }
            else if (move1 == 2)
            {
                std::cout << "Attacking Skeleton 2" << std::endl;
                result = turnBasedCombat(g, &skeleton);

                if (result == 0)
                {
                    numOfSkeletons--;
                    skeleton.resetStats();
                }
                else
                {
                    std::cout << "Error" << std::endl;
                }
            }
            else if (move1 == 3)
            {
                std::cout << "Attacking Skeleton 3" << std::endl;
                result = turnBasedCombat(g, &skeleton);

                if (result == 0)
                {
                    numOfSkeletons--;
                    skeleton.resetStats();
                }
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
        else if (numOfSkeletons == 2)
        {
            if (move1 == 1)
            {
                std::cout << "Attacking Skeleton 1" << std::endl; 
                result = turnBasedCombat(g, &skeleton);

                if (result == 0)
                {
                    numOfSkeletons--;
                    skeleton.resetStats();
                }
                else 
                {
                    std::cout << "Error" << std::endl;
                }
            }
            else if (move1 == 2)
            {
                std::cout << "Attacking Skeleton 2" << std::endl;
                result = turnBasedCombat(g, &skeleton);

                if (result == 0)
                {
                    numOfSkeletons--;
                    skeleton.resetStats();
                }
                else
                {
                    std::cout << "Error" << std::endl;
                }
            }
            else if (move1 == 3)
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
        else if (numOfSkeletons == 1)
        {
            if (move1 == 1)
            {
                std::cout << "Attacking Skeleton 1" << std::endl; 
                result = turnBasedCombat(g, &skeleton);

                if (result == 0)
                {
                    numOfSkeletons--;
                    skeleton.resetStats();

                    if (g->qWizard.active)
                    {
                        g->qWizard.finished = true;
                    }
                }
                else 
                {
                    std::cout << "Error" << std::endl;
                }
            }
            else if (move1 == 2)
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
        else 
        {
            if (move1 == 1)
            {
                cinignore();
                contin(); 
                std::cout << "Turning Back. . ." << std::endl;
                contin();

                g->dialogue2 = false;
                path2(g);
                break;
            }
            else 
            {
                std::cout << "Error" << std::endl;
            }
        }
    }

}


// - - - - - - - - - - Paths 3 - - - - - - - - - -
void path3 (gameState *g)
{
    std::cout << "Current Path: 3" <<std::endl;

    std::cout << "Welcome to path 3" << std::endl;
}


// - - - - - - - - - - Combat System - - - - - - - - - -
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
    cinignore();
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
            cinignore();
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
    std::cout << "HP: " << g->p.getHp() << std::endl;
    std::cout << "ATK: " << g->p.getAtk() << std::endl;
    std::cout << "SPEED: " << g->p.getSpeed() << std::endl;
    std::cout << "GOLD: " << g->p.getGold() << std::endl;

    cinignore();
    std::cout << "Press Enter To Exit. . .";
    getchar();
}

void enemyStats (enemy *e)
{
    std::cout << e->name << "\'s Stats:" << std::endl;
    std::cout << "HP: " << e->getHp() << std::endl;
    std::cout << "ATK: " << e->getAtk() << std::endl;
    std::cout << "SPEED: " << e->getSpeed() << std::endl;
    std::cout << "GOLD: " << e->getGold() << std::endl;

    cinignore();
    std::cout << "Press Enter To Exit. . .";
    getchar();
}

void statUp (gameState *g)
{
    int move1;
    int amount;

    std::cout << "Select A Stat To Upgrade: " << std::endl;
    std::cout << "[1] HP" << std::endl;
    std::cout << "[2] ATK" << std::endl;
    std::cout << "[3] SPEED" << std::endl;
    std::cout << "Next Move: ";
    std::cin >> move1;

    if (move1 == 1)
    {
        g->p.hpUp(amount);
    }
    // Continue statUp 
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
    g->p.setHp(100);
    g->p.setAtk(10);
    g->p.setSpeed(10);
    g->p.setGold(0);
    g->p.setDefend(false);
}

void resetGame (gameState *g) // Add All Dialogues and Quests Here
{
    // Dialogues
    g->dialogue2 = true;

    // Quests
    g->qWizard.active = false;
    g->qWizard.finished = false;

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
        if (g->qWizard.finished == true)
        {
            cinignore();
            std::cout << "< Wizard >" << std::endl;
            std::cout << "What Do You Need?" << std::endl;
            contin();
            std::cout << "< " << g->p.name << " >" << std::endl;
            std::cout << "So About The Reward?" << std::endl;
            contin();
            std::cout << "< Wizard >" << std::endl;
            std::cout << "Ohh.. Right" << std::endl;
            contin();
            std::cout << "< Wizard >" << std::endl;
            std::cout << "Done Already?" << std::endl;
            contin();
            std::cout << "< " << g->p.name << " >" << std::endl;
            std::cout << "Yup" << std::endl;
            contin();
            std::cout << "< Wizard >" << std::endl;
            std::cout << "In Return I Can Make You Stronger!" << std::endl;
            contin();
            std::cout << "< " << g->p.name << " >" << std::endl;
            std::cout << "Stronger? How?" << std::endl;
            contin();
            std::cout << "< Wizard >" << std::endl;
            std::cout << "Well It's Quite Easy Actually" << std::endl;
            std::cout << "All I Need Is A Few Gold And I Can Magically Enhance You" << std::endl;
            std::cout << "I'll Make Your First Few Upgrades Free Since You Took The Time To Get Rid Of Those Skeletons" << std::endl;

            int freeUps = 5;

            // Add statup Function Here
            // Consider Making This A One Time Section (Dialogue & Free statUp's)
        }
        else
        {
            int move2;

            std::cout << "Approaching the Wizard. . ." << std::endl;
            
            if (g->qWizard.active == true) // If The Quest Is Currently Active
            {
                std::cout << "< Wizard >" << std::endl;
                std::cout << "\"You have Skeletons To Kill\"" << std::endl;
                std::cout << "\"Stop Wasting Time Here!\"" << std::endl;

                path2(g);
            }
            else if (g->qWizard.active == false)
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

                    g->qWizard.active = true; // Activates Quest

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
