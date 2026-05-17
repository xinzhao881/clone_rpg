//
// Created by 이승민 on 25. 11. 23.
//
#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <utility>

class Character;

class Item {
public:
    Item(std::string _id, std::string _name, std::string _description, int _price) : id(std::move(_id)),
        name(std::move(_name)), description(std::move(_description)), price(_price) {
    } ;
    virtual ~Item() = default;

    virtual void use(Character& owner);
    const std::string& getName() const;
    const std::string& getDescription() const;
    int getPrice() const;
    int getId() const;
    virtual bool isStackable() = 0;
protected:
    std::string id;
    std::string name;
    std::string description;
    int price;
};
#endif //ITEM_H
