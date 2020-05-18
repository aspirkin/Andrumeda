#include <MenuItem.h>

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