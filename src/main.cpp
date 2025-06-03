// main.cpp
#include <iostream>
#include "character/Character.h"
#include "character/Mage.h"
#include "character/Warrior.h"

int main() {

    Character main_character("james");
    int choice;
    std::cout<<"choose 1 or 2\n";
    std::cin>>choice;
    switch (choice) {
        case 1:
            main_character = Mage("james");
            break;
        case 2:
            main_character = Warrior("james");
            break;
    }

    return 0;
}