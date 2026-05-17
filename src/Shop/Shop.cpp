//
// Created by 이승민 on 26. 3. 28.
//

#include "Shop.h"
#include "../Items/ItemFactory.h"
#include <fstream>
#include <iostream>
#include <memory>
#include<string>
void Shop::initShopData() {
    std::ifstream f("Items.json");
    if (f.is_open()) {
        shopData = nlohmann::json::parse(f);
    }
}

void Shop::buy(Character& character) {
    for (const auto& [id,item] : shopData["items"].items()) {
        std::cout<< id << ": " << item["name"].get<std::string>() <<"/ 가격:" << item["price"].get<int>() <<  std::endl;
    }
    std::cout<< "어떤 물건을 구매할까요?"<<std::endl;
    std::cin>> userChoice;
    //userChoice번호대로 Item객체 생성 아니면 스마트 포인터 생성
    auto generatedItem = ItemFactory::createItemById(std::to_string(userChoice),shopData);
    int itemPrice = generatedItem->getPrice();
    int itemCount = 1;
    if (generatedItem->isStackable()) {
        std::cout << "몇개를 구매할까요?" << std::endl;
        std::cin >> itemCount;
        itemPrice *= itemCount;
    }
    if (character.getTotalGold() >= itemPrice) {
        character.decreaseGold(itemPrice);
        character.addItem(std::move(generatedItem),itemCount);
    }
    else {
        std::cout << "돈이 부족합니다." << std::endl;
    }

}
void Shop::sell(Character& character) {
    if (character.getInventorySize() == 0) {
        std::cout << "판매할 물품이 없습니다." << std::endl;
    }
    else {
        character.viewInventory();
        std::cout << "어떤 물건을 판매할까요?" << std::endl;//에러 발생하면
        std::cin >> userChoice;//index대로 removeItem호출하고 increaseGold
        if (userChoice > character.getInventorySize() || userChoice < 0) {
            std::cout << "유효하지 않은 물건입니다." << std::endl;
            }
        else {
            character.increaseGold(character.getItemByIndex(userChoice - 1).getPrice());
            character.removeItem(userChoice - 1);
            }
        }
}
void Shop::enter(Character& character) {
    //일단 shopItems초기화하기 : 이거도 사실 나중에는 레벨, 스토리 진행도에 따라서 아이템이 해금될거다. 루프로 처리하도록
    initShopData();
    std::cout << "\n------------------------------------\n";
    std::cout << "상점의 주인 그리멀은 당신을 맞아줍니다.\n 어이, 살거야? 팔거야?\n";
    std::cout << "\n------------------------------------";
    while (true) {
        std::cout << "\n------------------------------------\n";
        std::cout << "1: 구매한다" << std::endl;
        std::cout << "2: 판매한다" << std::endl;
        std::cout << "3: 상점에서 나간다" << std::endl;
        std::cout << "\n------------------------------------\n";
        std::cin >> userChoice;

        switch (userChoice) {
            case 1: {
                buy(character);
                break;
            }
            case 2: {
                sell(character);
                break;
            }
            case 3: {
                return;

            }
            default:
                std::cout << "그리멀을 당신을 째려봅니다. 어이 구매할거야 판매할거야? 하나만 해"<< std::endl;
        }
    }
}
