#include <menus/MenuBranch.h>

MenuBranch::MenuBranch(String* name) : MenuItem(name) {
  _isMenu = true;
  _currentChildIndex = 0;
}

int MenuBranch::getCurrentChildIndex() {
  return _currentChildIndex;
}

int MenuBranch::getNumberOfChildren() {
  return _children.size();
}

void MenuBranch::selectPreviousChild() {
  _currentChildIndex--;
  if (_currentChildIndex < 0) _currentChildIndex = _children.size() - 1;
}

void MenuBranch::selectNextChild() {
  _currentChildIndex++;
  if ((_currentChildIndex + 1) > _children.size()) _currentChildIndex = 0;
}

MenuItem* MenuBranch::getCurrentChild() {
  return getChild(_currentChildIndex);
}

void MenuBranch::addChild(MenuItem* child) {
  child->setParent(this);
  _children.push_back(child);
}

MenuItem* MenuBranch::getChild(int index) {
  return _children[index];
}