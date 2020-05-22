#ifndef Menu_h_
#define Menu_h_

#include <MenuItem.h>
#include <vector>

class Menu : public MenuItem
{
private:
  //  TODO: Make arrays work & make it add children and retrieve them
  std::vector <MenuItem*> _children;
  int _currentChildIndex;
  // MenuItem* _currentChild;
public:
  Menu(String* name);
  // void enterCurrentChild();
  MenuItem* getChild(int index);
  void addChild(MenuItem* child);
};


#endif //Menu_h_