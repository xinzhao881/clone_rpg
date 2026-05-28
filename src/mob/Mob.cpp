#include "Mob.h"

#include <algorithm>
#include <utility>

Mob::Mob(std::string id, std::string name, Hp hp, StatBlock stats, std::vector<Skill> skills)
    : id(std::move(id)), name(std::move(name)), hp(hp), stats(stats), skills(std::move(skills)) {
    for (const auto& skill : this->skills) {
        skillMastery[skill.id] = 0;
    }
}

std::string Mob::getId() const {
    return id;
}

std::string Mob::getName() const {
    return name;
}

bool Mob::isAlive() const {
    return hp.getCurrentHP() > 0;
}

int Mob::getCurrentHp() const {
    return hp.getCurrentHP();
}

int Mob::getMaxHp() const {
    return hp.getMaxHP();
}

int Mob::getStrength() const {
    return stats.getStrength();
}

int Mob::getIntelligence() const {
    return stats.getIntelligence();
}

int Mob::getAgility() const {
    return stats.getAgility();
}

int Mob::getDefense() const {
    return stats.getDefense();
}

int Mob::getSpeed() const {
    return 10 + stats.getAgility();
}

int Mob::getMaxStamina() const {
    return maxStamina;
}

int Mob::getStaminaRegen() const {
    return staminaRegen;
}

void Mob::takeDamage(int damage) {
    hp.takeDamage(static_cast<hptype>(std::max(0, damage)));
}

const std::vector<Skill>& Mob::getSkills() const {
    return skills;
}

int Mob::getSkillMasteryLevel(const std::string& skillId) const {
    const auto it = skillMastery.find(skillId);
    if (it == skillMastery.end()) {
        return 0;
    }
    return it->second;
}

void Mob::gainSkillMastery(const std::string& skillId, int amount) {
    skillMastery[skillId] += amount;
}
