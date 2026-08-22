#include "player/Player.hpp"

#include <iostream>

#include "devTools.hpp"

// Player Constructor For Base Player Stats
Player::Player() {
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

void Player::takeDamage (int amount) {
    if (defend) amount /= 2;

    hp -= amount;

    if (hp < 0) hp = 0;
}


void Player::gainGold (int gold) {
    this->gold += gold;
}
void Player::setHp (int hp) {
    this->hp = hp;
}
void Player::setAtk (int atk) {
    this->atk = atk;
}
void Player::setSpeed (int speed) {
    this->speed = speed;
}
void Player::setGold (int gold) {
    this->gold = gold;
}
void Player::setDefend (bool defend) {
    this->defend = defend;
}


int Player::getHp () const {
    return hp;
}
int Player::getAtk () const {
    return atk;
}
int Player::getSpeed () const {
    return speed;
}
int Player::getGold () const {
    return gold;
}
bool Player::getDefend () const {
    return defend;
}
int Player::getLvlHp () const {
    return lvlHp;
}
int Player::getLvlAtk () const {
    return lvlAtk;
}
int Player::getLvlSpeed () const {
    return lvlSpeed;
}

// Increasing/Upgrading Player Stats
int Player::continueStatUp (int price) {
    int decision;

    message(MessageType::SYS, {"Will cost:", std::to_string(price), "gold"});

    message(MessageType::INPUT, {"Continue :"});
    yn();
    std::cin >> decision;

    if (decision == 1) {
        return 1;
    } else {
        horizontalBrokenLines();
        message(MessageType::SYS, {"Stat level up cancelled"});
        horizontalBrokenLines();
        
        return 0;
    }
}

UpgradeResult Player::applyStatUp (int &stat, int &lvl, int amount, int price) {
    int beforeGold = gold;
    int decision = continueStatUp(price);
    
    if (decision == 0) return UpgradeResult::CANCELLED;

    gold -= price;

    clear();

    if (gold >= 0) {
        stat += 10 * amount;
        lvl += amount;

        horizontalBrokenLines();
        message(MessageType::SYS, {"Upgrade Successful!"});
        horizontalBrokenLines();

        return UpgradeResult::SUCCESS;
    } else {
        horizontalBrokenLines();
        message(MessageType::ERROR, {"Not enough gold!"});
        horizontalBrokenLines();

        gold = beforeGold;
        return UpgradeResult::INSUFFICIENT_GOLD;
    }
}

UpgradeResult Player::hpUp (int amount, int price) { 
    return applyStatUp(hp, lvlHp, amount, price); 
}
UpgradeResult Player::atkUp (int amount, int price) {   
    return applyStatUp(atk, lvlAtk, amount, price);
}
UpgradeResult Player::speedUp (int amount, int price) {
    return applyStatUp(speed, lvlSpeed, amount, price);
}