#include "Armor.h"

// The constructor is now inline in Armor.h, so no definition is needed here.

// Definition for the assignment operator
void Armor::operator=(const Armor &x) {
    // Call the base class assignment operator
    Item::operator=(x);
    // Copy the derived class members
    this->defensePower = x.defensePower;
}

// Definition for isValid
bool Armor::isValid() {
    // id, name, description are protected in Item
    if (!id.empty() && !name.empty() && !description.empty() && defensePower > 0) {
        return true;
    }
    return false;
}
