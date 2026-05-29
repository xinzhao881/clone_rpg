#ifndef CHARACTER_H
#define CHARACTER_H
#include <map>
#include <memory>
#include <string>
#include <vector>
#include "../Items/Equipment.h"
#include "../Items/Item.h"
#include "../skills/Skill.h"
#include "../stats/Hp.h"
#include "../stats/StatBlock.h"
#include "../Gold/Gold.h"
struct InventoryEntry {
    std::unique_ptr<Item> item;
    int quantity;
};
using Inventory = std::vector<InventoryEntry>;
class Character {
public:
    // 순수 가상 소멸자
    virtual ~Character() = default;
    Character(std::string inputName = "john"): name(inputName), hp(10,10), stats(10,10), gold() {};
    std::string getName() const { return name; }
    void equip(Armor& armor);
    void equip(Weapon& weapon);
    void healHp(hptype heal);
    bool isAlive() const;
    int getCurrentHp() const;
    int getMaxHp() const;
    int getStrength() const;
    int getIntelligence() const;
    int getAgility() const;
    int getDefense() const;
    int getSpeed() const;
    int getMaxStamina() const;
    int getStaminaRegen() const;
    void takeDamage(int damage);
    const std::vector<Skill>& getSkills() const;
    int getSkillMasteryLevel(const std::string& skillId) const;
    void gainSkillMastery(const std::string& skillId, int amount);
    void addItem(std::unique_ptr<Item>&& item, int quantity_);
    void removeItem(int index);
    void decreaseGold(int value);
    void increaseGold(int value);
     int getTotalGold();
    void viewInventory();
    Item& getItemByIndex(int index);
    int getInventorySize();
    bool searchForItem(Item& item);
protected:
    std::string name;
    Hp hp;
    StatBlock stats;
    Inventory inventory;
    Equipment equipment;
    Gold gold;
    std::vector<Skill> skills;
    std::map<std::string, int> skillMastery;
    int maxStamina = 100;
    int staminaRegen = 3;
};


#endif //CHARACTER_H
