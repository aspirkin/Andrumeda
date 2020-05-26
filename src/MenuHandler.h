#ifndef MenuHandler_h_
#define MenuHandler_h_

#include <menus/MenuBranch.h>
#include <parameters/AbstractParameter.h>
#include <EncoderHandler.h>

class MenuHandler
{
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

  const int _menuChildrenValueXPos = 100;
  const int _menuChildrenValueColor = WHITE;
  const int _menuChildrenValueSelectedColor = GREEN;

  MenuBranch* _rootMenu;
  MenuBranch* _currentMenu;
  void redraw();
  void drawMenuPath();
  void drawMenuChildren();
  void drawMenuItem(MenuItem* item,int xPos, int yPos, bool isSelected);
  void drawValue(MenuItem* item, int xPos, int yPos, bool isSelected);

  AbstractParameter* _parameterMock = new AbstractParameter(new String());
  EncoderHandler* _encoderHandler;
  void setEncoderParameter(MenuItem* item);
public:
  MenuHandler(MenuBranch* rootMenu, EncoderHandler* encoderHandler);
  void enterCurrentChild();
  void escapeToParent();
  void selectNextChild();
  void selectPreviousChild();
};

#endif //MenuHandler_h_