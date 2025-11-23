//
// Created by 이승민 on 25. 11. 23.
//

#ifndef POTION_H
#define POTION_H
#include "Item.h"

class Potion : public Item {
public:
    int hp_to_restore;
    void use(Character& owner)override {
        owner.hp.heal(hp_to_restore);
    }
};
#endif //POTION_H
