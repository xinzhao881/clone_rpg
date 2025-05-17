//
// Created by 이승민 on 25. 5. 11.
//

#include "Character.h"
#include "../stats/hp.h"
#include<string>

#include "../stats/statBlock.h"

class warrior : public Character{
public:
    warrior();
    ~warrior();
private:
    static const statType baseStrength = 10u;
    static const statType baseIntelligence =10u;
    std::string name;

};
