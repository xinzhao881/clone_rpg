//
// Created by 이승민 on 26. 4. 8..
//

#ifndef CLONE_RPG_STORYMANAGER_H
#define CLONE_RPG_STORYMANAGER_H

#include "../GameManager/json.hpp"
#include "../Common/GameState.h"
#include <optional>
#include <string>
#include <vector>

class StoryManager {
public:
    StoryManager();
    ~StoryManager();
    void initStoryData();
    void showCurrStory(int index);
    struct NextBehavior {
        GameState nextState;
        std::optional<int> nextIndex;
        std::vector<std::string> mobIds;
    };
    NextBehavior getNextBehavior(int index);

private:
    bool shouldTriggerEncounter(const nlohmann::json& encounter) const;
    std::vector<std::string> generateEncounterMobIds(const nlohmann::json& encounter) const;
    std::string selectMobFromPool(const nlohmann::json& mobPool) const;

    nlohmann::json storyData;
    nlohmann::json currentNodeData;
    std::unordered_map<int, bool> hasVisited;
};



#endif //CLONE_RPG_STORYMANAGER_H
