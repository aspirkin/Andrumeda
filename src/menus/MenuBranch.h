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

  MenuItem* getPreviousChild() {
    if (_children.size() == 0) return nullptr;
    if (_currentChildIndex == 0) {
      return getChild((int)_children.size() - 1);
    } else {
      return getChild(_currentChildIndex - 1);
    }
  }

  MenuItem* getNextChild() {
    if (_children.size() == 0) return nullptr;
    if (_currentChildIndex == (int)_children.size() - 1) {
      return getChild(0);
    } else {
      return getChild(_currentChildIndex + 1);
    }
  }

  MenuItem* getCurrentChild() {
    if (_children.size() == 0) return nullptr;
    return getChild(_currentChildIndex);
  };

  int getCurrentChildIndex() {return _currentChildIndex;};

  void setFirstChildCurrent() {_currentChildIndex = 0;};

  void setLastChildCurrent() {_currentChildIndex = (int)_children.size() - 1;};

  bool selectNextChild() {
    if (_children.size() == 0) return false;
    _currentChildIndex++;
    if ((_currentChildIndex + 1) > (int)_children.size()) _currentChildIndex = 0;
    return true;
  };

  bool selectPreviousChild() {
    if (_children.size() == 0) return false;
    _currentChildIndex--;
    if (_currentChildIndex < 0) _currentChildIndex = _children.size() - 1;
    return true;
  };
};


#endif //MenuBranch_h_