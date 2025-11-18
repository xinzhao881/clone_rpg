//
// Created by 이승민 on 25. 5. 11.
//
#include "./Hp.h"

bool Hp::setMaxHP(hptype newMaxHP) {
    if (newMaxHP <= 0) return false;
    maxHP = newMaxHP;
    // currentHP도 maxHP를 넘어가지 않게 조정
    if (currentHP > maxHP) {
        currentHP = maxHP;
    }
    return true;
}

void Hp::takeDamage(hptype damage) {
    currentHP -= damage;
    if (currentHP <= 0) {
        currentHP = 0;
    }
}

void Hp::heal(hptype heal) {
    currentHP += heal;
    if (currentHP  > maxHP) {
        currentHP = maxHP;
    }
}

hptype Hp::getMaxHP() const {
    return this->maxHP;
}

 hptype Hp::getCurrentHP() const{
    return currentHP;
}

Hp::Hp(hptype currentHP, hptype maxHP) {
    this->maxHP = maxHP;
    this->currentHP = (currentHP > maxHP) ? maxHP : currentHP;
}