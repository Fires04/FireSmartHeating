/**
 * Fire Smart Floor Heating - FSFA
 * @version v0.0
 * @board Wemos D1 mini
 * @author David Stein <info@davidstein.cz> 
 */
#include "../include/headerFiles.h"

void setup() {
  //enable serial debug
  Serial.begin(230400);

  //connect to wifi - callback function call
  connectWiFi();

  //setup web server
  setupWebServer();

  //connect to MQTT broker
  connectMQTT();


}

void loop() {
  //web server handle
  httpServer.handleClient();

  //mqtt client
  mqttClient.loop();

  //give some time to ESP chip
  yield();
}