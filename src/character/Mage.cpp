//
// Created by 이승민 on 25. 5. 18.
//
#pragma once
#include "Mage.h"

#include <iostream>
#include <string>
#include "Character.h"

Mage::Mage(std::string& inputName):Character(inputName){
    name = inputName;
    hptype hpGrowth = 19u;
    this->hp = HP(hpGrowth, hpGrowth);
    this->stats = StatBlock(baseStrength,baseIntelligence);
    std::cout<<"You are Mage";
}
