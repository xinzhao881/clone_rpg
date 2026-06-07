#ifndef MOB_H
#define MOB_H

#include <map>
#include <string>
#include <vector>
#include "../skills/Skill.h"
#include "../stats/Hp.h"
#include "../stats/StatBlock.h"

class Mob {
public:
    Mob(std::string id, std::string name, Hp hp, StatBlock stats, std::vector<Skill> skills, int expReward = 0);

    std::string getId() const;
    std::string getName() const;
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

private:
    std::string id;
    std::string name;
    Hp hp;
    StatBlock stats;
    std::vector<Skill> skills;
    std::map<std::string, int> skillMastery;
    int maxStamina = 80;
    int staminaRegen = 2;
    int expReward = 0;
};

#endif //MOB_H
MOB_H
