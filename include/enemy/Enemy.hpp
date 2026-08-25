#pragma once

#include <string>

class Enemy {
    protected:
        int hp;
        int atk;
        int speed;
        int gold;

    public:
        std::string name;

        // Create Enemies By Using enemy(Name, HP, ATTACK, SPEED, GOLD)
        Enemy(std::string name, int hp, int atk, int speed, int gold); 

        // Combat
        void takeDamage (int amount);

        virtual void specialMove (int turnCount);

        // Set Enemy Variables
        void setHp (int hp);

        // Get Enemy Variables
        int getHp () const;
        int getAtk () const;
        int getSpeed() const;
        int getGold () const;

};