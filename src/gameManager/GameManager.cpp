#include "GameManager.h"
#include <fstream>
#include <iostream>

GameManager::GameManager()
    : isRunning(true), state(GameState::STORY), currentNode(1) {
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
                //handleMenuState();
                std::cout << "Menu not implemented yet." << std::endl;
                state = GameState::EXIT;
                break;
            case GameState::BATTLE:
                // Placeholder
                std::cout << "Battle not implemented yet." << std::endl;
                state = GameState::EXIT;
                break;
            case GameState::SHOP:
                // Placeholder
                std::cout << "Shop not implemented yet." << std::endl;
                state = GameState::EXIT;
                break;
            case GameState::EXIT:
                isRunning = false;
                break;
        }
    }
    std::cout << "Thanks for playing!" << std::endl;
}

void GameManager::handleStoryState() {
    if (storyData.is_null() || !storyData.contains("story")) {
        std::cerr << "Story data is missing or invalid." << std::endl;
        state = GameState::EXIT;
        return;
    }
    nlohmann::json currentNodeData;
    bool foundNode = false;
    for (const auto& node : storyData["story"]) {
        if (node["node_number"] == currentNode) {
            currentNodeData = node;
            foundNode = true;
            break;
        }
    }

    if (!foundNode) {
        std::cerr << "Error: Story node " << currentNode << " not found." << std::endl;
        state = GameState::EXIT;
        return;
    }

    std::cout << "\n------------------------------------\n";
    std::cout << currentNodeData["description"].get<std::string>() << std::endl;
    std::cout << "------------------------------------\n";


    if (currentNodeData.contains("choices") && !currentNodeData["choices"].is_null() && !currentNodeData["choices"].empty()) {
        const auto& choices = currentNodeData["choices"];
        int choiceNum = 1;
        auto totalchoices = choices.size();
        for (const auto& choice : choices) {
            if(choice.contains("text") && !choice["text"].empty()){
                 std::cout << choiceNum++ << ". " << choice["text"] << std::endl;
            }
        }

        int userChoice;
        std::cout << "> ";
        std::cin >> userChoice;

        if (std::cin.fail() || userChoice < 1 || userChoice >= choiceNum) {
            std::cout << "Invalid choice. Please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }

        const auto& selectedChoice = choices[userChoice - 1];
        if (selectedChoice.contains("next_node")) {
            currentNode = selectedChoice["next_node"];
        } else {
            std::cout << "This path leads nowhere. The story ends." << std::endl;
            state = GameState::EXIT;
        }
    } else {
        std::cout << "The story concludes here." << std::endl;
        state = GameState::EXIT;
    }
}

void GameManager::handleMenuState(){}
