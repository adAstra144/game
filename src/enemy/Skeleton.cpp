#include "enemy/Skeleton.hpp"

Skeleton::Skeleton() : Enemy("Skeleton", 30, 5, 15, 30) {}

void Skeleton::resetStats () {
    hp = 30;
    atk = 5;
    speed = 15;
    gold = 30;
}
