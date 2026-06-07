//
// Created by 이승민 on 25. 6. 3.
//

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <memory>
#include <string>
#include <vector>
#include "../character/Character.h"
#include "json.hpp"
#include "../Common/GameState.h"

#include "../Story/StoryManager.h"

class GameManager {
public:
    GameManager(std::shared_ptr<Character> playerCharacter);
    void run();
    void handleStoryState();
    void loadBattle();
    void handleBattleState();
    void handleMenuState();
    void handleShopState(Character& character);
    void loadExit();
    void handleExitState();
    void handleBuyItem();
    void handleSellItem();
    int getCharacterGold();
    void decreaseCharacterGold(int value);
    void increaseCharacterGold(int value);
    void addItem(Item& item);
    void removeItem(int index);
    void viewPlayerInventory();
    Item& getItemByIndex(int index);
    int getInventorySize();

private:
    GameState state;
    bool isRunning;
    std::shared_ptr<Character> player;
    nlohmann::json shopData;
    int currentNode;
    std::vector<std::string> currentBattleMobIds;
    StoryManager storyManager;
};

#endif //GAMEMANAGER_H
