//
// Created by 이승민 on 25. 11. 23.
//

#ifndef ARMOR_H
#define ARMOR_H
#include "../character/Character.h"

class Armor : public Character {
public:
    int defense;
    Armor();
    void use(Character& owner) {

    };

};

#endif //ARMOR_H
