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

void Warrior::onLevelUp() {
    Character::onLevelUp();
    stats.setStrength(stats.getStrength() + 2);
    stats.setAgility(stats.getAgility() + 1);
    std::cout << "Strength +2, Agility +1" << std::endl;
}
