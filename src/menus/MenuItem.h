#ifndef MenuItem_h_
#define MenuItem_h_

#include <WString.h>

class MenuItem
{
protected:
  String _name;
  MenuItem* _parent = nullptr;
  bool _isHidden = false;
  bool _isMenu = false;

public:
  MenuItem(String name) { _name = name; };

  String getName() {return _name;};
  void setParent(MenuItem* parent) {_parent = parent;};
  MenuItem* getParent() {return _parent;};

  bool isMenu() {return _isMenu;};
  bool isHidden() {return _isHidden;};
  void hide() {_isHidden = true;};
  void unHide() {_isHidden = false;};
};

#endif //MenuItem_h_