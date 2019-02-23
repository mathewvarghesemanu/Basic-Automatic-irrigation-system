#include <ESP8266WiFi.h>
#include <ThingerESP8266.h>

#define USERNAME "Mak3rspace"
#define DEVICE_ID "moisturesensor"
#define DEVICE_CREDENTIAL "Mak3rSpace"

#define SSID "mathew"
#define SSID_PASSWORD "lunargrey"

ThingerESP8266 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

  thing.add_wifi(SSID, SSID_PASSWORD);

  // digital pin control example (i.e. turning on/off a light, a relay, configuring a parameter, etc)
  thing["led"] << digitalPin(LED_BUILTIN);

  // resource output example (i.e. reading a sensor value)
  thing["millis"] >> outputValue(millis());

  // more details at http://docs.thinger.io/arduino/
}

void loop() {
  thing.handle();
}
