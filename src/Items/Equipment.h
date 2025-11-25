//
// Created by 이승민 on 25. 11. 25.
//

#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include "Armor.h"
#include "Weapon.h"

class Equipment {
private:
    Armor head;
    Armor upper_body;
    Armor lower_body;
    Weapon weapon;
public:
    Equipment();
    void setHead(const Armor& head) {
        // The Armor::use method (on the Armor *being equipped*) should handle the equipping
        // and inventory management. This method in Equipment should ideally just set the head
        // armor after the inventory swap is handled.
        // this->head.use(head); // Incorrect call given the new Armor::use implementation.
        this->head = head; // Assign directly, assuming inventory swap is handled externally.
        //갈아 끼우면 갈아끼운다고 print해줘야되는데
    }
};
#endif //EQUIPMENT_H
