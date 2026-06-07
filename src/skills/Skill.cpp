#include "Skill.h"

#include <unordered_map>
#include <fstream>
#include <iostream>
#include "../GameManager/json.hpp"

namespace {
std::unordered_map<std::string, Skill> skillMap;
bool isLoaded = false;

SkillType stringToSkillType(const std::string& type) {
    if (type == "Damage") return SkillType::Damage;
    if (type == "Wait") return SkillType::Wait;
    if (type == "Recover") return SkillType::Recover;
    return SkillType::Damage;
}

ScalingStat stringToScalingStat(const std::string& stat) {
    if (stat == "Strength") return ScalingStat::Strength;
    if (stat == "Intelligence") return ScalingStat::Intelligence;
    return ScalingStat::Strength;
}
}

void SkillBook::init() {
    if (isLoaded) return;

    std::ifstream f("skills.json");
    if (!f.is_open()) {
        std::cerr << "Could not open skills.json" << std::endl;
        return;
    }

    try {
        auto data = nlohmann::json::parse(f);
        if (data.contains("skills")) {
            for (auto& [id, details] : data["skills"].items()) {
                skillMap[id] = Skill{
                    id,
                    details.value("name", "unknown"),
                    stringToSkillType(details.value("type", "Damage")),
                    stringToScalingStat(details.value("stat", "Strength")),
                    details.value("power", 0),
                    details.value("time_cost", 0),
                    details.value("min_time_cost", 0),
                    details.value("stamina_cost", 0),
                    details.value("min_stamina_cost", 0),
                    details.value("accuracy", 0)
                };
            }
        }
        isLoaded = true;
    } catch (const std::exception& e) {
        std::cerr << "Error parsing skills.json: " << e.what() << std::endl;
    }
}

const Skill* SkillBook::findById(const std::string& skillId) {
    auto it = skillMap.find(skillId);
    if (it != skillMap.end()) {
        return &(it->second);
    }
    return nullptr;
}

std::vector<Skill> SkillBook::defaultSkillsForWarrior() {
    std::vector<Skill> result;
    if (const auto* s = findById("slash")) result.push_back(*s);
    if (const auto* s = findById("heavy_slash")) result.push_back(*s);
    if (const auto* s = findById("wait")) result.push_back(*s);
    return result;
}

std::vector<Skill> SkillBook::defaultSkillsForMage() {
    std::vector<Skill> result;
    if (const auto* s = findById("fireball")) result.push_back(*s);
    if (const auto* s = findById("wait")) result.push_back(*s);
    return result;
}
