#include <Arduino.h>
#include <wifi_connection.h>
#include <ArduinoJson.h>
#include <requester.h>
#include <lights.h>
#include <secrets.h>

DynamicJsonDocument doc(1024);
String body;

struct BrightnessControl {
  uint8_t current_value = 0; 
};

void setup() {
  // Start Serial communication
  Serial.begin(115200);
  setup_wifi_connection();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  doc["on"]["on"] = true;
  serializeJson(doc, body);
  sendPutRequest(BED_ROOM_GROUP, body);
  
  delay(1000);
  doc["dimming"]["brightness"] = 90.0;
  double x;
  double y;
  double z;
  
  calculateXYZ(255, 0, 0, x, y, z);
  doc["color"]["xy"]["x"] = x;
  doc["color"]["xy"]["y"] = y;
  serializeJson(doc, body);
  sendPutRequest(BED_ROOM_GROUP, body);
  delay(1000);

  calculateXYZ(0, 255, 0, x, y, z);
  doc["color"]["xy"]["x"] = x;
  doc["color"]["xy"]["y"] = y;
  serializeJson(doc, body);
  sendPutRequest(BED_ROOM_GROUP, body);
  delay(1000);

  calculateXYZ(0, 0, 255, x, y, z);
  doc["color"]["xy"]["x"] = x;
  doc["color"]["xy"]["y"] = y;
  serializeJson(doc, body);
  sendPutRequest(BED_ROOM_GROUP, body);
  delay(2000);

  doc["on"]["on"] = false;
  serializeJson(doc, body);
  sendPutRequest(BED_ROOM_GROUP, body);

}