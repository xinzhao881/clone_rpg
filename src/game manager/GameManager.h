// GameManager.h
#pragma once
#include "MenuItem.h"
#include <memory>

class GameManager {
public:
    GameManager();
    void run();

private:
    void initializeMenu();
    void showMenu(const std::shared_ptr<MenuItem>& currentMenu);
    void handleInput(int choice, const std::shared_ptr<MenuItem>& currentMenu);

    bool isRunning;
    std::shared_ptr<MenuItem> rootMenu;
    std::shared_ptr<MenuItem> currentMenu;
};