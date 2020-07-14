#ifndef AbstractDisplayHandler_h_
#define AbstractDisplayHandler_h_

#include <menus/MenuBranch.h>

class AbstractDisplayHandler {
protected:
  // virtual void redraw();
  virtual String getMenuPath(MenuBranch* menu);
  virtual void drawMenuPath(bool isRoot = false);
  virtual void drawMenuChildren(MenuBranch* menu, bool isRoot = false);
  virtual void drawMenuChild(MenuItem* item,int xPos, int yPos, bool isSelected);
  virtual void drawMenuChildValue(MenuItem* item, int xPos, int yPos, bool isSelected);
public:
  virtual void displayMenu(MenuBranch* menu, bool isRoot = false) {};
  virtual void redisplayMenuChildren(bool isRoot = false) {};
  virtual void redisplaySelectedChildValue() {};
};

#endif  //AbstractDisplayHandler_h_