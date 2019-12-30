#ifndef CONFIGURATION_H
#define CONFIGURATION_H

//wifi setup
#define WIFI_SSID "steinovi_iot"  // your network SSID (name)
#define WIFI_PASS "stein@iot"  // your network key

//thing things
#define ThingType "FireSmartFloorHeater_"
#define RoomID "FireWorkshop"

#define MQTTClientID ThingType RoomID

//MQTT setup
#define mqttServer "192.168.50.7"
#define mqttPort 1883
#define mqttUser ""
#define mqttPass ""
#define mqttPublish "/power/heating/" RoomID "/status"
#define mqttSubscribe  "/power/heating/" RoomID "/cmd"

//leds
#define espLedPin 2

#define HOST_NAME "FireESP"

#define HTTP_PORT 80

#if defined ESP8266 || defined ESP32 //check board
  #define USE_MDNS true
  #define USE_ARDUINO_OTA true
  #define WEB_SERVER_ENABLED true
  //#define DEBUG_DISABLED true
#else
  #error "The board must be ESP8266 or ESP32"
#endif 

#endif