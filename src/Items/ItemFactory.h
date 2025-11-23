//
// Created by 이승민 on 25. 11. 23.
//

#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H
#include "Item.h"
#include "Potion.h"
#include "../gameManager/json.hpp"

class ItemFactory {
public:
    static void loadItemDatabase(const nlohmann::json& db);
    static std::unique_ptr<Item> createItemById(const std::string& itemId) {
        const auto& itemData = itemDatabase[itemId];
        const std::string type = itemData["type"];
    if (type == "POTION") {
        auto potion = std::make_unique<Potion>();
        potion->id = itemId["id"];
        potion->name = itemData["name"];
        potion->description = itemData["description"];
        potion->hp_to_restore = itemData["hp_to_restore"];
        return potion;
    }
    else if (type == "WEAPON") {}
    else if (type == "ARMOUR") {}
    };
};
#endif //ITEMFACTORY_H
