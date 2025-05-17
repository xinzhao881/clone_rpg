//
// Created by 이승민 on 25. 5. 11.
//

#include "Character.h"
#include "../stats/hp.h"
#include<string>

#include "../stats/statblock.h"

class warrior : public Character{
public:
    warrior();
    ~warrior();
private:
    static const hptype hpGrowth = static_cast<hptype>(19u);
    static const statType baseStrength = static_cast<hptype>(10u);
    static const statType baseIntelligence = static_cast<hptype>(10u);
    std::string name;

};
