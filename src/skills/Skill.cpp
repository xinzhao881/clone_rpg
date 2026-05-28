#include "Skill.h"

#include <array>

namespace {
const std::array<Skill, 4> skills = {
        Skill{"slash", "베기", SkillType::Damage, ScalingStat::Strength, 5, 100, 60, 20, 8, 90},
        Skill{"heavy_slash", "강한 베기", SkillType::Damage, ScalingStat::Strength, 10, 140, 90, 35, 18, 80},
        Skill{"firebolt", "파이어볼트", SkillType::Damage, ScalingStat::Intelligence, 8, 120, 75, 28, 12, 85},
        Skill{"wait", "숨 고르기", SkillType::Recover, ScalingStat::Strength, 12, 60, 60, 0, 0, 100}
};
}

const Skill* SkillBook::findById(const std::string& skillId) {
    for (const auto& skill : skills) {
        if (skill.id == skillId) {
            return &skill;
        }
    }
    return nullptr;
}

std::vector<Skill> SkillBook::defaultSkillsForWarrior() {
    return {*findById("slash"), *findById("heavy_slash"), *findById("wait")};
}

std::vector<Skill> SkillBook::defaultSkillsForMage() {
    return {*findById("firebolt"), *findById("wait")};
}
