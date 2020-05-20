#include <MenuHandler.h>
#include <DisplayObject.h>

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

MenuHandler::MenuHandler(Menu* rootMenu) {
  _rootMenu = rootMenu;
  _currentMenu = _rootMenu;
  display.initR(INITR_144GREENTAB);
  redraw();
}

void MenuHandler::redraw() {
  display.fillScreen(BLACK);
  drawMenuPath();
}

void MenuHandler::drawMenuPath() {
  String result = "";
  result = *_currentMenu->getName() + result;
  //  TODO: Make cyclic
  display.setCursor(1, 1);
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.print(result);
}
