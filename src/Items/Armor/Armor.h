//
// Created by 이승민 on 25. 11. 23.
//

#ifndef ARMOR_H
#define ARMOR_H
#include "../Item.h"


class Armor : public Item {
public:
    Armor(std::string _id, std::string _name, std::string _description, int _price,
           int _defensePower) : Item(_id, _name, _description, _price), defensePower(_defensePower) {};
    void operator =(const Armor& x);
    bool isValid();
    bool isStackable() override{return false;};
private:
    int defensePower;
};

#endif //ARMOR_H
