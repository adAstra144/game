#include "player.h"

// Player Constructor For Base Player Stats
player::player()
{
    // Base Stats
    hp = 100;
    atk = 10;
    speed = 10;
    gold = 100;
    defend = false;

    // Base Level Of Stats
    lvlHp = 1;
    lvlAtk = 1;
    lvlSpeed = 1;
}


// Combat Methods
void player::takeDamage (int amount)
{
    if (defend) amount /= 2;

    hp -= amount;

    if (hp < 0) hp = 0;
}


void player::gainGold (int gold) // Or Gain Gold
{
    this->gold += gold;
}

// Set Player Variables Methods
void player::setHp (int hp)
{
    this->hp = hp;
}
void player::setAtk (int atk)
{
    this->atk = atk;
}
void player::setSpeed (int speed)
{
    this->speed = speed;
}
void player::setGold (int gold)
{
    this->gold = gold;
}
void player::setDefend (bool defend)
{
    this->defend = defend;
}



// Get Player Variables Methods
int player::getHp ()
{
    return hp;
}
int player::getAtk ()
{
    return atk;
}
int player::getSpeed ()
{
    return speed;
}
int player::getGold ()
{
    return gold;
}
bool player::getDefend ()
{
    return defend;
}
int player::getLvlHp ()
{
    return lvlHp;
}
int player::getLvlAtk ()
{
    return lvlAtk;
}
int player::getLvlSpeed ()
{
    return lvlSpeed;
}

// Methods For Increasing/Upgrading Player Stats
int player::hpUp (int amount, int price)
{
    int beforeGold = gold;

    gold -= price;

    if (gold < 0)
    {
        std::cout << "Not Enough Gold!" << std::endl;
        gold = beforeGold;
        return 0; // Transac Failed
    }
    else
    {
        hp += 10 * amount;    
        lvlHp += amount;
        return 1; // Transac Success
    }
        
}
int player::atkUp (int amount, int price)
{   
    int beforeGold = gold;

    gold -= price;

    if (gold < 0)
    {
        std::cout << "Not Enough Gold" << std::endl;
        gold = beforeGold;
        return 0; // Transac Failed
    }
    else
    {
        atk += 10 * amount;
        lvlAtk += amount;
        return 1; // Transac Success
    }
}

int player::speedUp (int amount, int price)
{
    std::cout << "This Will Cost " << price << " Gold. Continue?" << std::endl;

    int beforeGold;

    gold -= price;

    if (gold < 0)
    {
        std::cout << "Not Enough Gold" << std::endl;
        gold = beforeGold;
        return 0; // Transac Failed
    }
    else
    {
        speed += 10 * amount;
        lvlSpeed += amount;
        return 1; // Transac Success
    }
}