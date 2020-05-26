#ifndef MenuBranch_h_
#define MenuBranch_h_

#include <menus/MenuItem.h>
#include <vector>

class MenuBranch : public MenuItem
{
private:
  std::vector <MenuItem*> _children;
  int _currentChildIndex = 0;
public:
  MenuBranch(String* name);
  MenuItem* getChild(int index);
  void addChild(MenuItem* child);
  MenuItem* getCurrentChild();
  void selectNextChild();
  void selectPreviousChild();
  int getNumberOfChildren();
  int getCurrentChildIndex();
};


#endif //MenuBranch_h_