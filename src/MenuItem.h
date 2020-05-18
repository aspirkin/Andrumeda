#ifndef MenuItem_h_
#define MenuItem_h_

#include <WString.h>

class MenuItem
{
protected:
  String* _name;
  bool _isHidden;
  MenuItem* _parent;
public:
  MenuItem(String* name);
  void hide();
  void unHide();
  MenuItem* getParent();
  String* getName();
  void setParent(MenuItem* parent);
};

#endif //MenuItem_h_