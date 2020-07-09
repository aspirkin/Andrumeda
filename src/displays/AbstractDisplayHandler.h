#ifndef AbstractDisplayHandler_h_
#define AbstractDisplayHandler_h_

#include <menus/MenuBranch.h>

class AbstractDisplayHandler {
protected:
  // virtual void redraw();
  virtual String getMenuPath(MenuBranch* menu);
  virtual void drawMenuPath();
  virtual void drawMenuChildren(MenuBranch* menu);
  virtual void drawMenuChild(MenuItem* item,int xPos, int yPos, bool isSelected);
  virtual void drawMenuChildValue(MenuItem* item, int xPos, int yPos, bool isSelected);
public:
  virtual void displayMenu(MenuBranch* menu) {};
  virtual void redisplayMenuChildren() {};
  virtual void redisplaySelectedChildValue() {};
};

#endif  //AbstractDisplayHandler_h_