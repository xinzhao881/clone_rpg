//
// Created by 이승민 on 25. 11. 25.
//
#include "Character.h"

#include <algorithm>
#include <iostream>

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

bool Character::isAlive() const {
    return hp.getCurrentHP() > 0;
}

int Character::getCurrentHp() const {
    return hp.getCurrentHP();
}

int Character::getMaxHp() const {
    return hp.getMaxHP();
}

int Character::getStrength() const {
    return stats.getStrength();
}

int Character::getIntelligence() const {
    return stats.getIntelligence();
}

int Character::getAgility() const {
    return stats.getAgility();
}

int Character::getDefense() const {
    return stats.getDefense();
}

int Character::getSpeed() const {
    return 10 + stats.getAgility();
}

int Character::getLevel() const {
    return stats.getLevel();
}

int Character::getExp() const {
    return stats.getExperience();
}

int Character::getExpToNextLevel() const {
    return stats.getExpToNextLevel();
}

int Character::getMaxStamina() const {
    return maxStamina;
}

int Character::getStaminaRegen() const {
    return staminaRegen;
}

void Character::takeDamage(int damage) {
    hp.takeDamage(static_cast<hptype>(std::max(0, damage)));
}

void Character::gainExp(int amount) {
    if (stats.gainExperience(amount)) {
        onLevelUp();
    }
}

void Character::onLevelUp() {
    std::cout << "\nLEVEL UP! " << name << " is now level " << stats.getLevel() << "!" << std::endl;
    // 기본적으로 HP를 약간 올려줌
    hptype currentMax = hp.getMaxHP();
    hp.setMaxHP(currentMax + 10);
    hp.heal(10);
}

const std::vector<Skill>& Character::getSkills() const {
    return skills;
}

int Character::getSkillMasteryLevel(const std::string& skillId) const {
    const auto it = skillMastery.find(skillId);
    if (it == skillMastery.end()) {
        return 0;
    }
    return it->second;
}

void Character::gainSkillMastery(const std::string& skillId, int amount) {
    skillMastery[skillId] += amount;
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
