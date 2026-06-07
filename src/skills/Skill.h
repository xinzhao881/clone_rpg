#ifndef SKILL_H
#define SKILL_H

#include <string>
#include <vector>

enum class SkillType {
    Damage,
    Wait,
    Recover
};

enum class ScalingStat {
    Strength,
    Intelligence
};

struct Skill {
    std::string id;
    std::string name;
    SkillType type;
    ScalingStat scalingStat;
    int basePower;
    int baseTimeCost;
    int minTimeCost;
    int baseStaminaCost;
    int minStaminaCost;
    int accuracy;
};

class SkillBook {
public:
    static void init();
    static const Skill* findById(const std::string& skillId);
    static std::vector<Skill> defaultSkillsForWarrior();
    static std::vector<Skill> defaultSkillsForMage();
};

#endif //SKILL_H
