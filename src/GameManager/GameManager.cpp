#include "GameManager.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include "../Items/ItemFactory.h"
#include "../Shop/Shop.h"
#include "../Story/StoryManager.h"

GameManager::GameManager(std::shared_ptr<Character> playerCharacter)
    : isRunning(true), state(GameState::STORY), currentNode(1), player(std::move(playerCharacter)) {
    loadStory();
}

void GameManager::loadStory() {
    std::ifstream f("story.json");
    if (f.is_open()) {
        storyData = nlohmann::json::parse(f);
    } else {
        std::cerr << "Could not open story.json" << std::endl;
        isRunning = false;
    }
}

void GameManager::run() {
    while (isRunning) {
        switch (state) {
            case GameState::STORY:
                handleStoryState();
                break;
            case GameState::MENU:
                // Placeholder
                handleMenuState();
                std::cout << "Menu not implemented yet." << std::endl;
                state = GameState::EXIT;
                break;
            case GameState::BATTLE:
                // Placeholder
                std::cout << "Battle not implemented yet." << std::endl;
                handleBattleState();
                break;
            case GameState::SHOP:
                // Placeholder
                handleShopState(*player);
                break;
            case GameState::EXIT:
                isRunning = false;
                break;
        }
    }
    std::cout << "Thanks for playing!" << std::endl;
}

void GameManager::handleStoryState() {
    StoryManager storyManager;
    int userChoice;

    storyManager.showCurrStory(currentNode);
    std::cout << "> ";
    std::cin >> userChoice;

    if (std::cin.fail()) {
        std::cout << "Invalid choice. Please try again." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    auto nextBehavior = storyManager.getNextBehavior(userChoice);

    if (nextBehavior.nextIndex.has_value()) {
        currentNode = nextBehavior.nextIndex.value();
    }

    currentBattleMobIds = nextBehavior.mobIds;
    state = nextBehavior.nextState;
}
void GameManager::handleMenuState() {
}


void GameManager::handleBattleState() {
    if (!currentBattleMobIds.empty()) {
        std::cout << "Encounter triggered. Spawned mobs:" << std::endl;
        for (const auto& mobId : currentBattleMobIds) {
            std::cout << "- mob_id: " << mobId << std::endl;
        }
        currentBattleMobIds.clear();
    }

    state=GameState::STORY;
}

void GameManager::handleShopState(Character& character) {
    Shop shop;
    shop.enter(character);
    state = GameState::STORY;
}
int GameManager::getCharacterGold() {
    return player->getTotalGold();
}

void GameManager::decreaseCharacterGold(int value) {
    player->decreaseGold(value);
}

void GameManager::increaseCharacterGold(int value) {
    player->increaseGold(value);
}
void GameManager::viewPlayerInventory() {
    player->viewInventory();
}

Item & GameManager::getItemByIndex(int index) {
    return player->getItemByIndex(index);
}

int GameManager::getInventorySize() {
    return player->getInventorySize();
}
