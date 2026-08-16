#include "player/player.hpp"

#include <iostream>
#include "devTools.hpp"

// Player Constructor For Base Player Stats
player::player() {
    // Base Stats
    hp = 100;
    atk = 20; // Default Is 10
    speed = 10;
    gold = 100;
    defend = false;

    // Base Level Of Stats
    lvlHp = 1;
    lvlAtk = 1;
    lvlSpeed = 1;
}

void player::takeDamage (int amount) {
    if (defend) amount /= 2;

    hp -= amount;

    if (hp < 0) hp = 0;
}


void player::gainGold (int gold) {
    this->gold += gold;
}
void player::setHp (int hp) {
    this->hp = hp;
}
void player::setAtk (int atk) {
    this->atk = atk;
}
void player::setSpeed (int speed) {
    this->speed = speed;
}
void player::setGold (int gold) {
    this->gold = gold;
}
void player::setDefend (bool defend) {
    this->defend = defend;
}


int player::getHp () {
    return hp;
}
int player::getAtk () {
    return atk;
}
int player::getSpeed () {
    return speed;
}
int player::getGold () {
    return gold;
}
bool player::getDefend () {
    return defend;
}
int player::getLvlHp () {
    return lvlHp;
}
int player::getLvlAtk () {
    return lvlAtk;
}
int player::getLvlSpeed () {
    return lvlSpeed;
}

// Increasing/Upgrading Player Stats
int player::continueStatUp (int price) {
    int decision;

    message(messageType::SYS, {"Will cost:", std::to_string(price), "gold"});

    message(messageType::INPUT, {"Continue :"});
    yn();
    std::cin >> decision;

    if (decision == 1) {
        return 1;
    } else {
        horizontalBrokenLines();
        message(messageType::SYS, {"Stat level up cancelled"});
        horizontalBrokenLines();
        
        return 0;
    }
}

int player::hpUp (int amount, int price) {
    int beforeGold = gold;

    int decision = continueStatUp(price);

    if (decision == 1) {
        gold -= price;
    } else if (decision == 0) {
        return 0;
    }

    if (gold >= 0) {
        hp += 10 * amount;    
        lvlHp += amount;

        horizontalBrokenLines();
        message(messageType::SYS, {"Upgrade succesful!"});
        horizontalBrokenLines();

        return 1; // Transac Success
    } else {
        horizontalBrokenLines();
        message(messageType::ERROR, {"Not enough gold"});
        horizontalBrokenLines();

        gold = beforeGold;

        return 0; // Transac Failed
    }   
}
int player::atkUp (int amount, int price) {   
    int beforeGold = gold;

    int decision = continueStatUp(price);

    if (decision == 1) {
        gold -= price;
    } else if (decision == 0) {
        return 0;
    }

    if (gold >= 0) {
        atk += 10 * amount;
        lvlAtk += amount;

        horizontalBrokenLines();
        message(messageType::SYS, {"Upgrade succesful!"});
        horizontalBrokenLines();

        return 1; // Transac Success
    } else {
        horizontalBrokenLines();
        message(messageType::ERROR, {"Not enough gold"});
        horizontalBrokenLines();

        gold = beforeGold;

        return 0; // Transac Failed
    }
}

int player::speedUp (int amount, int price) {
    int beforeGold;

    int decision = continueStatUp(price);

    if (decision == 1) {
        gold -= price;
    } else if (decision == 0) {
        return 0;
    }

    if (gold >= 0) {
        speed += 10 * amount;
        lvlSpeed += amount;

        horizontalBrokenLines();
        message(messageType::SYS, {"Upgrade succesful!"});
        horizontalBrokenLines();

        return 1; // Transac Success
    }
    else {
        horizontalBrokenLines();
        message(messageType::ERROR, {"Not enough gold"});
        horizontalBrokenLines();

        gold = beforeGold;

        return 0; // Transac Failed
    }
}