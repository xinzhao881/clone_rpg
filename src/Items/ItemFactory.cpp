//
// Created by 이승민 on 25. 11. 30.
//
#include "ItemFactory.h"

#include "Weapon/Weapon.h"
#include "Armor/Armor.h"
#include "Potion.h"

std::unique_ptr<Item> ItemFactory::createItemById(const std::string &itemId, nlohmann::json &db) {
    // Use the itemId parameter to find the correct item in the database
    if (!db["items"].contains(itemId)) {
        return nullptr; // Item not found
    }
    auto itemData = db["items"][itemId];
    std::string itemType = itemData["type"];

    if (itemType == "WEAPON") {
        // Create a unique_ptr to the derived class Weapon
        // It will be implicitly converted to std::unique_ptr<Item> upon return
        return std::make_unique<Weapon>(itemData["id"], itemData["name"], itemData["description"], itemData["price"],
                                        itemData["attack"]);
    } else if (itemType == "ARMOR") {
        return std::make_unique<Armor>(itemData["id"], itemData["name"], itemData["description"], itemData["price"],
                                        itemData["defense"]);
    } else if (itemType == "POTION") {
        return std::make_unique<Potion>(itemData["id"], itemData["name"], itemData["description"], itemData["price"],
                                        itemData["hpToRestore"]);
    }

    // Return a null pointer if the item type is not recognized
    return nullptr;
}
