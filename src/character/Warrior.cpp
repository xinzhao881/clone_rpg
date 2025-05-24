#include "Warrior.h"

#include <iostream>

#include "Character.h"
//
// Created by 이승민 on 25. 5. 17.
//
Warrior::Warrior(std::string& inputName):Character(inputName){
    name = inputName;
    hptype hpGrowth = 19u;
    this->hp = HP(hpGrowth, hpGrowth);
    this->stats = StatBlock(baseStrength,baseIntelligence);
    std::cout<<"You are Warrior";
}

