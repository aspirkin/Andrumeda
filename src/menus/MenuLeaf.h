#ifndef MenuLeaf_h_
#define MenuLeaf_h_

#include <menus/MenuItem.h>
#include <parameters/StatefulParameter.h>

class MenuLeaf : public MenuItem
{
protected:
  StatefulParameter* _parameter;
public:
  MenuLeaf(String name, StatefulParameter* parameter) : MenuItem(name) {
    _parameter = parameter;
    _isMenu = false;
  };

  StatefulParameter* getParameter() {return _parameter;};
};

#endif //MenuItem_h_