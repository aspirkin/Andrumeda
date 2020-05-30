#include <Controls.h>

Controls::Controls(int numberOfMusicNodes, int numberOfEncoders, MenuBranch* rootMenu, AbstractDisplayHandler* displayHandler) {
  _numberOfMusicNodes = numberOfMusicNodes;
  _numberOfEncoders = numberOfEncoders;

  _rootMenu = rootMenu;
  _currentMenu = _rootMenu;

  _displayHandler = displayHandler;
  _displayHandler->displayMenu(_currentMenu);
}

void Controls::addEncoder(int pinS, int pinA, int pinB, EncoderType encoderType){
  EncoderHandler* newEncoderHandler = new EncoderHandler(pinS, pinA, pinB);
  _ptrEncoderHandlers.push_back(newEncoderHandler);

  if (encoderType == EncoderType::PARAMETER_CHANGE) {
    _parameterEncoderHandler = newEncoderHandler;
    _parameterEncoderHandler->setClickFunction(std::bind(&Controls::enterCurrentChild, this));
  } else if (encoderType == EncoderType::MENU_NAVIGATION) {
    _navigationEncoderHandler = newEncoderHandler;
    _navigationEncoderHandler->setClickFunction(std::bind(&Controls::escapeToParent, this));

    StatelessParameter* paramMenuChildrenNavigation =
      new StatelessParameter(
        std::bind(&Controls::selectNextChild, this),
        std::bind(&Controls::selectPreviousChild, this)
      );
    _navigationEncoderHandler->setParameter(paramMenuChildrenNavigation);
  }
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

void Controls::setEncoderParameter(MenuItem* item) {
  if (item == nullptr) {
    _parameterEncoderHandler->setParameter(_parameterMock);
  } else if (item->isMenu()) {
    _parameterEncoderHandler->setParameter(_parameterMock);
  } else {
    _parameterEncoderHandler->setParameter(((MenuLeaf*)item)->getParameter());
  }
}

void Controls::updateDisplay() {
  _displayHandler->displayMenu(_currentMenu);
  setEncoderParameter(_currentMenu->getCurrentChild());
}

void Controls::selectNextChild() {
  if (_currentMenu->selectNextChild()) updateDisplay();
}

void Controls::selectPreviousChild() {
  if (_currentMenu->selectPreviousChild()) updateDisplay();
}

void Controls::enterCurrentChild() {
  if (_currentMenu->getCurrentChild() == nullptr) return;
  if (_currentMenu->getCurrentChild()->isMenu()) {
    _currentMenu = (MenuBranch*) _currentMenu->getCurrentChild();
    updateDisplay();
  }
}

void Controls::escapeToParent() {
  if (_currentMenu != _rootMenu) {
    _currentMenu = (MenuBranch*) _currentMenu->getParent();
    updateDisplay();
  }
}