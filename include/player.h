#pragma once

#include <iostream>
#include <string>
#include "devTools.h"
#include "enemy.h"

// Main Player 
class player
{
    private:
        int hp;
        int atk;
        int speed;
        int gold;
        bool defend;
        int lvlHp;
        int lvlAtk;
        int lvlSpeed;
    
    public:
        std::string name;

        // Player Constructor
        player();

        // Combat Methods
        void takeDamage(int amount);

        void gainGold (int gold);

        // Set Player Variables Methods
        void setHp (int hp);
        void setAtk (int atk);
        void setSpeed (int speed);
        void setGold (int gold);
        void setDefend (bool defend);

        // Get Player Variables Methods
        int getHp ();
        int getAtk ();
        int getSpeed ();
        int getGold ();
        bool getDefend ();
        int getLvlHp ();
        int getLvlAtk ();
        int getLvlSpeed ();

        // Methods For Increasing/Upgrading Player Stats
        int hpUp (int amount, int price);
        int atkUp (int amount, int price);
        int speedUp (int amount, int price);
};

