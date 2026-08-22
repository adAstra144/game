#pragma once

#include "player/player.hpp"

struct Quest {
    bool active;
    bool finished;
};

struct GameState {
    // Player
    player p;    

    // Quests
    Quest qWizard;
    int numOfSkeletons;
    
    // Dialogues (Format Dialogue(n)<- Path)
    bool dialogue2;
    bool dialogue2_2;
};

// Add All Dialogues and Quests Here
void resetGame (GameState *g); 