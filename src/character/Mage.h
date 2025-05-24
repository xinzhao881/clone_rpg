//
// Created by 이승민 on 25. 5. 18.
//

#ifndef MAGE_H
#define MAGE_H
#include <string>

#include "Character.h"

class Mage : public Character {
public:
    Mage(std::string& inputName);
    ~Mage() = default;
private:
    static const statType baseStrength = 10u;
    static const statType baseIntelligence =10u;
    std::string name;
};
#endif //MAGE_H
