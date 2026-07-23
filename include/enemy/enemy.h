#pragma once

#include <string>

class enemy 
{
    protected:
        int hp;
        int atk;
        int speed;
        int gold;

    public:
        std::string name;

        // Create Enemies By Using enemy(Name, HP, ATTACK, SPEED, GOLD)
        enemy(std::string n, int h, int a, int s, int g); 

        // Combat
        void takeDamage (int amount);

        virtual void specialMove (int turnCount);

        // Set Enemy Variables
        void setHp (int hp);

        // Get Enemy Variables
        int getHp ();
        int getAtk ();
        int getSpeed();
        int getGold ();

};