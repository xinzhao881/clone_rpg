//
// Created by 이승민 on 25. 5. 11.
//
#pragma once
#include "hitpointtypes.h"
class HP {
public:
    bool setMaxHP(hptype maxHP);
    void takeDamage(hptype damage);
    void heal(hptype heal);
    hptype getMaxHP();
    hptype getCurrentHP() const;

    HP(hptype currentHP, hptype maxHP);
private:
    hptype currentHP;
    hptype maxHP;
};
