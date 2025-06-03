#include "Warrior.h"

#include <iostream>

#include "Character.h"
//
// Created by 이승민 on 25. 5. 17.
//
Warrior::Warrior(std::string inputName):Character(inputName){
    hptype hpGrowth = 19u;
    hp = HP(hpGrowth, hpGrowth);
    stats = StatBlock(baseStrength,baseIntelligence);
    std::cout<<"You are Warrior!\n";
}

