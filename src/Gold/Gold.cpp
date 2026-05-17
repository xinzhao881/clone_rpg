//
// Created by 이승민 on 25. 11. 30.
//
#include "Gold.h"

void Gold::increaseGold(int value) {
    totalGold += value;
};
void Gold::decreaseGold(int value) {
    totalGold -= value;
}
int Gold::getTotalGold() {
    return totalGold;
}
Gold::Gold() : totalGold(0) {}
