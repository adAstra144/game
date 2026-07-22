#include "enemy.h"

// Create Enemies By Using enemy(Name, HP, ATTACK, SPEED, GOLD)
enemy::enemy(std::string n, int h, int a, int s, int g) 
{
    name = n;
    hp = h;
    atk = a;
    speed = s;
    gold = g;
}

// Combat
void enemy::takeDamage (int amount)
{
    hp -= amount; 
}
void enemy::specialMove (int turnCount)
{
    
}

// Set Enemy Variables
void enemy::setHp (int hp)
{
    this->hp = hp;
}

// Get Enemy Variables
int enemy::getHp ()
{
    return hp;
}
int enemy::getAtk ()
{
    return atk;
}
int enemy::getSpeed()
{
    return speed;
}
int enemy::getGold ()
{
    return gold;
}
