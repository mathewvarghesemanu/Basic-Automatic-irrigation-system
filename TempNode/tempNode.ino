#include <ESP8266WiFi.h>
#include <ThingerESP8266.h>
#include "DHTesp.h"

#define USERNAME "Mak3rspace"
#define DEVICE_ID "Dht11"
#define DEVICE_CREDENTIAL "Mak3rSpace"

#define SSID "Manu"
#define SSID_PASSWORD "ambalathil1234"

DHTesp dht;
ThingerESP8266 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);
float temperature = 0, humidity = 0;
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  Serial.println();
  Serial.println("Status\tHumidity (%)\tTemperature (C)\t(F)\tHeatIndex (C)\t(F)");
  String thisBoard = ARDUINO_BOARD;
  Serial.println(thisBoard);
  thing.add_wifi(SSID, SSID_PASSWORD);
  dht.setup(D5, DHTesp::DHT11);
  // digital pin control example (i.e. turning on/off a light, a relay, configuring a parameter, etc)
  thing["led"] << digitalPin(LED_BUILTIN);

  // resource output example (i.e. reading a sensor value)
  thing["millis"] >> outputValue(millis());

  thing["temperature"] >> [](pson& out){
      out = dht.getTemperature();
};
  thing["humidity"] >> [](pson& out){
      out = dht.getHumidity();
};
  // more details at http://docs.thinger.io/arduino/
}

void loop() {
  thing.handle();
  Serial.print(3);
}
