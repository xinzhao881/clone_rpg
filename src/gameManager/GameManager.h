//
// Created by 이승민 on 25. 6. 3.
//

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <memory>
#include "../character/Character.h"
#include "json.hpp"

enum class GameState {
    MENU,
    STORY,
    BATTLE,
    SHOP,
    EXIT
};

class GameManager {
public:
    GameManager();
    void run();

private:
    void loadStory();
    void handleStoryState();
    void loadBattle();
    void handleBattleState();
    void handleMenuState();
    void loadShop();
    void handleShopState();
    void loadExit();
    void handleExitState();


    GameState state;
    bool isRunning;
    std::shared_ptr<Character> player;
    nlohmann::json storyData;
    int currentNode;
};

#endif //GAMEMANAGER_H
