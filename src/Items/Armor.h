//
// Created by 이승민 on 25. 11. 23.
//

#ifndef ARMOR_H
#define ARMOR_H
#include "Item.h"

class Character; // Forward declaration to break circular dependency

class Armor : public Item {
public:
    int defense;
    Armor();
    void use(Character& owner); // Declaration only
    Armor& operator =(const Armor& x) {
        if (this == &x) {
            return *this;
        }
        Item::operator=(x);
        this->defense = x.defense;
        return *this;
    }


};

#endif //ARMOR_H
