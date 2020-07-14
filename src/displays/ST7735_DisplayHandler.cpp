#include <displays/ST7735_DisplayHandler.h>
#include <displays/ST7735_144_128x128_greenTab_Display.h>

String ST7735_DisplayHandler::getMenuPath(MenuBranch* menu) {
  String result = " -";
  MenuBranch* printingMenu = menu;
  while (printingMenu->getParent() != nullptr) {
    result =" - " + printingMenu->getName() + result;
    printingMenu = (MenuBranch*)(printingMenu->getParent());
  }
  return result;
}

void ST7735_DisplayHandler::drawMenuPath(bool isRoot) {
  if (isRoot) {
    display.setCursor(_initXPos + _menuPathXPos, _initYPos + _rootMenuPathYPos);
  } else {
    display.setCursor(_initXPos + _menuPathXPos, _initYPos + _menuPathYPos);
  }
  display.setTextColor(_menuPathColor);
  display.setTextSize(_menuPathTextSize);
  display.print(getMenuPath(_currentMenu));

  if (!isRoot) {
    display.setCursor(_initXPos + _previousMenuPathXPos, _initYPos + _previousMenuPathYPos);
    display.setTextColor(_previousMenuPathColor);
    display.setTextSize(_previousMenuPathTextSize);
    display.print("^");
    display.print(getMenuPath(((MenuBranch*)((MenuBranch*)_currentMenu->getParent())->getPreviousChild())));
    display.print(" ^");

    display.setCursor(_initXPos + _nextMenuPathXPos, _initYPos + _menuChildrenYPos + _currentMenu->getNumberOfChildren()*_menuChildrenYStep + _nextMenuPathYOffset);
    display.setTextColor(_nextMenuPathColor);
    display.setTextSize(_nextMenuPathTextSize);
    display.print("v");
    display.print(getMenuPath(((MenuBranch*)((MenuBranch*)_currentMenu->getParent())->getNextChild())));
    display.print(" v");
  }
}

void ST7735_DisplayHandler::drawMenuChildren(MenuBranch* menu, bool isRoot) {
  int yPos = _initYPos;
  if (isRoot) yPos += _rootMenuChildrenYPos; else yPos += _menuChildrenYPos;
  bool isSelected;
  Serial.println(menu->getNumberOfChildren());
  for (int i = 0; i < menu->getNumberOfChildren(); i++)
  {
    isSelected = (i == menu->getCurrentChildIndex());
    if (isSelected) {
      _currentChild = menu->getChild(i);
      _menuChildrenValueYPos = yPos;
    }
    drawMenuChild(menu->getChild(i), _menuChildrenXPos, yPos, isSelected);
    yPos += _menuChildrenYStep;
  }
};

void ST7735_DisplayHandler::drawMenuChild(MenuItem* item, int xPos, int yPos, bool isSelected) {
  if (isSelected) display.setTextColor(_menuChildrenSelectedColor); else display.setTextColor(_menuChildrenColor);
  display.setCursor(xPos, yPos);
  display.print(item->getName());
  drawMenuChildValue(item, _menuChildrenValueXPos, yPos, isSelected);
};

void ST7735_DisplayHandler::drawMenuChildValue(MenuItem* item, int xPos, int yPos, bool isSelected) {
  if (_currentMenu->getNumberOfChildren() == 0) return;
  if (isSelected) {
    display.setTextColor(_menuChildrenValueSelectedColor);
  } else display.setTextColor(_menuChildrenValueColor);

  display.setCursor(xPos, yPos);
  if (item->isMenu()) {
    display.print("->");
  } else {
    display.print(((MenuLeaf*)item)->getParameter()->getValueString());
  }
};

void ST7735_DisplayHandler::redisplayMenuChildren(bool isRoot) {
  drawMenuChildren(_currentMenu, isRoot);
};

void ST7735_DisplayHandler::redisplaySelectedChildValue() {
  display.fillRect(_menuChildrenValueXPos, _menuChildrenValueYPos, _menuChildrenValueWidth, _menuChildrenValueHeight, BLACK);
  drawMenuChildValue(_currentChild, _menuChildrenValueXPos, _menuChildrenValueYPos, true);
};

ST7735_DisplayHandler::ST7735_DisplayHandler(){
  display.initR(INITR_144GREENTAB);
};

void ST7735_DisplayHandler::displayMenu(MenuBranch* menu, bool isRoot) {
  _currentMenu = menu;
  display.fillScreen(_backgroundColor);
  drawMenuChildren(_currentMenu, isRoot);
  drawMenuPath(isRoot);
};