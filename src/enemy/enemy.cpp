#include "enemy/enemy.hpp"

// Create Enemies By Using enemy(Name, HP, ATTACK, SPEED, GOLD)
enemy::enemy(std::string name, int hp, int atk, int speed, int gold) {
    this->name = name;
    this->hp = hp;
    this->atk = atk;
    this->speed = speed;
    this->gold = gold;
}

void enemy::takeDamage (int amount) {
    hp -= amount; 
}
void enemy::specialMove (int turnCount) {
    
}


void enemy::setHp (int hp) {
    this->hp = hp;
}


int enemy::getHp () {
    return hp;
}
int enemy::getAtk () {
    return atk;
}
int enemy::getSpeed() {
    return speed;
}
int enemy::getGold () {
    return gold;
}
