//
// Created by 이승민 on 26. 3. 28.
//

#ifndef SHOP_H
#define SHOP_H
#include "../character/Character.h"
#include "../GameManager/json.hpp"
class Shop {
private:
    int userChoice;
    nlohmann::json shopData;
public:
    Shop() = default;
    ~Shop() = default;
    void initShopData();
    //루프 걸어서 받아야됨
    void enter(Character& character);
    void leave();
    void buy(Character& character);
    void sell(Character& character);

//여기도 stateMachine만들어서 처리 shop, Battle,story에 전부
};
#endif //SHOP_H
