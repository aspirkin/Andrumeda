#include <Menu.h>

Menu::Menu(String name) : MenuItem(name) {

}

void Menu::addChild(MenuItem* child) {
  //  TODO: add child to array

  child->setParent(this);
}