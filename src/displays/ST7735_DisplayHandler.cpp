#include <displays/ST7735_DisplayHandler.h>
#include <displays/ST7735_144_128x128_greenTab_Display.h>

void ST7735_DisplayHandler::drawMenuPath(MenuBranch* menu) {
  String result = "/";
  MenuBranch* printingMenu = menu;
  while (printingMenu->getParent() != nullptr) {
    result ="/" + printingMenu->getName() + result;
    printingMenu = (MenuBranch*)(printingMenu->getParent());
  }
  display.setCursor(_initXPos + _menuPathXPos, _initYPos + _menuPathYPos);
  display.setTextColor(_menuPathColor);
  display.setTextSize(_menuPathTextSize);
  display.print(result);
}

void ST7735_DisplayHandler::drawMenuChildren(MenuBranch* menu) {
  int yPos = _initYPos + _menuChildrenYPos;
  MenuItem* currentChild;
  bool isSelected;
  Serial.println(menu->getNumberOfChildren());
  for (int i = 0; i < menu->getNumberOfChildren(); i++)
  {
    currentChild = menu->getChild(i);
    isSelected = (i == menu->getCurrentChildIndex());
    drawMenuChild(currentChild, _menuChildrenXPos, yPos, isSelected);
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
  if (isSelected) display.setTextColor(_menuChildrenValueSelectedColor); else display.setTextColor(_menuChildrenValueColor);
  display.setCursor(xPos, yPos);
  if (item->isMenu()) {
    display.print("->");
  } else {
    display.print(((MenuLeaf*)item)->getParameter()->getValue());
  }
};

ST7735_DisplayHandler::ST7735_DisplayHandler(){
  display.initR(INITR_144GREENTAB);
};

void ST7735_DisplayHandler::displayMenu(MenuBranch* menu) {
  display.fillScreen(_backgroundColor);
  drawMenuPath(menu);
  drawMenuChildren(menu);
};