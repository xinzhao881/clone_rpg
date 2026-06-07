//
// Created by 이승민 on 26. 4. 8..
//

#include "StoryManager.h"

#include <fstream>
#include <iostream>
#include <random>

StoryManager::StoryManager() {
    initStoryData();
}

StoryManager::~StoryManager() = default;

void StoryManager::initStoryData() {
    std::ifstream f("story.json");
    if (f.is_open()) {
        storyData = nlohmann::json::parse(f);
    }
    hasVisited.clear();
}

void StoryManager::showCurrStory(int index) {
    bool foundNode = false;
    for ( const auto & node : storyData["story"]) {
        if (node["node_number"] == index) {
            currentNodeData = node;
            foundNode = true;
            break;
        }
    }
    if (!foundNode) {
        std::cerr << "Story node not found" << std::endl;
        return;
    }

    std::cout << "\n------------------------------------\n";
    if (!hasVisited[index]) {
        if (currentNodeData.contains("story") && !currentNodeData["story"].is_null()) {
            std::cout << currentNodeData["story"] << "\n\n";
        }
        hasVisited[index] = true;
    }

    std::cout << currentNodeData["description"] << std::endl;
    std::cout << "\n------------------------------------\n";
    const auto &choices = currentNodeData["choices"];
    int choiceIndex = 1;
    for (const auto &choice : choices) {
        if (choice.contains("text") && !choice["text"].empty()) {
            std::cout << choiceIndex++ << ". " << choice["text"] << std::endl;
        }
    }
}

StoryManager::NextBehavior StoryManager::getNextBehavior(int index) {
    StoryManager::NextBehavior nextBehavior;
    nextBehavior.nextState = GameState::STORY;

    if (!currentNodeData.contains("choices")) {
        return nextBehavior;
    }

    const auto& choices = currentNodeData["choices"];
    if (index < 1 || index > static_cast<int>(choices.size())) {
        std::cerr << "Invalid choice index" << std::endl;
        return nextBehavior;
    }

    const auto& choice = choices[index - 1];
    const std::string function = choice.value("function", "");

    if (function == "Move") {
        if (choice.contains("next_node") && !choice["next_node"].is_null()) {
            nextBehavior.nextIndex = choice["next_node"].get<int>();
        }
        if (choice.contains("encounter") && shouldTriggerEncounter(choice["encounter"])) {
            nextBehavior.nextState = GameState::BATTLE;
            nextBehavior.mobIds = generateEncounterMobIds(choice["encounter"]);
            return nextBehavior;
        }
        nextBehavior.nextState = GameState::STORY;
    }
    else if (function == "Battle") {
        if (choice.contains("next_node") && !choice["next_node"].is_null()) {
            nextBehavior.nextIndex = choice["next_node"].get<int>();
        }
        nextBehavior.nextState = GameState::BATTLE;
        if (choice.contains("Mobs")) {
            for (const auto& id : choice["Mobs"]) {
                nextBehavior.mobIds.push_back(id);
            }
        }
    }
    else if (function == "Shop") {
        nextBehavior.nextState = GameState::SHOP;
    }

    return nextBehavior;
}

bool StoryManager::shouldTriggerEncounter(const nlohmann::json& encounter) const {
    const double triggerChance = encounter.value("trigger_chance", 0.0);

    static std::random_device rd;
    static std::mt19937 generator(rd());
    std::bernoulli_distribution distribution(triggerChance);

    return distribution(generator);
}

std::vector<std::string> StoryManager::generateEncounterMobIds(const nlohmann::json& encounter) const {
    std::vector<std::string> mobIds;

    if (!encounter.contains("mob_count") || !encounter.contains("mob_pool")) {
        return mobIds;
    }

    const auto& mobCount = encounter["mob_count"];
    const int minCount = mobCount.value("min", 1);
    const int maxCount = mobCount.value("max", minCount);

    static std::random_device rd;
    static std::mt19937 generator(rd());
    std::uniform_int_distribution<int> countDistribution(minCount, maxCount);
    const int spawnCount = countDistribution(generator);

    for (int i = 0; i < spawnCount; ++i) {
        const std::string mobId = selectMobFromPool(encounter["mob_pool"]);
        if (!mobId.empty()) {
            mobIds.push_back(mobId);
        }
    }

    return mobIds;
}

std::string StoryManager::selectMobFromPool(const nlohmann::json& mobPool) const {
    if (!mobPool.is_array() || mobPool.empty()) {
        return "";
    }

    std::vector<int> weights;
    weights.reserve(mobPool.size());
    for (const auto& mobEntry : mobPool) {
        weights.push_back(mobEntry.value("weight", 0));
    }

    static std::random_device rd;
    static std::mt19937 generator(rd());
    std::discrete_distribution<int> distribution(weights.begin(), weights.end());
    const auto& selectedMob = mobPool[distribution(generator)];

    if (selectedMob.contains("mob_id")) {
        if (selectedMob["mob_id"].is_string()) {
            return selectedMob["mob_id"].get<std::string>();
        }
        return std::to_string(selectedMob["mob_id"].get<int>());
    }

    return "";
}
