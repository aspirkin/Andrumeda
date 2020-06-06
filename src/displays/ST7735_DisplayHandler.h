#ifndef ST7735_DisplayHandler_h_
#define ST7735_DisplayHandler_h_

#include <displays/AbstractDisplayHandler.h>
#include <menus/MenuLeaf.h>

class ST7735_DisplayHandler : public AbstractDisplayHandler {
private:
  const int BLACK    = 0x0000;
  const int BLUE     = 0x001F;
  const int RED      = 0xF800;
  const int GREEN    = 0x07E0;
  const int CYAN     = 0x07FF;
  const int MAGENTA  = 0xF81F;
  const int YELLOW   = 0xFFE0;
  const int WHITE    = 0xFFFF;

  const int _initXPos = 0;
  const int _initYPos = 2;
  const int _backgroundColor = BLACK;

  const int _menuPathXPos = 0;
  const int _menuPathYPos = 0;
  const int _menuPathTextSize = 1;
  const int _menuPathColor = RED;

  const int _menuChildrenXPos = 0;
  const int _menuChildrenYPos = 12;
  const int _menuChildrenYStep = 10;
  const int _menuChildrenColor = WHITE;
  const int _menuChildrenSelectedColor = YELLOW;

  const int _menuChildrenValueXPos = 74;
  const int _menuChildrenValueColor = WHITE;
  const int _menuChildrenValueSelectedColor = GREEN;

  const int _menuChildrenValueWidth = 59;
  const int _menuChildrenValueHeight = 8;
  int _menuChildrenValueYPos;
  MenuBranch* _currentMenu;
  MenuItem* _currentChild;

  void drawMenuPath(MenuBranch* menu);
  void drawMenuChildren(MenuBranch* menu);
  void drawMenuChild(MenuItem* item, int xPos, int yPos, bool isSelected);
  void drawMenuChildValue(MenuItem* item, int xPos, int yPos, bool isSelected);

public:
  ST7735_DisplayHandler();
  void displayMenu(MenuBranch* menu);
  void redisplayMenuChildren();
  void redisplaySelectedChildValue();
};

#endif  //ST7735_DisplayHandler_h_
