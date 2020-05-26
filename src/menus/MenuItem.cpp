#include <menus/MenuItem.h>

bool MenuItem::isMenu() {
  return _isMenu;
}

MenuItem::MenuItem(String* name) {
  _name = name;
}

String* MenuItem::getName() {
  return _name;
}

MenuItem* MenuItem::getParent() {
  return _parent;
}

void MenuItem::setParent(MenuItem* parent) {
  _parent = parent;
}

void MenuItem::hide() {
  _isHidden = true;
}

void MenuItem::unHide() {
  _isHidden = false;
}