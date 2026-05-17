//
// Created by 이승민 on 25. 11. 23.
//

#ifndef POTION_H
#define POTION_H
#include "Item.h"

class Potion : public Item {
public:
    Potion(std::string _id, std::string _name, std::string _description, int _price,
           int _hpToRestore) : Item(_id, _name, _description, _price), hpToRestore(_hpToRestore) {};
    bool isStackable() override{return true;};
private:
    int hpToRestore;
};
#endif //POTION_H
