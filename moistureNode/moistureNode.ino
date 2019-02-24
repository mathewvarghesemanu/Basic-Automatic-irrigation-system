#include <ESP8266WiFi.h>
#include <ThingerESP8266.h>

#define USERNAME "Mak3rspace"
#define DEVICE_ID "moisturesensor"
#define DEVICE_CREDENTIAL "Mak3rSpace"

#define SSID "Manu"
#define SSID_PASSWORD "ambalathil1234"
//D5 RELAY D6 LED A0 ANALOG 
ThingerESP8266 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);
int moistureValue=0,moisturePin=A0,motorPin=D5;
void setup() {
  Serial.begin(115200);
  
  pinMode(moisturePin, INPUT);
  pinMode(motorPin, OUTPUT);

  thing.add_wifi(SSID, SSID_PASSWORD);

  // digital pin control example (i.e. turning on/off a light, a relay, configuring a parameter, etc)
  thing["motor"] << digitalPin(motorPin);

  // resource output example (i.e. reading a sensor value)
   thing["millis"] >> outputValue(millis());

   thing["moistureValue"] >> outputValue(analogRead(moisturePin));

   //thing["threshold"] >> outputValue();
  // more details at http://docs.thinger.io/arduino/
}

void loop() {
  thing.handle();
  

}
