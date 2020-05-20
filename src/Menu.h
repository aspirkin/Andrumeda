#ifndef Menu_h_
#define Menu_h_

#include <MenuItem.h>

class Menu : public MenuItem
{
private:
  //  TODO: Make arrays work & make it add children and retrieve them
  // MenuItem* _children[];
  // MenuItem* _currentChild;
public:
  Menu(String* name);
  // void enterCurrentChild();
  // MenuItem* previousChild();
  // MenuItem* nextChild();
  void addChild(MenuItem* child);
};


#endif //Menu_h_