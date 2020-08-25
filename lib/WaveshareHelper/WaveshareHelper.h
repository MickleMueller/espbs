
#ifndef WaveshareHelper_h
#define WaveshareHelper_h
#define ENABLE_GxEPD2_display 1

#include "ArduinoJson.h"
#include "AsyncJson.h"
#include "GxEPD2_BW.h"
// #include "I2Cdev.h"
#include "HTTPClient.h"
#include "SPI.h"
#include "U8g2_for_Adafruit_GFX.h"
#include "WebServerHelper.h"
#include "WiFi.h"
#include "Wire.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 480

enum alignment { LEFT,
                 RIGHT,
                 CENTER };

class WaveshareHelperClass {
 private:
  Preferences preferences;
  HTTPClient http;
  String host;

  void read();
  void write();

  void readValues();
  void sendValues();

  unsigned long setupDuration;

  void initDisplay();

  void drawStatus(String title, String url, int offsetX, int offsetY);
  void drawUsage(String url, int offsetX, int offsetY);
  void drawString(int x, int y, String text, alignment align);

 public:
  void setup();
  void server();
  void loop();
  void sleep();
};

extern WaveshareHelperClass WaveshareHelper;

#endif