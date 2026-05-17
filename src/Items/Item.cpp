#include "Item.h"
#include "../character/Character.h"

void Item::use(Character& owner) {
    // Base implementation, does nothing or can be made pure virtual
}

const std::string& Item::getName() const {
    return name;
}

int Item::getPrice() const {
    return price;
}
