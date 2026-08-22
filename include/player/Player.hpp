#pragma once

#include <string>

enum class UpgradeResult {
    SUCCESS,
    CANCELLED,
    INSUFFICIENT_GOLD
};

// Main Player 
class Player {
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
        Player();

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
        int getHp () const;
        int getAtk () const;
        int getSpeed () const;
        int getGold () const;
        bool getDefend () const;
        int getLvlHp () const;
        int getLvlAtk () const;
        int getLvlSpeed () const;

        // Methods For Increasing/Upgrading Player Stats
        int continueStatUp (int price);
        UpgradeResult applyStatUp (int &stat, int &lvl, int amount, int price);
        UpgradeResult hpUp (int amount, int price);
        UpgradeResult atkUp (int amount, int price);
        UpgradeResult speedUp (int amount, int price);
};

