#ifndef Controls_h_
#define Controls_h_

#include <EncoderHandler.h>
#include <SensorHandler.h>
#include <vector>
#include <menus/MenuBranch.h>
#include <menus/MenuLeaf.h>
#include <parameters/AbstractParameter.h>
#include <parameters/StatefulParameter.h>
#include <parameters/StatelessParameter.h>
#include <EncoderHandler.h>
#include <displays/ST7735_DisplayHandler.h>

class Controls
{
protected:
  int _numberOfMusicNodes;
  int _numberOfEncoders;
  std::vector <SensorHandler*> _ptrMusicSensorHandlers;
  std::vector <EncoderHandler*> _ptrEncoderHandlers;

  MenuBranch* _rootMenu;
  MenuBranch* _currentMenu;
  AbstractDisplayHandler* _displayHandler;
  AbstractParameter* _parameterMock = new AbstractParameter();
  EncoderHandler* _parameterEncoderHandler;
  EncoderHandler* _navigationEncoderHandler;
  void setEncoderParameter(MenuItem* item);
  void updateDisplay();

public:
  enum class EncoderType {
    MENU_NAVIGATION,
    PARAMETER_CHANGE,
    HOT_FUNCTION
  };
  Controls(int numberOfMusicNodes, int numberOfEncoders, MenuBranch* rootMenu, AbstractDisplayHandler* displayHandler);
  SensorHandler* getMusicSensorHandler(int index);
  EncoderHandler* getEncoderHandler(int index);
  void addMusicSensor(int pin);
  void addEncoder(int pinA, int pinB, int pinS, EncoderType encoderType);
  void update();

  void enterCurrentChild();
  void escapeToParent();
  void selectNextChild();
  void selectPreviousChild();
};

#endif //Controls_h_