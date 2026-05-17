//
// Created by 이승민 on 25. 11. 30.
//

#ifndef MOBFACTORY_H
#define MOBFACTORY_H
#include "Mob.h"
#include "../GameManager/json.hpp"

class MobFactory {
public:
    static std::unique_ptr<Mob> createMobById(const std::string& mobId);


};
#endif //MOBFACTORY_H
