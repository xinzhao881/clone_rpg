#include "GameManager.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include "../Battle/BattleManager.h"
#include "../Items/ItemFactory.h"
#include "../mob/MobFactory.h"
#include "../Shop/Shop.h"
#include "../Story/StoryManager.h"
#include "../skills/Skill.h"

GameManager::GameManager(std::shared_ptr<Character> playerCharacter)
    : isRunning(true), state(GameState::STORY), currentNode(1), player(std::move(playerCharacter)) {
    SkillBook::init();
}

void GameManager::run() {
    while (isRunning) {
        switch (state) {
            case GameState::STORY:
                handleStoryState();
                break;
            case GameState::MENU:
                handleMenuState();
                std::cout << "Menu not implemented yet." << std::endl;
                state = GameState::EXIT;
                break;
            case GameState::BATTLE:
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
    if (currentBattleMobIds.empty()) {
        currentBattleMobIds.push_back("BattleDummy");
    }

    std::vector<std::unique_ptr<Mob>> mobs;
    for (const auto& mobId : currentBattleMobIds) {
        auto mob = MobFactory::createMobById(mobId);
        if (mob != nullptr) {
            mobs.push_back(std::move(mob));
        }
    }
    currentBattleMobIds.clear();

    BattleManager battleManager(*player, std::move(mobs));
    const bool won = battleManager.run();
    state = won ? GameState::STORY : GameState::EXIT;
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
