#include <MenuHandler.h>
#include <DisplayObject.h>

MenuHandler::MenuHandler(MenuBranch* rootMenu, EncoderHandler* encoderHandler) {
  _rootMenu = rootMenu;
  _currentMenu = _rootMenu;
  _encoderHandler = encoderHandler;

  display.initR(INITR_144GREENTAB);

  redraw();
}

void MenuHandler::redraw() {
  display.fillScreen(_backgroundColor);
  drawMenuPath();
  drawMenuChildren();
}

void MenuHandler::drawMenuChildren() {
  int yPos = _initYPos + _menuChildrenYPos;

  MenuItem* currentChild;
  bool isSelected;

  for (int i = 0; i < _currentMenu->getNumberOfChildren(); i++)
  {
    currentChild = _currentMenu->getChild(i);
    isSelected = (i == _currentMenu->getCurrentChildIndex());
    drawMenuItem(currentChild,
                 _menuChildrenXPos,
                 yPos,
                 isSelected);
    yPos += _menuChildrenYStep;

    if (isSelected) setEncoderParameter(currentChild);
  }
  
}

void MenuHandler::setEncoderParameter(MenuItem* item) {
  if (item->isMenu()) {
    _encoderHandler->setParameter(_parameterMock);
  } else {
    _encoderHandler->setParameter((AbstractParameter*)item);
  }
}

void MenuHandler::drawMenuItem(MenuItem* item, int xPos, int yPos, bool isSelected) {
  if (isSelected) {
    display.setTextColor(_menuChildrenSelectedColor);
  } else {
    display.setTextColor(_menuChildrenColor);
  }

  display.setCursor(xPos, yPos);
  display.print(*item->getName());

  drawValue(item, _menuChildrenValueXPos, yPos, isSelected);
}

void MenuHandler::drawValue(MenuItem* item, int xPos, int yPos, bool isSelected) {
  if (isSelected) {
    display.setTextColor(_menuChildrenValueSelectedColor);
  } else {
    display.setTextColor(_menuChildrenValueColor);
  }

  display.setCursor(xPos, yPos);
  if (item->isMenu()) {
    display.print("->");
  } else {
    display.print(((AbstractParameter*)item)->getValue());
  }
}

void MenuHandler::drawMenuPath() {
  String result = "/";
  MenuBranch* printingMenu = _currentMenu;

  while (printingMenu != _rootMenu) {
    result ="/" + *printingMenu->getName() + result;
    printingMenu = (MenuBranch*) printingMenu->getParent();
  }
  
  display.setCursor(_initXPos + _menuPathXPos,
                    _initYPos + _menuPathYPos);
  display.setTextColor(_menuPathColor);
  display.setTextSize(_menuPathTextSize);

  display.print(result);
}

void MenuHandler::selectNextChild() {
  _currentMenu->selectNextChild();
  redraw();
}

void MenuHandler::selectPreviousChild() {
  _currentMenu->selectPreviousChild();
  redraw();
}

void MenuHandler::enterCurrentChild() {
  if (_currentMenu->getCurrentChild()->isMenu()) {
    _currentMenu = (MenuBranch*) _currentMenu->getCurrentChild();
    redraw();
  }
}

void MenuHandler::escapeToParent() {
  if (_currentMenu != _rootMenu) {
    _currentMenu = (MenuBranch*) _currentMenu->getParent();
    redraw();
  }
}
