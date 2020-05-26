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
  MenuBranch(String name) : MenuItem(name) {
    _isMenu = true;
    _currentChildIndex = 0;
  };

  void addChild(MenuItem* child) {
    child->setParent(this);
    _children.push_back(child);
  };

  MenuItem* getChild(int index) {return _children[index];};
  int getNumberOfChildren() {return _children.size();};

  MenuItem* getCurrentChild() {return getChild(_currentChildIndex);};
  int getCurrentChildIndex() {return _currentChildIndex;};

  void selectNextChild() {
    _currentChildIndex++;
    if ((_currentChildIndex + 1) > _children.size()) _currentChildIndex = 0;
  };

  void selectPreviousChild() {
    _currentChildIndex--;
    if (_currentChildIndex < 0) _currentChildIndex = _children.size() - 1;
  };
};


#endif //MenuBranch_h_