#include "warrior.h"
#include "Character.h"
//
// Created by 이승민 on 25. 5. 17.
//
warrior::warrior() : Character() {
    hptype hpGrowth = 19u;
    this->hp = HP(hpGrowth, hpGrowth);
    this->stats = statBlock(10,10);
}
