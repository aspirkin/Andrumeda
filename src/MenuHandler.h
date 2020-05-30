#ifndef MenuHandler_h_
#define MenuHandler_h_

#include <menus/MenuBranch.h>
#include <menus/MenuLeaf.h>
#include <parameters/AbstractParameter.h>
#include <parameters/StatefulParameter.h>
#include <EncoderHandler.h>
#include <displays/ST7735_DisplayHandler.h>

class MenuHandler
{
private:
//  TODO: Extract display specific logic away
  MenuBranch* _rootMenu;
  MenuBranch* _currentMenu;
  AbstractDisplayHandler* _displayHandler;
  AbstractParameter* _parameterMock = new AbstractParameter();
  EncoderHandler* _encoderHandler;
  void setEncoderParameter(MenuItem* item);
  void updateDisplay();

public:
  MenuHandler(MenuBranch* rootMenu, EncoderHandler* encoderHandler);
  void enterCurrentChild();
  void escapeToParent();
  void selectNextChild();
  void selectPreviousChild();
};

#endif //MenuHandler_h_