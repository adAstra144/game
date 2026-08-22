#include "enemy/Enemy.hpp"

// Create Enemies By Using enemy(Name, HP, ATTACK, SPEED, GOLD)
Enemy::Enemy(std::string name, int hp, int atk, int speed, int gold) {
    this->name = name;
    this->hp = hp;
    this->atk = atk;
    this->speed = speed;
    this->gold = gold;
}

void Enemy::takeDamage (int amount) {
    hp -= amount; 
}
void Enemy::specialMove (int turnCount) {
    
}


void Enemy::setHp (int hp) {
    this->hp = hp;
}


int Enemy::getHp () {
    return hp;
}
int Enemy::getAtk () {
    return atk;
}
int Enemy::getSpeed() {
    return speed;
}
int Enemy::getGold () {
    return gold;
}
