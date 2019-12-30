/**
 * Includes file include all required libraries
 */ 
#ifndef INCLUDES_H
#define INCLUDES_H

//wifi library
#include <ESP8266WiFi.h>

//led library
#include <jled.h>


#ifdef USE_MDNS
  #include <DNSServer.h>
  #include <ESP8266mDNS.h>
#endif


//web server
#ifdef WEB_SERVER_ENABLED
    #include <ESP8266WebServer.h>
#endif

// Arduino OTA
#ifdef USE_ARDUINO_OTA
  #include <ArduinoOTA.h>
#endif

//mqtt
#include <PubSubClient.h>




#endif //INCLUDES_H 