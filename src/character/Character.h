#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>

#include "../stats/HP.h"
#include "../stats/StatBlock.h"

class Character {
protected:
    HP hp;
    std::string name;
    StatBlock stats;

public:
    // 순수 가상 소멸자
    virtual ~Character() = default;
    Character(std::string inputName): name(inputName), hp(10,10), stats(10,10) {};

/*
    // 순수 가상 함수들
    virtual void attack() = 0;
    virtual void specialAbility() = 0;

    // 공통 기능들
    virtual void takeDamage(hptype damage) { hp.takeDamage(damage); }
    virtual void heal(hptype heal) { hp.heal(heal); }
    virtual hptype getCurrentHP() const { return hp.getCurrentHP(); }
*/
};


#endif //CHARACTER_H