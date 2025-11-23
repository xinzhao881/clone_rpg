//
// Created by 이승민 on 25. 11. 23.
//

#ifndef WEAPON_H
#define WEAPON_H
#include "Item.h"

class Weapon : public Item {
public:
    int attack_power;
    void use(Character& owner) override {
        //인벤토리 규칙
    }

};
#endif //WEAPON_H
