#include <Menu.h>

Menu::Menu(String* name) : MenuItem(name) {

}

void Menu::addChild(MenuItem* child) {
  _children.push_back(child);
  child->setParent(this);
}

MenuItem* Menu::getChild(int index) {
  return _children[index];
}