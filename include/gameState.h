#pragma once

#include "player.h"

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
    int numOfSkeletons = 3;
    
    // Dialogues
    bool dialogue2;
};

// Add All Dialogues and Quests Here
void resetGame (gameState *g); 