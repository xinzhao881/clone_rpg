#include "Warrior.h"

#include <iostream>

#include "Character.h"
//
// Created by 이승민 on 25. 5. 17.
//
Warrior::Warrior(std::string inputName):Character(inputName){
    hptype hpGrowth = 19u;
    hp = Hp(hpGrowth, hpGrowth);
    stats = StatBlock(baseStrength,baseIntelligence);
    stats.setAgility(8);
    stats.setDefense(5);
    skills = SkillBook::defaultSkillsForWarrior();
    for (const auto& skill : skills) {
        skillMastery[skill.id] = 0;
    }
    std::cout<<"You are Warrior!\n";
}
