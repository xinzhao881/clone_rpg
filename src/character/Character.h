//
// Created by 이승민 on 25. 5. 17.
//


#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>

#include "../stats/hp.h"
#include "../stats/statBlock.h"
class Character {
protected:
    HP hp;
    std::string name;
    //hptype hpGrowth; 나중에 레벨업 구현할때 사용하겠음
    statBlock stats;

public:
    Character(): hp(10,10), stats(10,10) {
    }

     ~Character() = default;  // 가상 소멸자

    // 순수 가상 함수들
    // virtual void attack() = 0;
    // virtual void specialAbility() = 0;

    // 공통 기능들
    void takeDamage(hptype damage) { hp.takeDamage(damage); }
    void heal(hptype heal) { hp.heal(heal); }
    hptype getCurrentHP() const { return hp.getCurrentHP(); }
};
#endif //CHARACTER_H
