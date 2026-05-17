//
// Created by 이승민 on 25. 11. 30.
//

#ifndef GOLD_H
#define GOLD_H
class Gold {
private:
    int totalGold;
public:
    Gold();
    int getTotalGold();
    void increaseGold(int value);
    void decreaseGold(int value);
};
#endif //GOLD_H
