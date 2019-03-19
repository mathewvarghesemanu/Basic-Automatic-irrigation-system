#include <ESP8266WiFi.h>
#include <ThingerESP8266.h>

#define USERNAME "Mak3rspace"
#define DEVICE_ID "moisturesensor"
#define DEVICE_CREDENTIAL "Mak3rSpace"

#define SSID "coconuts"
#define SSID_PASSWORD "coconuts"
//D5 RELAY D6 LED A0 ANALOG
ThingerESP8266 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

int moisturePin = A0, motorPin = D5, ledPin = D6;
int moistureValue = 0, threshold = 100;

void setup() {
  Serial.begin(115200);

  pinMode(moisturePin, INPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(motorPin, LOW);
digitalWrite(ledPin, LOW);
  thing.add_wifi(SSID, SSID_PASSWORD);

  // digital pin control example (i.e. turning on/off a light, a relay, configuring a parameter, etc)
  thing["motorcontrol"] >> outputValue(digitalRead(motorPin));

  thing["ledcontrol"] << digitalPin(ledPin);
  // resource output example (i.e. reading a sensor value)
  thing["millis"] >> outputValue(millis());

  thing["moistureValue"] >> outputValue(moistureValue=analogRead(moisturePin));

  thing["threshold"] << inputValue(threshold);
 /* thing["resource"] = []() {
    if (analogRead(moisturePin) < threshold)
    {
      digitalWrite(ledPin, LOW);
      Serial.println("hey");}
    else
      digitalWrite(ledPin, HIGH);
  };
*/

  // more details at http://docs.thinger.io/arduino/
}

void loop() {
  thing.handle();
  Serial.println(threshold);
if (moistureValue < threshold)
    {
      digitalWrite(motorPin, HIGH);
      Serial.println("hey");}
    else
      digitalWrite(motorPin, LOW); 
}
