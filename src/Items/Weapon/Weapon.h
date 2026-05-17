//
// Created by 이승민 on 25. 11. 23.
//

#ifndef WEAPON_H
#define WEAPON_H
#include "../Item.h"

class Weapon : public Item {
public:
    bool isValid();

    Weapon(std::string _id, std::string _name, std::string _description, int _price,
           int _attackPower) : Item(_id, _name, _description, _price), attackPower(_attackPower) {};
    bool isStackable() override{return false;};
private:
    int attackPower;
};
#endif //WEAPON_H
