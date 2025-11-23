//
// Created by 이승민 on 25. 11. 23.
//

#ifndef ACCESSORY_H
#define ACCESSORY_H
#include "Item.h"

class Accessory : public Item {
    public:
     Accessory();
    void use(Character &owner) override {
        //장착하는 로ㄷ
    };
};
#endif //ACCESSORY_H
