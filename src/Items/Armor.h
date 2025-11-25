//
// Created by 이승민 on 25. 11. 23.
//

#ifndef ARMOR_H
#define ARMOR_H
#include "Item.h"
#include "../character/Character.h"
#include "../character/Character.h"
#include "../character/Character.h"
#include "../character/Character.h"

class Armor : public Item {
public:
    int defense;
    Armor();
    void use(Character& owner) {
        // Save the currently equipped head armor to inventory
        Armor old_head_armor = owner.equipment.head;
        owner.inventory.emplace_back(old_head_armor);

        // Equip *this* new armor
        owner.equipment.head = *this;
    };
    void operator =(Armor& x) {
        this->defense = x.defense;
    }


};

#endif //ARMOR_H
