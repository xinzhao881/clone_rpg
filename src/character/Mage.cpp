//
// Created by 이승민 on 25. 5. 18.
//
#include "Mage.h"

#include <iostream>
#include <string>
#include "Character.h"

Mage::Mage(std::string inputName) : Character(inputName) {
    hptype hpGrowth = 19u;
    hp = HP(hpGrowth, hpGrowth);
    stats = StatBlock(baseStrength, baseIntelligence);
    std::cout<<"You are Mage!\n";
}