#ifndef MapParameter_h_
#define MapParameter_h_

#include <parameters/StatefulParameter.h>
#include <WString.h>
#include <functional>
#include <map>
#include <vector>

typedef std::function<void(int)> SetterFunction;
typedef std::map<int, String> ValuesMap;

class MapParameter : public StatefulParameter
{
protected:
  ValuesMap _values;
  std::vector<int> _keysVector;
  int _index;

  void handleValueOverTop() {
    if (_isCyclic) _index = 0; else _index = _keysVector.size() - 1;
  }

  void handleValueBelowBottom() {
    if (_isCyclic) _index = _keysVector.size() - 1; else _index = 0;
  }

  void apply() {
    _setterFunction(_keysVector[_index]);
  }

public:
  MapParameter(
    SetterFunction setterFunction,
    ValuesMap values,
    int initialIndex,
    bool isCyclic = false,
    String units = ""
    ) : StatefulParameter(setterFunction, isCyclic, units)
  {
    _values = values;
    ValuesMap::iterator it = _values.begin();
    while (it != _values.end())
    {
      _keysVector.push_back(it->first);
      it++;
    }
    _index = initialIndex;
    apply();
  }

  void increase() {
    _index++;
    if (_index >= int(_keysVector.size())) handleValueOverTop();
    apply();
  }

  void decrease() {
    _index--;
    if (_index < 0) handleValueBelowBottom();
    apply();
  }

  String getValueString() {
    return String(_values[_keysVector[_index]]) + _units;
  }

};

#endif  //MapParameter_h_