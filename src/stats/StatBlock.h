#include <cstdint>
#include <sys/types.h>
//
// Created by 이승민 on 25. 5. 11.
//
#pragma once
typedef std::uint8_t statType; //0에서 255까지 값을 갖는다
class StatBlock {
public:
    StatBlock(statType strength, statType intelligence): level(1), strengthStat(strength),
                                                         intelligenceStat(intelligence), experienceStat(0),
                                                         agilityStat(1), defenseStat(1), insightStat(1), luckStat(1) {};

private:
    statType level;
    statType strengthStat;
    statType intelligenceStat;
    statType experienceStat;
    statType agilityStat;
    statType defenseStat;
    statType insightStat;
    statType luckStat;
};
