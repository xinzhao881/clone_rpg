#include "Equipment.h"

Equipment::Equipment() : armor("", "", "", 0, 0), weapon("", "", "", 0, 0) {
    // Default constructor
}

bool Equipment::isArmorValid() {
    return armor.isValid();
}


Armor&& Equipment::getArmor() {
    return std::move(armor);
}

Weapon&& Equipment::getWeapon() {
    return std::move(weapon);
}


bool Equipment::isWeaponValid() {
    return weapon.isValid();
}
