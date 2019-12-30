#include "../include/headerFiles.h"

/*
 * Callback function to connect to wifi
 */
void connectWiFi(){
    // Connect WiFi
    //espLed.Breathe(3500).Forever();

    Serial.println("*** connectWiFi: begin conection ...");
    // Connect with SSID and password stored
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    // Wait connection
    uint32_t timeout = millis() + 20000; // Time out
    while (WiFi.status() != WL_CONNECTED && millis() < timeout)
    {
        delay(250);
        Serial.print(".");
        if(millis() > (timeout - 2000)){
            Serial.println("Unable to connect to wifi - restart ");
            ESP.restart();
        }
    }
    // End
    //successfull wifi connection
    Serial.println("");
    Serial.print("connectWiFi: connect a ");
    Serial.println(WiFi.SSID());
    Serial.print("IP: ");
    Serial.println(WiFi.localIP().toString());
    //espLed.On();
}

void setupWebServer(){
    Serial.println("Setup http server");
    httpServer.on("/",handleRoot);
    httpServer.begin();
    Serial.println("http enables");
}

/* 
 * Handle root web server
 */
 void handleRoot(){
     String rootMessage = "";
     rootMessage += "Room ID: ";
     rootMessage += RoomID;
     rootMessage += "\nSSID: ";
     rootMessage += WiFi.SSID();
     rootMessage += "\nIP: ";
     rootMessage += WiFi.localIP().toString();
     rootMessage += "\n";
     httpServer.send(200, "text/plain", rootMessage);
     Serial.println("Webserver 200 root");
 }


void connectMQTT(){
    Serial.println("Setup mqtt connection");
    mqttClient.setServer(mqttServer,mqttPort);
    mqttClient.setCallback(mqttHandle);

    while(!mqttClient.connected()){
        Serial.println("Connecting to mqtt");
        if(mqttClient.connect(MQTTClientID,mqttUser,mqttPass)){
            Serial.print("Connected to MQTT as client: ");
            Serial.println(MQTTClientID);
        }else{
            Serial.print("MQTT failed with state ");
            Serial.print(mqttClient.state()+"\n");
            delay(2000);
        }
    }
    Serial.println("MQTT - Hello world");
    mqttClient.publish(mqttPublish, "Connected :) !");
    mqttClient.subscribe(mqttSubscribe);
}


 void mqttHandle(char* topic, byte* payload, unsigned int length){
    Serial.print("Message arrived in topic: ");
    Serial.println(topic);
 
    Serial.print("Message:");
    for (unsigned int i = 0; i < length; i++) {
        Serial.print((char)payload[i]);
    }
 
    Serial.println();
    Serial.println("-----------------------");
 }


