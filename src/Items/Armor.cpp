#include "Armor.h"
#include "../character/Character.h"

Armor::Armor() : defense(0) {
    // Default constructor
}

void Armor::use(Character& owner) {
    // Save the currently equipped head armor to inventory
    Armor old_head_armor = owner.equipment.getHead();
    owner.inventory.emplace_back(old_head_armor);

    // Equip *this* new armor
    owner.equipment.setHead(*this);
}
