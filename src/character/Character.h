//
// Created by 이승민 on 25. 5. 17.
//


#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>

#include "../stats/hp.h"
#include "../stats/statblock.h"
class Character {
protected:
    HP hp;
    std::string name;
    hptype HP_GROWTH;
    statBlock stats;

public:
    Character();

    virtual ~Character() = default;  // 가상 소멸자

    // 순수 가상 함수들
    virtual void attack() = 0;
    virtual void specialAbility() = 0;

    // 공통 기능들
    void takeDamage(hptype damage) { hp.takeDamage(damage); }
    void heal(hptype heal) { hp.heal(heal); }
    hptype getCurrentHP() const { return hp.getCurrentHP(); }
};
#endif //CHARACTER_H
