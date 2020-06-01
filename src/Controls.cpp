#include <Controls.h>

Controls::Controls(int numberOfMusicNodes, int numberOfEncoders, MenuBranch* rootMenu, AbstractDisplayHandler* displayHandler) {
  _numberOfMusicNodes = numberOfMusicNodes;
  _numberOfEncoders = numberOfEncoders;

  _rootMenu = rootMenu;
  _currentMenu = _rootMenu;

  _displayHandler = displayHandler;
  _displayHandler->displayMenu(_currentMenu);
}

void Controls::addNavigationEncoder(int pinS, int pinA, int pinB){
  _navigationEncoderHandler = addCommonEncoder(pinS, pinA, pinB);
  _navigationEncoderHandler->setClickFunction(std::bind(&Controls::escapeToParent, this));
  _navigationEncoderHandler->setParameter(_navigationParameter);
}

void Controls::addConfigurationEncoder(int pinS, int pinA, int pinB){
  _configurationEncoderHandler = addCommonEncoder(pinS, pinA, pinB);
  _configurationEncoderHandler->setClickFunction(std::bind(&Controls::enterCurrentChild, this));
  _configurationEncoderHandler->setParameter(_configurationParameter);
}

EncoderHandler* Controls::addCommonEncoder(int pinS, int pinA, int pinB){
  EncoderHandler* newEncoderHandler = new EncoderHandler(pinS, pinA, pinB);
  _ptrEncoderHandlers.push_back(newEncoderHandler);
  return newEncoderHandler;

}

void Controls::addMusicSensor(int pin) {
  _ptrMusicSensorHandlers.push_back(new SensorHandler(pin));
}

SensorHandler* Controls::getMusicSensorHandler(int index) {
  return _ptrMusicSensorHandlers[index];
}

EncoderHandler* Controls::getEncoderHandler(int index) {
  return _ptrEncoderHandlers[index];
}

void Controls::update() {
  //Serial.println("controls update");
  for (int i = 0; i < _numberOfMusicNodes; i++)
  {
    _ptrMusicSensorHandlers[i]->update();
  }

  for (int i = 0; i < _numberOfEncoders; i++)
  {
    _ptrEncoderHandlers[i]->update();
  }
}

void Controls::setConfigurableParameter(MenuItem* item) {
  if (item == nullptr) {
    _configurableParameter = _parameterMock;
  } else if (item->isMenu()) {
    _configurableParameter = _parameterMock;
  } else {
   _configurableParameter = ((MenuLeaf*)item)->getParameter();
  }
}

// void Controls::updateDisplay() {
//   _displayHandler->displayMenu(_currentMenu);
// }

void Controls::selectNextChild() {
  if (_currentMenu->selectNextChild()) {
    setConfigurableParameter(_currentMenu->getCurrentChild());
    _displayHandler->redisplayMenuChildren();
  }
}

void Controls::selectPreviousChild() {
  if (_currentMenu->selectPreviousChild()) {
    setConfigurableParameter(_currentMenu->getCurrentChild());
    _displayHandler->redisplayMenuChildren();
  }
}

void Controls::increaseParameter() {
  _configurableParameter->increase();
  _displayHandler->redisplaySelectedChildValue();
}

void Controls::decreaseParameter() {
  _configurableParameter->decrease();
  _displayHandler->redisplaySelectedChildValue();
}

void Controls::enterCurrentChild() {
  if (_currentMenu->getCurrentChild() == nullptr) return;
  if (_currentMenu->getCurrentChild()->isMenu()) {
    _currentMenu = (MenuBranch*) _currentMenu->getCurrentChild();
    _displayHandler->displayMenu(_currentMenu);
    setConfigurableParameter(_currentMenu->getCurrentChild());
  }
}

void Controls::escapeToParent() {
  if (_currentMenu != _rootMenu) {
    _currentMenu = (MenuBranch*) _currentMenu->getParent();
    _displayHandler->displayMenu(_currentMenu);
    setConfigurableParameter(_currentMenu->getCurrentChild());
  }
}