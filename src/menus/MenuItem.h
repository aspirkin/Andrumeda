#ifndef MenuItem_h_
#define MenuItem_h_

#include <WString.h>

class MenuItem
{
protected:
  String* _name;
  MenuItem* _parent;
  bool _isHidden;
  bool _isMenu = false;
public:
  MenuItem(String* name);
  MenuItem* getParent();
  String* getName();
  void setParent(MenuItem* parent);
  bool isMenu();
  void hide();
  void unHide();
};

#endif //MenuItem_h_