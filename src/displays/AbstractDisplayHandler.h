#ifndef AbstractDisplayHandler_h_
#define AbstractDisplayHandler_h_

#include <menus/MenuBranch.h>

class AbstractDisplayHandler {
protected:
  // virtual void redraw();
  virtual void drawMenuPath(MenuBranch* menu);
  virtual void drawMenuChildren(MenuBranch* menu);
  virtual void drawMenuChild(MenuItem* item,int xPos, int yPos, bool isSelected);
  virtual void drawMenuChildValue(MenuItem* item, int xPos, int yPos, bool isSelected);
public:
  virtual void displayMenu(MenuBranch* menu) {};
};

#endif  //AbstractDisplayHandler_h_