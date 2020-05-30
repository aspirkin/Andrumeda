#include <MenuHandler.h>

MenuHandler::MenuHandler(MenuBranch* rootMenu, EncoderHandler* encoderHandler) {
  _rootMenu = rootMenu;
  _currentMenu = _rootMenu;
  _encoderHandler = encoderHandler;

  _displayHandler = new ST7735_DisplayHandler();
  _displayHandler->displayMenu(_currentMenu);
}

void MenuHandler::setEncoderParameter(MenuItem* item) {
  if (item == nullptr) {
    _encoderHandler->setParameter(_parameterMock);
  } else if (item->isMenu()) {
    _encoderHandler->setParameter(_parameterMock);
  } else {
    _encoderHandler->setParameter(((MenuLeaf*)item)->getParameter());
  }
}

void MenuHandler::updateDisplay() {
  _displayHandler->displayMenu(_currentMenu);
  setEncoderParameter(_currentMenu->getCurrentChild());
}

void MenuHandler::selectNextChild() {
  if (_currentMenu->selectNextChild()) updateDisplay();
}

void MenuHandler::selectPreviousChild() {
  if (_currentMenu->selectPreviousChild()) updateDisplay();
}

void MenuHandler::enterCurrentChild() {
  if (_currentMenu->getCurrentChild() == nullptr) return;
  if (_currentMenu->getCurrentChild()->isMenu()) {
    _currentMenu = (MenuBranch*) _currentMenu->getCurrentChild();
    updateDisplay();
  }
}

void MenuHandler::escapeToParent() {
  if (_currentMenu != _rootMenu) {
    _currentMenu = (MenuBranch*) _currentMenu->getParent();
    updateDisplay();
  }
}
