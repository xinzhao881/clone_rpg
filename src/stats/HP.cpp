//
// Created by 이승민 on 25. 5. 11.
//
#include "./HP.h"

bool HP::setMaxHP(hptype newMaxHP) {
    if (newMaxHP <= 0) return false;
    maxHP = newMaxHP;
    // currentHP도 maxHP를 넘어가지 않게 조정
    if (currentHP > maxHP) {
        currentHP = maxHP;
    }
    return true;
}

void HP::takeDamage(hptype damage) {
    currentHP -= damage;
    if (currentHP <= 0) {
        currentHP = 0;
    }
}

void HP::heal(hptype heal) {
    currentHP += heal;
    if (currentHP  > maxHP) {
        currentHP = maxHP;
    }
}

hptype HP::getMaxHP() const {
    return this->maxHP;
}

 hptype HP::getCurrentHP() const{
    return currentHP;
}

HP::HP(hptype currentHP, hptype maxHP) {
    this->maxHP = maxHP;
    this->currentHP = (currentHP > maxHP) ? maxHP : currentHP;
}