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
  AbstractParameter* _configurableParameter;
  StatelessParameter* _navigationParameter = new StatelessParameter(
    std::bind(&Controls::selectNextChild, this),
    std::bind(&Controls::selectPreviousChild, this)
  );
  StatelessParameter* _configurationParameter = new StatelessParameter(
    std::bind(&Controls::increaseParameter, this),
    std::bind(&Controls::decreaseParameter, this)
  );

  EncoderHandler* _configurationEncoderHandler;
  EncoderHandler* _navigationEncoderHandler;

  void setConfigurableParameter(MenuItem* item);
  // void updateDisplay();

public:
  Controls(int numberOfMusicNodes, int numberOfEncoders, MenuBranch* rootMenu, AbstractDisplayHandler* displayHandler);
  SensorHandler* getMusicSensorHandler(int index);
  EncoderHandler* getEncoderHandler(int index);
  void addMusicSensor(int pin);
  void addNavigationEncoder(int pinA, int pinB, int pinS);
  void addConfigurationEncoder(int pinA, int pinB, int pinS);
  EncoderHandler* addCommonEncoder(int pinA, int pinB, int pinS);
  void update();

  void enterCurrentChild();
  void escapeToParent();
  void selectNextChild();
  void selectPreviousChild();
  void increaseParameter();
  void decreaseParameter();
};

#endif //Controls_h_