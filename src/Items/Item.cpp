#include "Item.h"

Item::Item() : id(""), name(""), description("") {
    // Default constructor
}

Item::~Item() {
    // Virtual destructor
}

void Item::use(Character& owner) {
    // Base implementation, does nothing or can be made pure virtual
}
