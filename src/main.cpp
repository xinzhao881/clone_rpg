#include <iostream>
#include <memory>
#include "character/Character.h"
#include "character/Mage.h"
#include "character/Warrior.h"
#include "gameManager/GameManager.h"


#include <iostream>
#include <memory>
#include "character/Character.h"
#include "character/Mage.h"
#include "character/Warrior.h"
#include "gameManager/GameManager.h"

int main() {
    std::string name;
    int choice = 0;

    std::cout << "Welcome to RPG Game!" << std::endl;
    std::cout << "Give me a name:" << std::endl;
    std::cin >> name;

    std::shared_ptr<Character> myCharacter;
    std::cout << "Choose your job:" << std::endl;
    std::cout << "1. Warrior\n" << "2. Mage\n";
    std::cin >> choice;

    switch (choice) {
        case 1:
            myCharacter = std::make_shared<Warrior>(name);
            break;
        case 2:
            myCharacter = std::make_shared<Mage>(name);
            break;
        default:
            std::cout << "Invalid choice, starting as a Warrior." << std::endl;
            myCharacter = std::make_shared<Warrior>(name);
            break;
    }

    std::cout << "Welcome " << myCharacter->getName() << std::endl; // Assumes a getName() method

    auto gameManager = std::make_shared<GameManager>();
    gameManager->run();

    return 0;
}
