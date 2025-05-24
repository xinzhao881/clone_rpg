// MenuItem.h
#pragma once
#include <string>
#include <vector>
#include <functional>
#include <memory>

class MenuItem {
public:
    MenuItem(const std::string& title, std::function<void()> action = nullptr) 
        : title(title), action(action) {}

    void addChild(std::shared_ptr<MenuItem> child) {
        children.push_back(child);
    }

    void execute() {
        if (action) {
            action();
        }
    }

    const std::string& getTitle() const { return title; }
    const std::vector<std::shared_ptr<MenuItem>>& getChildren() const { return children; }

private:
    std::string title;
    std::function<void()> action;
    std::vector<std::shared_ptr<MenuItem>> children;
};