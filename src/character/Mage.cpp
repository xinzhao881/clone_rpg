//
// Created by 이승민 on 25. 5. 18.
//
#include "Mage.h"

#include <iostream>
#include <string>
#include "Character.h"

Mage::Mage(std::string inputName) : Character(inputName) {
    hptype hpGrowth = 19u;
    hp = Hp(hpGrowth, hpGrowth);
    stats = StatBlock(baseStrength, baseIntelligence);
    stats.setAgility(7);
    stats.setDefense(3);
    skills = SkillBook::defaultSkillsForMage();
    for (const auto& skill : skills) {
        skillMastery[skill.id] = 0;
    }
    std::cout<<"You are Mage!\n";
}

void Mage::onLevelUp() {
    Character::onLevelUp();
    stats.setIntelligence(stats.getIntelligence() + 2);
    stats.setInsight(stats.getInsight() + 1);
    std::cout << "Intelligence +2, Insight +1" << std::endl;
}
