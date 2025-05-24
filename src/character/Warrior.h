//
// Created by 이승민 on 25. 5. 11.
//
#pragma once
#include "Character.h"
#include "../stats/HP.h"
#include<string>

#include "../stats/StatBlock.h"

class Warrior : public Character{
public:
    Warrior(std::string& inputName);
    ~Warrior();
private:
    static const statType baseStrength = 10u;
    static const statType baseIntelligence =10u;
    std::string name;

};
