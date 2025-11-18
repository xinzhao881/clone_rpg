//
// Created by 이승민 on 25. 5. 11.
//
#pragma once
#include "HitPointTypes.h"
class Hp {
public:
    bool setMaxHP(hptype maxHP);
    void takeDamage(hptype damage);
    void heal(hptype heal);
    [[nodiscard]] hptype getMaxHP() const;
    hptype getCurrentHP() const;

    Hp(hptype currentHP, hptype maxHP);
private:
    hptype currentHP;
    hptype maxHP;
};
