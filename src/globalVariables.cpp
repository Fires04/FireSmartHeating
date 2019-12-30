#include "../include/headerFiles.h"

//ESP LED
//JLed espLed = JLed(espLedPin).On();

//http server
ESP8266WebServer httpServer(80);

//wifi connection
WiFiClient wifiClient;

//mqtt connection
PubSubClient mqttClient(wifiClient);