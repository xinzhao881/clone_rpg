//
// Created by 이승민 on 25. 11. 26.
//
#include "Weapon.h"

bool Weapon::isValid() {
    if (!id.empty() and !name.empty() and !description.empty() and attackPower) {
        return true;
    }
    return false;
}