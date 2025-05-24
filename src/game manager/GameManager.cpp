// GameManager.cpp
#include "GameManager.h"
#include <iostream>

GameManager::GameManager() : isRunning(true) {
    initializeMenu();
}

void GameManager::initializeMenu() {
    rootMenu = std::make_shared<MenuItem>("메인 메뉴");

    // 메인 메뉴 항목들 추가
    auto statusMenu = std::make_shared<MenuItem>("상태 보기", []{
        std::cout << "상태를 표시합니다.\n";
    });

    auto exploreMenu = std::make_shared<MenuItem>("탐험하기");
    auto restMenu = std::make_shared<MenuItem>("휴식하기", []{
        std::cout << "휴식 중...\n";
    });
    auto exitMenu = std::make_shared<MenuItem>("종료", [this]{
        std::cout << "게임을 종료합니다.\n";
        isRunning = false;
    });

    // 탐험 서브메뉴 추가
    auto forest = std::make_shared<MenuItem>("숲으로 가기", []{
        std::cout << "숲으로 들어갑니다...\n";
    });
    auto cave = std::make_shared<MenuItem>("동굴 탐험하기", []{
        std::cout << "동굴로 들어갑니다...\n";
    });
    exploreMenu->addChild(forest);
    exploreMenu->addChild(cave);

    // 메인 메뉴에 항목들 추가
    rootMenu->addChild(statusMenu);
    rootMenu->addChild(exploreMenu);
    rootMenu->addChild(restMenu);
    rootMenu->addChild(exitMenu);

    currentMenu = rootMenu;
}

void GameManager::run() {
    while (isRunning) {
        showMenu(currentMenu);

        int input;
        std::cin >> input;

        handleInput(input, currentMenu);

        std::cout << "\n\n";
    }
}

void GameManager::showMenu(const std::shared_ptr<MenuItem>& menu) {
    std::cout << "====== " << menu->getTitle() << " ======\n";

    const auto& children = menu->getChildren();
    for (size_t i = 0; i < children.size(); ++i) {
        std::cout << (i + 1) << ". " << children[i]->getTitle() << "\n";
    }

    if (menu != rootMenu) {
        std::cout << "0. 뒤로 가기\n";
    }

    std::cout << "======================\n";
    std::cout << "선택: ";
}

void GameManager::handleInput(int choice, const std::shared_ptr<MenuItem>& menu) {
    const auto& children = menu->getChildren();

    if (choice == 0 && menu != rootMenu) {
        currentMenu = rootMenu;
        return;
    }

    if (choice < 1 || choice > children.size()) {
        std::cout << "잘못된 선택입니다.\n";
        return;
    }

    auto selectedItem = children[choice - 1];

    if (!selectedItem->getChildren().empty()) {
        currentMenu = selectedItem;
    } else {
        selectedItem->execute();
    }
}