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
    [[nodiscard]] statType getLevel() const { return level; }
    [[nodiscard]] statType getStrength() const { return strengthStat; }
    [[nodiscard]] statType getIntelligence() const { return intelligenceStat; }
    [[nodiscard]] statType getAgility() const { return agilityStat; }
    [[nodiscard]] statType getDefense() const { return defenseStat; }
    [[nodiscard]] statType getInsight() const { return insightStat; }
    [[nodiscard]] statType getLuck() const { return luckStat; }
    [[nodiscard]] int getExperience() const { return experienceStat; }
    [[nodiscard]] int getExpToNextLevel() const { return level * 50; }

    void setLevel(statType _level) { level = _level; }
    void setStrength(statType strength) { strengthStat = strength; }
    void setIntelligence(statType intelligence) { intelligenceStat = intelligence; }
    void setAgility(statType agility) { agilityStat = agility; }
    void setDefense(statType defense) { defenseStat = defense; }
    void setInsight(statType insight) { insightStat = insight; }
    void setLuck(statType luck) { luckStat = luck; }

    bool gainExperience(int amount) {
        experienceStat += amount;
        bool leveledUp = false;
        while (experienceStat >= getExpToNextLevel()) {
            experienceStat -= getExpToNextLevel();
            level++;
            leveledUp = true;
        }
        return leveledUp;
    }

private:
    statType level;
    statType strengthStat;
    statType intelligenceStat;
    int experienceStat;
    statType agilityStat;
    statType defenseStat;
    statType insightStat;
    statType luckStat;
};
