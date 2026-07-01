#include <stdio.h>
#include <string.h>
#include <unistd.h>


typedef struct
{
    char name[50];
    int hp;
    int atk;
    int speed;
    int gold;
} player;

typedef struct 
{
    char name[50];
    int hp;
    int atk;
    int speed;
    int goldDrop;
} enemy;


// FUNCTIONS
// Paths
void path0(player *p);
void path1(char move1[], player *p);
void path1_2(player *p);
void path2(char move1[], player *p);
void path3(char move1[], player *p);

// Combat
void turnBasedCombat(player *p, enemy *e);
void playerCombatOption(player *p, enemy *e);

// Tools
void playerStats(player *p);
void enemyStats(enemy *p);


int main (void)
{
    char menuOptions[50] = "";

    printf("Welcome to astra's short dungeon game!\n");
    printf("[1] New Game\n");
    printf("[2] Exit\n");

    fgets(menuOptions, sizeof(menuOptions), stdin);
    menuOptions[strcspn(menuOptions, "\n")] = 0;

    if (strcmp(menuOptions, "1") == 0)
    {
        printf("Starting new game...\n");
        //sleep(1);

        player p;
        p.name;
        p.hp = 100;
        p.atk = 10; 
        p.gold;

        printf("Player Name: ");
        //sleep(1);
        fgets(p.name, sizeof(p.name), stdin);
        p.name[strcspn(p.name, "\n")] = 0;
        
        printf(" * = player action\n");
        printf(" # = Story\n");
        printf("Enter \"X\" to exit game anytime\n");
        //sleep(2);
        printf("# You start your adventure inside a dungeon with no memory of how you got here\n");
        //sleep(3);
        printf("# Presented before you are 3 paths\n");

        path0(&p); // "&p" Passes Player "p" Struct To Other Functions. Just "p" For The Rest No "&". 

    }
    else if (strcmp(menuOptions, "2") == 0)
    {
        printf("Goodbye :(\n");
    }
    else
    {
        printf("Error\n");
    }


    return 0;
}

void path0(player *p) // Starting Area
{       
    int running = 1;
    while (running)        
    {
        char move1[50];

        printf("[1] Path 1\n");
        printf("[2] Path 2\n");
        printf("[3] Path 3\n");

        printf("Next Move: ");
            
        fgets(move1, sizeof(move1), stdin);
        move1[strcspn(move1, "\n")] = 0;

        if (strcmp(move1, "1") == 0)
        {
            path1(move1, p);
            break;
        }
        else if (strcmp(move1, "2") == 0)
        {
            path2(move1, p);
            break;
        }
        else if (strcmp(move1, "3") == 0)
        {
            path3(move1, p);
            break;
        }
        else if (strcmp(move1, "X") == 0)
        {
            printf("Goodbye!\n");
            break;
        }
        else
        {
            printf("Invalid move. Please try again\n");
        }
    }
}

void path1(char move1[], player *p) // Optional King Goblin Route
{
    printf("* You enter path 1.\n");
    printf("# As you wander around you encounter a sign saying \"Danger ahead\"\n");

    int running = 1;
    while (running)
    {
        char move2[50];

        printf("[1] Continue path 1\n");
        printf("[2] Turn back\n");
        printf("Next Move: ");

        fgets(move2, sizeof(move2), stdin);
        move2[strcspn(move2, "\n")] = 0;

        if (strcmp(move2, "1") == 0)
        {
            path1_2(p);
            break;
        }
        else if (strcmp(move2, "2") == 0)
        {
            printf("* You turned back\n");
            printf("# You are now back at the start\n");
            path0(p);
            break;
        }
        else if (strcmp(move2, "X") == 0)
        {
            printf("goodbye\n");
            break;
        }
        else
        {
            printf("Invalid move. Try again\n");
        }
    }
}

void path1_2(player *p) // King Goblin Route
{
    printf("# Ignoring the sign you pushed on\n");
    printf("# This was an awkwardly long straight path\n");
    printf("# Everything was going smoothly until you hear a loud roar approaching\n");
    printf("# You looked behind and barely dodged the giants rampage\n");
    printf("! ! King Goblin has appeared ! !\n");

    enemy kingGoblin;
    kingGoblin.hp = 200;
    kingGoblin.atk = 50;
    kingGoblin.goldDrop = 300;
    strcpy(kingGoblin.name, "King Goblin");

    turnBasedCombat(p, &kingGoblin);
}

void path2(char move1[], player *p) // Meet a Swordsman Route (Increase Attack)
{
    printf("* You selected path 2\n");
}

void path3(char move1[], player *p) // Meet a Wizard Route (Increase HP)
{
    printf("* You selected path 3\n");
}

void turnBasedCombat(player *p, enemy *e)
{
    printf("Combat start!\n");

    int start;

    if (p->speed > e->speed)
    {
        printf("Player starts first!\n");
        start = 0; // Player start = 0
    }
    else 
    {
        printf("Enemy starts first!\n");
        start = 1; // Enemy start = 1
    }
    
    int running = 1;
    while (running)
    {
        if (start == 0)
        {
            printf("%s's Turn \n", p->name);

            playerCombatOption(p,e);

            if (e->hp <= 0 )
            {
                printf("You win!");
                break;
            }

            start = 1;
        }
        else if (start == 1)
        {
            printf("%s's Turn\n", e->name);

            printf("%s Attacks! \n", e->name);
            p->hp = p->hp - e->atk;

            if (p->hp <= 0 )
            {
                printf("You lose!\n");
                break;
            }

            start = 0;
        }
    }
}

void playerCombatOption(player *p, enemy *e)
{
    char playerCombatDecision[50];
    printf("[1] Attack\n");
    printf("[2] Defend\n");
    printf("[3] Run\n");
    printf("[4] Player Stats\n");
    printf("[5] Enemy stats\n");
    printf("Next Move : ");

    fgets(playerCombatDecision, sizeof(playerCombatDecision), stdin);
    playerCombatDecision[strcspn(playerCombatDecision, "\n")] = 0;

    if (strcmp(playerCombatDecision, "1") == 0)
    {
        e->hp = e->hp - p->atk;
    }
    else if (strcmp(playerCombatDecision, "2") == 0) // Placeholder | add later
    {
        printf("Add defence later\n");
    }
    else if (strcmp(playerCombatDecision, "3") == 0) // Placeholder | add later
    {
        printf("Add run later\n");
    }
    else if (strcmp(playerCombatDecision, "4") == 0)
    {
        playerStats(p);
        playerCombatOption(p, e);
    }
    else if (strcmp(playerCombatDecision, "5") == 0)
    {
        enemyStats(e);
        playerCombatOption(p, e);
    }
    else 
    {
        printf("error\n"); // Add better error checking | Consider adding loop back if error
    }
} 

// Print stats functions
void playerStats(player *p)
{
    printf("%s\n", p->name);
    printf("Player Stats : \n");
    printf("HP : %i\n", p->hp);
    printf("ATK : %i\n", p->atk);
    printf("SPEED : %i\n", p->speed);
    printf("GOLD : %i\n", p->gold);
    printf("Press Enter to exit. . .\n");
    getchar();
}
void enemyStats(enemy *e)
{
    printf("%s\n", e->name);
    printf("Enemy Stats : \n");
    printf("HP : %i\n", e->hp);
    printf("ATK : %i\n", e->atk);
    printf("SPEED : %i\n",e->speed);
    printf("GOLD : %i\n", e->goldDrop);
    printf("Press Enter to exit. . .\n");
    getchar();
}