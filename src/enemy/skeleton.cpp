#include "enemy/skeleton.h"

skeleton::skeleton() : enemy("Skeleton", 30, 5, 15, 30) {}

void skeleton::resetStats () {
    hp = 30;
    atk = 5;
    speed = 15;
    gold = 30;
}
