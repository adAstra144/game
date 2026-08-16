#pragma once

#include "player/player.hpp"

struct quest {
    bool active;
    bool finished;
};

struct gameState {
    // Player
    player p;    

    // Quests
    quest qWizard;
    int numOfSkeletons;
    
    // Dialogues (Format Dialogue(n)<- Path)
    bool dialogue2;
    bool dialogue2_2;
};

// Add All Dialogues and Quests Here
void resetGame (gameState *g); 