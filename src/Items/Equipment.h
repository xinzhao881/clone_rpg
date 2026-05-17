//
// Created by 이승민 on 25. 11. 25.
//

#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include "Armor/Armor.h"
#include "Weapon/Weapon.h"

class Equipment {
private:
    Armor armor;
    Weapon weapon;
public:
    Equipment();
    bool isArmorValid();
    bool isWeaponValid();

    Armor&& getArmor();

    Weapon&& getWeapon();
};
#endif //EQUIPMENT_H
