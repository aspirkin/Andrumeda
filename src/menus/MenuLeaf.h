#ifndef MenuLeaf_h_
#define MenuLeaf_h_

#include <menus/MenuItem.h>
#include <parameters/AbstractStatefulParameter.h>

class MenuLeaf : public MenuItem
{
protected:
  AbstractStatefulParameter* _parameter;
public:
  MenuLeaf(String name, AbstractStatefulParameter* parameter) : MenuItem(name) {
    _parameter = parameter;
    _isMenu = false;
  };

  AbstractStatefulParameter* getParameter() {return _parameter;};
};

#endif //MenuItem_h_