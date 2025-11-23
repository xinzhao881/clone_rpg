//
// Created by 이승민 on 25. 11. 23.
//

#ifndef ITEM_H
#define ITEM_H
#include "../character/Character.h"


class Item {
public:
    Item();
    virtual ~Item();
    virtual void use(Character& owner) = 0;
private:
    std::string id;
    std::string name;
    std::string description;
};
#endif //ITEM_H
