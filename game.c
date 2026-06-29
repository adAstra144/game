#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef struct
{
    char name[50];
    int hp;
    int atk;
    int gold;
} player;

typedef struct 
{
    int hp;
    int atk;
    int goldDrop;
} enemy;


void path0(player *p);
void path1(char move1[], player *p);
void path1_2(player *p);
void path2(char move1[], player *p);
void path3(char move1[], player *p);


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

    printf("%i\n", p->hp); // Make Turn Based Combat Here!
}

void path2(char move1[], player *p) // Meet a Swordsman Route (Increase Attack)
{
    printf("* You selected path 2\n");
}

void path3(char move1[], player *p) // Meet a Wizard Route (Increase HP)
{
    printf("* You selected path 3\n");
}