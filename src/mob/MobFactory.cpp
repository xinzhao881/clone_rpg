//
// Created by 이승민 on 25. 12. 14.
//

#include "MobFactory.h"

#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "Mob.h"

std::unique_ptr<Mob> MobFactory::createMobById(const std::string& mobId) {
    std::ifstream f("mobs.json");
    if (!f.is_open()) {
        std::cerr << "Could not open mobs.json" << std::endl;
        return nullptr;
    }

    const auto mobData = nlohmann::json::parse(f);
    if (!mobData.contains("mobs") || !mobData["mobs"].contains(mobId)) {
        std::cerr << "Mob not found: " << mobId << std::endl;
        return nullptr;
    }

    const auto& data = mobData["mobs"][mobId];
    const int maxHp = data.value("hp", 10);
    StatBlock stats(
            static_cast<statType>(data.value("str", 1)),
            static_cast<statType>(data.value("int", 1))
    );
    stats.setAgility(static_cast<statType>(data.value("agi", 1)));
    stats.setDefense(static_cast<statType>(data.value("def", 1)));

    std::vector<Skill> skills;
    if (data.contains("skills")) {
        for (const auto& skillId : data["skills"]) {
            const Skill* skill = SkillBook::findById(skillId.get<std::string>());
            if (skill != nullptr) {
                skills.push_back(*skill);
            }
        }
    }
    if (skills.empty()) {
        const Skill* waitSkill = SkillBook::findById("wait");
        if (waitSkill != nullptr) {
            skills.push_back(*waitSkill);
        }
    }

    return std::make_unique<Mob>(
            data.value("id", mobId),
            data.value("name", "unknown"),
            Hp(static_cast<hptype>(maxHp), static_cast<hptype>(maxHp)),
            stats,
            skills,
            data.value("exp", 0)
    );
}
