//
// Created by 이승민 on 25. 11. 23.
//

#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H
#include "Item.h"
#include "Potion.h"
#include "../GameManager/json.hpp"

class ItemFactory {
public:
    static std::unique_ptr<Item> createItemById(const std::string& itemId, nlohmann::json& db);
};
#endif //ITEMFACTORY_H
