#ifndef __MENU_H__
#define __MENU_H__

#include <string>
#include <vector>
#include <functional>

class Button {
public:
    Button(
        std::string name,
        const std::function<void()> setup,
        const std::function<void()> update
    ): name(name), setup(setup), update(update) {}
private:
    std::string name;
    std::function<void()> setup;
    std::function<void()> update;
};

class Category {
public:
    Category(std::string name) : name(name) {}
    std::string name;
    std::vector<Button*> buttons;
};

class Menu {
public:
    Menu();
    
    void setup();
    void update();

    void addCategory(std::string name);
    void addButton(
        std::string name,
        std::string category,
        std::function<void()> setup,
        std::function<void()> update
    );
    void addToggle(
        std::string name,
        std::string category,
        std::function<void()> enable,
        std::function<void()> disable,
        std::function<void()> update
    );
private:
    std::vector<Category> categories;
    int width, height;
};

#endif
