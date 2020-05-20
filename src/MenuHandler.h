#ifndef MenuHandler_h_
#define MenuHandler_h_

#include <Menu.h>
#include <AbstractParameter.h>

class MenuHandler
{
private:
  Menu* _rootMenu;
  Menu* _currentMenu;
  void redraw();
  void drawMenuPath();
  void drawChildren();
public:
  MenuHandler(Menu* rootMenu);
  void enterChild();
  void escapeToParent();
  void nextChild();
  void previousChild();
};

#endif //MenuHandler_h_