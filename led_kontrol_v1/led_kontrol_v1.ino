#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager for connect wifi
#include <ESP8266WebServer.h> // for HTTPUpdate
#include <ESP8266mDNS.h>// for HTTPUpdate
#include <ESP8266HTTPUpdateServer.h>// for HTTPUpdate

// for HTTPUpdate
const char* host = "esp8266-webupdate";// for HTTPUpdate name
ESP8266WebServer httpServer(8080);// for HTTPUpdate port
ESP8266HTTPUpdateServer httpUpdater;// for HTTPUpdate begin


void setup() {
  
    //serial begin for information
    Serial.begin(115200);
    
    //for wifi connect
    WiFiManager wifiManager;
    wifiManager.autoConnect("Cyber_JET", "12345678");
    
    // for HTTPUpdate port 8080
    MDNS.begin(host);
    httpUpdater.setup(&httpServer);
    httpServer.begin();
    MDNS.addService("http", "tcp", 8080);
    Serial.println("HTTPUpdateServer ready!"); 
	  Serial.print("Open http://");
	  Serial.print(WiFi.localIP());
	  Serial.println(":8080/update in your browser\n");
}

void loop() {
  
      // for HTTPUpdate
      httpServer.handleClient();
      MDNS.update();
}
