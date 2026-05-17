//
// Created by 이승민 on 25. 11. 25.
//
#include "Character.h"

#include <iostream>
#include <__ostream/basic_ostream.h>

void Character::equip(Weapon& weapon) {
    if (!equipment.isWeaponValid()) {
        equip(weapon);
    }
    else {
        //인벤토리에 지금 갖고있는거 emplace하고 갈아끼우기
        addItem(std::make_unique<Weapon>(equipment.getWeapon()),1);
        equipment.getWeapon() = weapon;
    }
}
void Character::equip(Armor &armor) {
    if (!equipment.isArmorValid()) {
        equip(armor);
    }
    else {
        addItem(std::make_unique<Armor>(equipment.getArmor()),1);
        equipment.getArmor() = armor;
    }
}
void Character::healHp(hptype heal) {
    this->hp.heal(heal);
}

void Character::addItem(std::unique_ptr<Item>&& item, int quantity_) {
    for (auto& entry: inventory) {
        if (entry.item->getName() == item->getName() && entry.item->isStackable()) {
            entry.quantity+=quantity_;
        }
    }
        inventory.push_back({std::move(item), 1});
}

void Character::removeItem(int index) {
    inventory.erase(inventory.begin() + index - 1);
}
void Character::increaseGold(int value) {
    gold.increaseGold(value);
}

int Character::getTotalGold() {
    return gold.getTotalGold();
}

void Character::viewInventory() {
    if (inventory.empty()) {
        std::cerr << "Empty inventory" << std::endl;
    }
    else {
        for (int i = 0; i < inventory.size(); i++) {
            std::cout << i + 1 << ": " <<inventory[i].item->getName() << std::endl;
        }
    }
}

Item& Character::getItemByIndex(int index) {
    return *inventory[index].item;
}

int Character::getInventorySize() {
    return inventory.size();
}

bool Character::searchForItem(Item &item) {// index를 반환해야되나

    for (const auto& entry : inventory) {
        if (entry.item->getName() == item.getName()) {
            return true;
        }
    }
    return false;
}

void Character::decreaseGold(int value) {
    gold.decreaseGold(value);
}
