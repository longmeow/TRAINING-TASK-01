#include <ESP8266WiFi.h>
#include <DallasTemperature.h>
#include <OneWire.h>
#include "utils.h"

const char* ssid = "longmeow";
const char* pass = "longmeow";
const int TEMP_PIN = 4;
const int LIGHT_PIN = 14;
const char* CIP = "$$$$$"; //Dien vo

OneWire oneWire(TEMP_PIN);
DallasTemperature sensors(&oneWire);

void setup () {
  Serial.begin(115200);
  start(ssid,pass);
  pinMode(LIGHT_PIN, INPUT);
}

void loop() {
  sensors.requestTemperatures();
  Serial.print("Temp: ");
  Serial.println(sensors.getTempCByIndex(0));
  Serial.print("Light: ");
  Serial.println(digitalRead(LIGHT_PIN));

  waitNewReq(CIP);
  returnData(sensors.getTempCByIndex(0),digitalRead(LIGHT_PIN));
}
