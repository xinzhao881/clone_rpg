#include <cstdint>
#include <sys/types.h>
//
// Created by 이승민 on 25. 5. 11.
//
typedef std::uint8_t statType;//0에서 255까지 값을 갖는다
struct statBlock {
    statType strengthStat;
    statType dexterityStat;
    statType intelligenceStat;
    statType manaCompatibilityStat;
    statBlock() {
        strengthStat = (statType)10,intelligenceStat = (statType)10,dexterityStat = (statType)10,manaCompatibilityStat = (statType)10;
    }
};

