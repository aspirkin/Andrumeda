#ifndef Scale_h_
#define Scale_h_

#include <WString.h>

class Scale
{
private:
  static const int NUMBER_OF_STEPS = 9;
  int _steps[NUMBER_OF_STEPS];
  String _name;
public:
  Scale(String name, int steps[NUMBER_OF_STEPS]) {
    _name = name;
    for (int i=0; i<NUMBER_OF_STEPS; i++) _steps[i] = steps[i];
  }

  String getName() {
    return _name;
  }

  int getStep(int index) {
    if (index >= NUMBER_OF_STEPS) return _steps[NUMBER_OF_STEPS-1];
    return _steps[index];
  }
};

#endif  //Scale_h_