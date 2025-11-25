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
    const Armor& getHead() const { return head; }
    Armor& getHead() { return head; }
    void setHead(const Armor& newHead) {
        this->head = newHead;
        //갈아 끼우면 갈아끼운다고 print해줘야되는데
    }
};
#endif //EQUIPMENT_H
